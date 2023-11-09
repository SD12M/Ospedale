#include "View/headers/view_insert_tecnico.h"
VInsertTecnico::VInsertTecnico(QWidget* parent) : QWidget(parent)
{
    insert_common = new ViewInsert(this);
    insert_common->mansione->setText("tecnico");

    label_interventi = new QLabel("Interventi :",this);
    label_interventi->setAlignment(Qt::AlignRight);

    QRegularExpression rx("^[0-9]*$");
    validator_medico = new QRegularExpressionValidator(rx, this);

    numero_interventi = new QLineEdit();
    numero_interventi->setFixedSize(100,20);
    numero_interventi->setMaxLength(3);
    numero_interventi->setValidator(validator_medico);

    h_layout_interventi = new QHBoxLayout();
    h_layout_interventi->addWidget(label_interventi);
    h_layout_interventi->addWidget(numero_interventi);

    v_layout_common = new QVBoxLayout();
    v_layout_common->addWidget(insert_common);

    v_layout_specific = new QVBoxLayout();
    v_layout_specific->addItem(h_layout_interventi);

    grid_layout = new QGridLayout();
    grid_layout->addLayout(v_layout_common,0,0);

    grid_layout->addLayout(v_layout_specific,0,1);

    annulla_inserimento = new QAction(this);
    annulla_inserimento->setShortcut(QKeySequence(Qt::Key_Escape));

    inserisci_dato = new QAction(this);
    inserisci_dato->setShortcut(QKeySequence(Qt::Key_Return));

    connect(annulla_inserimento,&QAction::triggered,this,&VInsertTecnico::close);
    connect(inserisci_dato,&QAction::triggered,this,&VInsertTecnico::prepare_and_send_data);
    connect(insert_common->annulla, &QPushButton::clicked,this,&VInsertTecnico::close);
    connect(insert_common->inserisci, &QPushButton::clicked,this,&VInsertTecnico::prepare_and_send_data);

    this->addAction(inserisci_dato);
    this->addAction(annulla_inserimento);
    this->setLayout(grid_layout);
    this->setWindowTitle("Inserimento dati infermiere");
}
void VInsertTecnico::prepare_and_send_data()
{
    emit send_data(QString(insert_common->get_data() + "|" + numero_interventi->text()));
}
