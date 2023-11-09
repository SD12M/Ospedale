#include "View/headers/view_insert_medico.h"

VInsertMedico::VInsertMedico(QWidget* parent) : QWidget(parent)
{
    insert_common = new ViewInsert(this);
    insert_common->mansione->setText("medico");

    label_morti = new QLabel("Morti :",this);
    label_morti->setAlignment(Qt::AlignRight);

    label_salvati = new QLabel("Salvati :",this);
    label_salvati->setAlignment(Qt::AlignRight);

    QRegularExpression rx("^[0-9]*$");
    validator_medico = new QRegularExpressionValidator(rx, this);

    numero_morti_edit = new QLineEdit(this);
    numero_morti_edit->setFixedSize(100,20);
    numero_morti_edit->setMaxLength(3);
    numero_morti_edit->setValidator(validator_medico);

    numero_salvati_edit = new QLineEdit(this);
    numero_salvati_edit->setFixedSize(100,20);
    numero_salvati_edit->setMaxLength(3);
    numero_salvati_edit->setValidator(validator_medico);

    h_layout_morti = new QHBoxLayout();
    h_layout_morti->addWidget(label_morti);
    h_layout_morti->addWidget(numero_morti_edit);

    h_layout_salvati = new QHBoxLayout();
    h_layout_salvati->addWidget(label_salvati);
    h_layout_salvati->addWidget(numero_salvati_edit);

    v_layout_common = new QVBoxLayout();
    v_layout_common->addWidget(insert_common);

    v_layout_specific = new QVBoxLayout();
    v_layout_specific->addItem(h_layout_morti);
    v_layout_specific->addItem(h_layout_salvati);

    h_main_layout = new QHBoxLayout();
    h_main_layout->addItem(v_layout_common);
    h_main_layout->addSpacing(20);
    h_main_layout->addItem(v_layout_specific);


    annulla_inserimento = new QAction(this);
    annulla_inserimento->setShortcut(QKeySequence(Qt::Key_Escape));

    inserisci_dato = new QAction(this);
    inserisci_dato->setShortcut(QKeySequence(Qt::Key_Return));

    connect(annulla_inserimento,&QAction::triggered,this,&VInsertMedico::close);
    connect(inserisci_dato,&QAction::triggered,this,&VInsertMedico::prepare_and_send_data);
    connect(insert_common->annulla, &QPushButton::clicked,this,&VInsertMedico::close);
    connect(insert_common->inserisci, &QPushButton::clicked,this,&VInsertMedico::prepare_and_send_data);

    this->addAction(inserisci_dato);
    this->addAction(annulla_inserimento);
    this->setLayout(h_main_layout);
    this->setWindowTitle("Inserimento dati medico");
}
void VInsertMedico::prepare_and_send_data()
{
    emit send_data(QString(insert_common->get_data() + "|" + numero_morti_edit->text() + "|" + numero_salvati_edit->text()));
}
