#include "View/headers/insert.h"
Insert::Insert(QWidget *parent) : QWidget(parent)
{
    annulla = new QPushButton("Annulla",this);
    seleziona = new QPushButton("Seleziona",this);
    seleziona->setIcon(QIcon("resources/images/select.png"));

    scelta_dottore = new QRadioButton("Dottore",this);
    scelta_infermiere = new QRadioButton("Infermiere",this);
    scelta_tecnico = new QRadioButton("Tecnico",this);

    v_layout = new QVBoxLayout();
    v_layout->addWidget(scelta_dottore);
    v_layout->addWidget(scelta_infermiere);
    v_layout->addWidget(scelta_tecnico);

    scelte = new QGroupBox("Selezionare il tipo di dato : ");
    scelte->setLayout(v_layout);

    v_layout2 = new QVBoxLayout();
    v_layout2->addWidget(seleziona);
    v_layout2->addWidget(annulla);

    grid_layout = new QGridLayout();
    grid_layout->addWidget(scelte,0,0);
    grid_layout->addLayout(v_layout2,0,1);

    setFixedSize(350,150);
    setLayout(grid_layout);
    setWindowTitle("Inserimento dati");

    seleziona_dato = new QAction(this);
    seleziona_dato->setShortcut(QKeySequence(Qt::Key_Return));

    annulla_inserimento = new QAction(this);
    annulla_inserimento->setShortcut(QKeySequence(Qt::Key_Escape));

    this->addAction(seleziona_dato);
    this->addAction(annulla_inserimento);
    this->move(screen()->geometry().center() - frameGeometry().center());

    // selezione tramite action.
    connect(seleziona_dato, &QAction::triggered, this,&Insert::invia_scelta);
    // selezione tramite pulsante.
    connect(seleziona,&QPushButton::clicked,this,&Insert::invia_scelta);
    // chiusura tramite pulsante.
    connect(annulla,&QPushButton::clicked,this,&Insert::close);
    // chiusura tramite action.
    connect(annulla_inserimento, &QAction::triggered, this,&Insert::close);
}
void Insert::invia_scelta()
{
    if(scelta_dottore->isChecked())
    {
        this->close();
        emit scelta_inserimento(Tipo::Medico);
    }
    else if(scelta_infermiere->isChecked())
    {
        this->close();
        emit scelta_inserimento(Tipo::Infermiere);
    }
    else if(scelta_tecnico->isChecked())
    {
        this->close();
        emit scelta_inserimento(Tipo::Tecnico);
    }
    else
    {

    }
}
