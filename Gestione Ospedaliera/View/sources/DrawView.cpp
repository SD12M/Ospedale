#include "View/headers/DrawView.h"
DrawView::DrawView(QWidget  *p)
    : QWidget (p), serie(nullptr),bar_set(nullptr), bar_set_confronto(nullptr), bar_serie(nullptr), lista_names(0)
{
    chart = new QChart();
    chart_view = new QChartView();
    box_info = new QGroupBox("Modifica sulle celle abilitate");
    grid_layout = new QGridLayout();

    table = new QTableView(this);
    table->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    table->resizeColumnsToContents();
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    v_layout = new QVBoxLayout();
    v_layout->addWidget(table);
    box_info->setLayout(v_layout);

    v_layout_graph = new QVBoxLayout();
    v_layout_graph->addWidget(chart_view);
    v_layout_graph->addStretch(1);

    grid_layout->addWidget(box_info,0,0);
    grid_layout->addLayout(v_layout_graph,1,0);

    this->setLayout(grid_layout);
    this->setMinimumSize(1000,500);
    this->setMaximumSize(1100,550);
    this->move(screen()->geometry().center() - frameGeometry().center());
}
void DrawView::drawMedico(Medico* const medico)
{
    ModificaMedico* model_medico = new ModificaMedico(medico,this);
    table->setModel(model_medico);
    connect(model_medico,&ModificaMedico::state_changed,this,&DrawView::send_change);

    this->setWindowTitle("Modifica informazioni:  medico");
    serie = new QPieSeries(this);

    serie->append("pazienti morti", medico->get_morti());
    serie->append("pazienti salvati", medico->get_salvati());

    chart->addSeries(serie);
    chart->setTitle("Efficienza Medico");

    chart_view->setChart(chart);
    chart_view->setRenderHint(QPainter::Antialiasing);
    this->show();
}
void DrawView::drawInfermiere(Infermiere* const infermiere)
{
    ModificaInfermiere* model_infermiere = new ModificaInfermiere(infermiere,this);
    table->setModel(model_infermiere);
    connect(model_infermiere,&ModificaInfermiere::state_changed,this,&DrawView::send_change);

    this->setWindowTitle("Modifica informazioni:  infermiere");
    QString v2 = "Rendimento Infermiere : " + QString::fromStdString(infermiere->get_nome());
    QString v1 = "Mese : " + QString::fromStdString(infermiere->get_mese());

    bar_set = new QBarSet(v2);
    bar_set->append(infermiere->get_interventi());

    bar_set_confronto = new QBarSet("Rendimento atteso : 50");
    bar_set_confronto->append(50);

    bar_serie = new QBarSeries(this);

    bar_serie->append(bar_set);
    bar_serie->append(bar_set_confronto);

    chart->addSeries(bar_serie);
    chart->setTitle("Confronto tra rendimento reale e rendimento atteso");

    QStringList identificatori;
    identificatori << v1;

    axisX = new QBarCategoryAxis();
    axisX->append(identificatori);
    chart->addAxis(axisX,Qt::AlignBottom);
    bar_serie->attachAxis(axisX);

    axisY = new QValueAxis();
    axisY->setRange(0,100);
    chart->addAxis(axisY, Qt::AlignLeft);
    bar_serie->attachAxis(axisY);

    chart_view->setChart(chart);
    chart_view->setRenderHint(QPainter::Antialiasing);

    this->show();
}
void DrawView::drawTecnico(Tecnico* const  tecnico)
{
    ModificaTecnico* model_tecnico = new ModificaTecnico(tecnico,this);
    table->setModel(model_tecnico);

    connect(model_tecnico,&ModificaTecnico::state_changed,this,&DrawView::send_change);

    this->setWindowTitle("Modifica informazioni:  tecnico");

    candle_series = new QCandlestickSeries(this);
    candle_series->setName("Confronto nel mese di " + QString::fromStdString(tecnico->get_mese()));
    candle_series->setIncreasingColor(QColor(Qt::green));
    candle_series->setDecreasingColor(QColor(Qt::red));

    // valori rendimento attuale tecnico.
    candle_set_1 = new QCandlestickSet(0,this);
    candle_set_1->setOpen(0.0);
    candle_set_1->setHigh(100.0);
    candle_set_1->setLow(0.0);
    candle_set_1->setClose(tecnico->get_interventi());

    // valori rendimento atteso
    candle_set_2 = new QCandlestickSet(0,this);
    candle_set_2->setOpen(0.0);
    candle_set_2->setHigh(100.0);
    candle_set_2->setLow(0.0);
    candle_set_2->setClose(60.0);

    double diff =  static_cast<double>(tecnico->get_interventi()) - 60;

    candle_set_3 = new QCandlestickSet(0,this);
    candle_set_3->setOpen(0.0);
    candle_set_3->setHigh(100.0);
    candle_set_3->setLow(-60);
    candle_set_3->setClose(diff);

    candle_series->append(candle_set_1);
    candle_series->append(candle_set_2);
    candle_series->append(candle_set_3);

    chart->addSeries(candle_series);
    chart->setTitle("Visualizzazione rendimento tecnico : " + QString::fromStdString(tecnico->get_nome()));
    chart->createDefaultAxes();
    chart->legend()->setAlignment(Qt::AlignBottom);

    axisY = qobject_cast<QValueAxis *>(chart->axes(Qt::Vertical).at(0));
    axisY->setMax(100);
    axisY->setMin(-50);

    lista_names = new QStringList();
    lista_names->append("Rendimento Tecnico: " + QString::number(tecnico->get_interventi()));
    lista_names->append("Rendimento Atteso: 60");

    if(diff >= 0.0)
    {
        lista_names->append("Differenza positiva:" + QString::number(diff));
    }
    else
    {
        lista_names->append("Differenza negativa:" + QString::number(diff));
    }

    axisX = qobject_cast<QBarCategoryAxis *>(chart->axes(Qt::Horizontal).at(0));
    axisX->setCategories(*lista_names);

    chart_view->setChart(chart);
    chart_view->setRenderHint(QPainter::Antialiasing);

    this->show();
}
void DrawView::send_change()
{
    emit state_changed();
}
DrawView::~DrawView()
{
    delete lista_names;
}



