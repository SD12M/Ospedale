#include "View/headers/mainview.h"
MainView::MainView(QMainWindow *parent) :
    QMainWindow(parent),modifica_model(nullptr), visitor(nullptr),
    inserisci_view(nullptr), index_saved(-1), loaded_data(0)
{
    filedialog_load = new QFileDialog(this);
    filedialog_store = new QFileDialog(this);

    show_message = new Messaggio(this);

    central = new QWidget;
    setCentralWidget(central);

    topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    bottomFiller = new QWidget;
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    model = new TableModel(this);

    table_view = new QTableView();
    table_view->setModel(model);
    table_view->setSelectionBehavior(QAbstractItemView::SelectRows);
    table_view->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    table_view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table_view->resizeColumnsToContents();
    table_view->setMinimumHeight(300);
    table_view->setVisible(false);

    inserimento = new QAction(tr("Inserisci dato"),this);
    inserimento->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_A));
    inserimento->setIcon(QIcon(":/resources/images/add.png"));

    load = new QAction(tr("Carica dati"),this);
    load->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_L));
    load->setIcon(QIcon(":/resources/images/load.png"));

    store = new QAction(tr("Salva dati"),this);
    store->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));
    store->setIcon(QIcon(":/resources/images/save.png"));

    help = new QAction(tr("Help"),this);
    help->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_H));
    help->setIcon(QIcon(":/resources/images/help.png"));

    cancella = new QAction(tr("Cancella dato"),this);
    cancella->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_D));
    cancella->setIcon(QIcon(":/resources/images/delete.png"));

    informazioni = new QAction(tr("Informazioni"),this);
    informazioni->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_I));
    informazioni->setIcon(QIcon(":/resources/images/info.png"));

    menu_azioni = menuBar()->addMenu("File");
    menu_azioni->addAction(load);
    menu_azioni->addAction(store);

    menu_informazioni = menuBar()->addMenu("Informazioni aggiuntive");
    menu_informazioni->addAction(informazioni);

    menu_file = menuBar()->addMenu("Inserimento dato");
    menu_file->addAction(inserimento);

    menu_delete = menuBar()->addMenu("Cancella");
    menu_delete->addAction(cancella);

    menu_help = menuBar()->addMenu("Help");
    menu_help->addAction(help);

    db_status_img = new QPixmap();
    db_status_img->load(":/resources/images/red.png");

    label_row = new QLabel(this);
    label_row->setText("Riga selezionata : ");
    label_row->setVisible(false);

    numero_dipendenti = new QLabel(this);
    numero_dipendenti->setVisible(false);

    db_status_text = new QLabel(this);
    db_status_text->setText("Database caricato : ");

    db_status = new QLabel();
    db_status->setPixmap(db_status_img->scaled(10,10,Qt::KeepAspectRatio));

    bar = new QStatusBar();
    bar->addWidget(db_status_text);
    bar->addWidget(db_status);
    bar->addWidget(numero_dipendenti);
    bar->addPermanentWidget(label_row);

    V_layout = new QVBoxLayout();
    V_layout->addWidget(topFiller);
    V_layout->addWidget(table_view);
    V_layout->addSpacing(1);
    V_layout->addWidget(bottomFiller);
    central->setLayout(V_layout);

    this->setStatusBar(bar);
    this->setMinimumSize(800,400);
    this->setMaximumSize(900,500);
    this->setWindowTitle("GeHospital");
    this->move(screen()->geometry().center() - frameGeometry().center());

    connect(inserimento,&QAction::triggered,this,&MainView::create_choice_view);

    connect(load, &QAction::triggered, filedialog_load,&QFileDialog::exec);
    connect(filedialog_load,&QFileDialog::fileSelected,model,&TableModel::load_from_file);

    connect(informazioni, &QAction::triggered, this,&MainView::info_clicked);
    connect(cancella,&QAction::triggered, this, &MainView::delete_selected_row);
    connect(help, &QAction::triggered, this,&MainView::aiuto);
    connect(table_view,&QTableView::clicked,this,&MainView::onTableClicked);
    connect(this,&MainView::ask_object_info, model, &TableModel::select_info);
    connect(this,&MainView::delete_at, model, &TableModel::delete_obj_at_row);
    connect(model,&TableModel::data_loaded, this,&MainView::enable_table);
    connect(model,&TableModel::delete_success,this,&MainView::reset_index);
    connect(model,&TableModel::draw_info,this,&MainView::show_specific_info);
    connect(model,&TableModel::zero_data,this,&MainView::enable_disable_insert);
}
void MainView::enable_disable_insert()
{
    loaded_data = !loaded_data;
    table_view->setVisible(false);
    numero_dipendenti->setVisible(false);
    db_status_img->load("resources/images/red.png");
    db_status->setPixmap(db_status_img->scaled(10,10,Qt::KeepAspectRatio));
    label_row->setVisible(false);
    disconnect(store,&QAction::triggered,filedialog_store,&QFileDialog::exec);
}
/*
 * Metodo reset_index : effettua il reset dell'indice selezionato.
 * Se index_saved ha il valore -1 (o qualsiasi valore < 0) allora la funzione di delete da parte del model non avrà alcun effetto.
*/
void MainView::reset_index()
{
    index_saved = -1;
    numero_dipendenti->setText("Numero totale dipendenti : " + QString::number(model->get_dipendenti()));
}
/*
 * Metodo create_choice_view : mostra la view di scelta inserimento nuovo dato tra : Medico, Infermire e Tecnico.
*/
void MainView::create_choice_view()
{
    if(loaded_data)
    {
        inserisci_view = new Insert();
        inserisci_view->setWindowModality(Qt::ApplicationModal);
        inserisci_view->setAttribute(Qt::WA_DeleteOnClose);
        inserisci_view->show();
        connect(inserisci_view,&Insert::scelta_inserimento,this,&MainView::create_insert_view);
    }
    else
    {
        show_message->messaggio("Errore dati","Caricare prima il database.");
    }
}
/*
 * Metodo create_insert_view : in base al tipo di dato scelto da inserire, viene mostrata la corrispondente view.
*/
void MainView::create_insert_view(const Tipo& valore)
{
    if(valore == Tipo::Medico)
    {
        VInsertMedico* view = new VInsertMedico();
        view->setAttribute(Qt::WA_DeleteOnClose);
        view->setWindowModality(Qt::ApplicationModal);
        view->show();
        connect(view,&VInsertMedico::send_data,model,&TableModel::inserisci);
        connect(model,&TableModel::insert_success,view,&VInsertMedico::close);
    }
    else if(valore == Tipo::Infermiere)
    {
        VInsertInfermiere* view = new VInsertInfermiere();
        view->setAttribute(Qt::WA_DeleteOnClose);
        view->setWindowModality(Qt::ApplicationModal);
        view->show();
        connect(view,&VInsertInfermiere::send_data,model,&TableModel::inserisci);
        connect(model,&TableModel::insert_success,view,&VInsertInfermiere::close);
    }
    else if(valore == Tipo::Tecnico)
    {
        VInsertTecnico* view = new VInsertTecnico();
        view->setAttribute(Qt::WA_DeleteOnClose);
        view->setWindowModality(Qt::ApplicationModal);
        view->show();
        connect(view,&VInsertTecnico::send_data,model,&TableModel::inserisci);
        connect(model,&TableModel::insert_success,view,&VInsertTecnico::close);
    }
    else
    {

    }
}
void MainView::closeEvent(QCloseEvent *event)
{
    if(model->get_model_state())
    {
        QMessageBox::StandardButton scelta = QMessageBox::question(this,"Modifiche non salvate","Procedere senza salvare le modifiche?", QMessageBox::Yes | QMessageBox::No,QMessageBox::No);
        if(scelta == QMessageBox::Yes)
        {
            event->accept();
        }
        else
        {
            event->ignore();
        }
    }
    else
    {
        event->accept();
    }
}
void MainView::enable_table()
{
    loaded_data = true;
    table_view->setVisible(true);
    db_status_img->load("resources/images/green.png");
    db_status->setPixmap(db_status_img->scaled(10,10,Qt::KeepAspectRatio));
    numero_dipendenti->setText("Numero totale dipendenti : " + QString::number(model->get_dipendenti()));
    numero_dipendenti->setVisible(true);
    connect(store, &QAction::triggered, filedialog_store,&QFileDialog::exec);
    connect(filedialog_store,&QFileDialog::fileSelected,model,&TableModel::salva_to_file);
}
void MainView::aiuto()
{
    const QString help_text("Benventuo in GeHospital. \n\n\n"
                  ""
                  "Tutte le azioni possono essere svolte tramite il menu in alto, oppure tramite shortcuts.\n\n"
                  ""
                  "Azioni generali per l'utilizzo dell'applicazione : \n\n"
                  ""
                  ""
                  "1. Caricare i dati : File -> Carica dati oppure CTRL + L\n\n"
                  "2. Salvare i dati  : File -> Salva dati oppure CTRL + S\n\n"
                  "3. Informazioni aggiuntive : Informazioni aggiuntive -> Informazioni oppure CTRL + I \n\n"
                  "4. Inserimento dato: Inserimento -> Inserisci oppure CTRL + A\n\n"
                  "5. Cancella dato : Cancella -> Cancella dato oppure CTRL + D\n\n"
                  "6. Menu informativo : Help oppure CTRL + H\n\n"
                  ""
                  ""
                  "Nota: In una shortcut, il simbolo + non deve essere incluso nella combinazione di tasti."
                  "");
    show_message->messaggio("Help",QString(help_text));
}
void MainView::delete_selected_row()
{
    emit delete_at(index_saved);
}
void MainView::info_clicked()
{
    emit ask_object_info(index_saved);
}
void MainView::show_specific_info(Persona* const p)
{
    visitor = new DrawView();
    visitor->setWindowModality(Qt::ApplicationModal);
    p->draw_specific_info(visitor);
    connect(visitor,&DrawView::state_changed,model,&TableModel::modifica_state_changed);
}
void MainView::onTableClicked(const QModelIndex &index)
{
    if (index.isValid()) {
        index_saved = index.row();
        label_row->setText("Riga selezionata : " + QString::number(index_saved));
        label_row->setVisible(true);
    }
}
