#include "View/headers/view_insert_infermiere.h"

VInsertInfermiere::VInsertInfermiere(QWidget* parent) : QWidget(parent)
{
    insert_common = new ViewInsert(this);
    insert_common->mansione->setText("infermiere");

    label_assistiti = new QLabel("Assistiti :",this);
    label_assistiti->setAlignment(Qt::AlignRight);

    QRegularExpression rx("^[0-9]*$");
    validator_medico = new QRegularExpressionValidator(rx, this);

    numero_assistiti = new QLineEdit();
    numero_assistiti->setFixedSize(100,20);
    numero_assistiti->setMaxLength(3);
    numero_assistiti->setValidator(validator_medico);

    h_layout_assistiti = new QHBoxLayout();
    h_layout_assistiti->addWidget(label_assistiti);
    h_layout_assistiti->addWidget(numero_assistiti);

    v_layout_common = new QVBoxLayout();
    v_layout_common->addWidget(insert_common);

    v_layout_specific = new QVBoxLayout();
    v_layout_specific->addItem(h_layout_assistiti);

    grid_layout = new QGridLayout();
    grid_layout->addLayout(v_layout_common,0,0);

    grid_layout->addLayout(v_layout_specific,0,1);

    annulla_inserimento = new QAction(this);
    annulla_inserimento->setShortcut(QKeySequence(Qt::Key_Escape));

    inserisci_dato = new QAction(this);
    inserisci_dato->setShortcut(QKeySequence(Qt::Key_Return));

    connect(annulla_inserimento,&QAction::triggered,this,&VInsertInfermiere::close);
    connect(inserisci_dato,&QAction::triggered,this,&VInsertInfermiere::prepare_and_send_data);
    connect(insert_common->annulla, &QPushButton::clicked,this,&VInsertInfermiere::close);
    connect(insert_common->inserisci, &QPushButton::clicked,this,&VInsertInfermiere::prepare_and_send_data);

    this->addAction(annulla_inserimento);
    this->addAction(inserisci_dato);
    this->setLayout(grid_layout);
    this->setWindowTitle("Inserimento dati infermiere");
}
void VInsertInfermiere::prepare_and_send_data()
{
    emit send_data(QString(insert_common->get_data() + "|" + numero_assistiti->text()));
}
