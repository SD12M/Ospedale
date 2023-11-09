#ifndef DRAWVIEW_H
#define DRAWVIEW_H
#include "Classes/headers/ConstVisitor.h"
#include "Model/headers/modifica_medico.h"
#include "Model/headers/modifica_tecnico.h"
#include "Model/headers/modifica_infermiere.h"
#include <QWidget>
#include <QTableView>
#include <QString>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QGroupBox>
#include <QLabel>
#include <QHeaderView>
#include <QChart>
#include <QChartView>
#include <QPieSeries>
#include <QBarSet>
#include <QBarSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QScreen>
#include <QCandlestickSeries>
#include <QCandlestickSet>
#include <QStringList>

class DrawView : public QWidget, public Visitor
{
    Q_OBJECT
private:
    QVBoxLayout* v_layout;
    QVBoxLayout* v_layout_graph;

    QTableView* table;
    QPieSeries* serie;
    QChart* chart;
    QChartView* chart_view;

    QBarSet* bar_set;
    QBarSet* bar_set_confronto;

    QBarSeries* bar_serie;
    QBarCategoryAxis* axisX;
    QValueAxis* axisY;

    QGroupBox* box_info;
    QGridLayout* grid_layout;

    QCandlestickSeries* candle_series;

    QCandlestickSet* candle_set_1;
    QCandlestickSet* candle_set_2;
    QCandlestickSet* candle_set_3;

    QStringList* lista_names;

    void barchart_set(const QString&);
public:
    explicit DrawView(QWidget*p = nullptr);
    virtual void drawMedico(Medico* const) override final;
    virtual void drawInfermiere(Infermiere* const) override final;
    virtual void drawTecnico(Tecnico* const) override final;
    ~DrawView();
private slots:
    void send_change();
signals:
    void state_changed();
};
#endif // DRAWVIEW_H
