#ifndef VIEW_INSERT_H
#define VIEW_INSERT_H
#include "Model/headers/main_m.h"
#include "Classes/headers/messaggio.h"
#include <QWidget>
#include <QPushButton>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QAbstractItemView>
#include <QLabel>
#include <QLineEdit>
#include <QCloseEvent>
#include <QRegularExpression>
#include <QAction>
#include <QScreen>

class ViewInsert : public QWidget  {
    Q_OBJECT
    friend class VInsertMedico;
    friend class VInsertInfermiere;
    friend class VInsertTecnico;

private:
  QPushButton *annulla;
  QPushButton *inserisci;

  QLabel *label_nome;
  QLabel *label_mansione;
  QLabel *label_cognome;
  QLabel *label_età;
  QLabel *label_stipendio;
  QLabel *label_mese;

  QLineEdit *mansione;
  QLineEdit *nome;
  QLineEdit *cognome;
  QLineEdit *età;
  QLineEdit *stipendio;
  QLineEdit *mese;

  QVBoxLayout *v_layout1;
  QVBoxLayout *main_v_layout;

  QHBoxLayout *main_h_layout;
  QHBoxLayout *h_layout_btns;

  QHBoxLayout *h_l1;
  QHBoxLayout *h_l2;
  QHBoxLayout *h_l3;
  QHBoxLayout *h_l4;
  QHBoxLayout *h_l5;
  QHBoxLayout *h_l6;

  QValidator* validator;

  QString get_data() const;

public:
    ViewInsert(QWidget* parent = nullptr);
};
#endif // VIEW_INSERT_H
