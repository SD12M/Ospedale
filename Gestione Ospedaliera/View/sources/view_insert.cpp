#include "View/headers/view_insert.h"
ViewInsert::ViewInsert(QWidget* parent) : QWidget(parent) {
  annulla = new QPushButton("Annulla", this);
  inserisci = new QPushButton("Inserisci", this);

  label_nome = new QLabel("Nome : ", this);
  label_nome->setAlignment(Qt::AlignRight);

  label_cognome = new QLabel("Cognome : ", this);
  label_cognome->setAlignment(Qt::AlignRight);

  label_mansione = new QLabel("Mansione : ", this);
  label_mansione->setAlignment(Qt::AlignRight);

  label_stipendio = new QLabel("Stipendio : ", this);
  label_stipendio->setAlignment(Qt::AlignRight);

  label_età = new QLabel("Età : ", this);
  label_età->setAlignment(Qt::AlignRight);

  label_mese = new QLabel("Mese : ", this);
  label_mese->setAlignment(Qt::AlignRight);

  mansione = new QLineEdit(this);
  mansione->setFixedSize(100,20);
  mansione->setEnabled(false);

  QRegularExpression rx("^[a-z]*$");
  validator = new QRegularExpressionValidator(rx, this);

  mese = new QLineEdit(this);
  mese->setFixedSize(100,20);
  mese->setValidator(validator);
  mese->setMaxLength(9);

  nome = new QLineEdit(this);
  nome->setFixedSize(100,20);
  nome->setValidator(validator);
  nome->setMaxLength(10);

  cognome = new QLineEdit(this);
  cognome->setFixedSize(100,20);
  cognome->setValidator(validator);
  cognome->setMaxLength(10);

  età = new QLineEdit(this);
  età->setFixedSize(100,20);
  età->setValidator(new QIntValidator(25, 60, this));

  stipendio = new QLineEdit(this);
  stipendio->setFixedSize(100,20);
  stipendio->setValidator(new QIntValidator(1100, 2500, this));

  h_l1 = new QHBoxLayout();
  h_l2 = new QHBoxLayout();
  h_l3 = new QHBoxLayout();
  h_l4 = new QHBoxLayout();
  h_l5 = new QHBoxLayout();
  h_l6 = new QHBoxLayout();

  h_l1->addWidget(label_nome);
  h_l1->addWidget(nome);

  h_l2->addWidget(label_cognome);
  h_l2->addWidget(cognome);

  h_l3->addWidget(label_mansione);
  h_l3->addWidget(mansione);

  h_l4->addWidget(label_stipendio);
  h_l4->addWidget(stipendio);

  h_l5->addWidget(label_età);
  h_l5->addWidget(età);

  h_l6->addWidget(label_mese);
  h_l6->addWidget(mese);

  // campi dato comuni.
  v_layout1 = new QVBoxLayout();
  v_layout1->addItem(h_l3);
  v_layout1->addSpacing(20);
  v_layout1->addItem(h_l1);
  v_layout1->addSpacing(20);
  v_layout1->addItem(h_l2);
  v_layout1->addSpacing(20);
  v_layout1->addItem(h_l4);
  v_layout1->addSpacing(20);
  v_layout1->addItem(h_l5);
  v_layout1->addSpacing(20);
  v_layout1->addItem(h_l6);

  h_layout_btns = new QHBoxLayout();
  h_layout_btns->addWidget(annulla,0,Qt::AlignLeft);
  h_layout_btns->addWidget(inserisci,0,Qt::AlignRight);

  main_h_layout = new QHBoxLayout();
  main_h_layout->addItem(v_layout1);

  main_v_layout = new QVBoxLayout();
  main_v_layout->addItem(main_h_layout);
  main_v_layout->addStretch(1);
  main_v_layout->addItem(h_layout_btns);

  this->setLayout(main_v_layout);
}
QString ViewInsert::get_data() const
{
  return QString
      (
             nome->text() + "|"
             + cognome->text() + "|"
             + mansione->text() + "|"
             + età->text() + "|"
             + stipendio->text() + "|"
             + mese->text()
      ).toLower();
}
