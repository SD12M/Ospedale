#ifndef INSERT_H
#define INSERT_H
#include "Classes/headers/messaggio.h"
#include <QWidget>
#include <QPushButton>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QRadioButton>
#include <QAction>
#include <QScreen>
enum class Tipo
{
    Medico,Infermiere,Tecnico
};
class Insert : public QWidget
{
    Q_OBJECT
private:
    QPushButton* annulla;
    QPushButton* seleziona;

    QRadioButton* scelta_dottore;
    QRadioButton* scelta_infermiere;
    QRadioButton* scelta_tecnico;

    QGroupBox* scelte;
    QVBoxLayout* v_layout;
    QVBoxLayout* v_layout2;

    QGridLayout* grid_layout;

    QAction* seleziona_dato;
    QAction* annulla_inserimento;
public:
    explicit Insert(QWidget *parent = 0);
    ~Insert() = default;
public slots:
    void invia_scelta();
signals:
    void scelta_inserimento(const Tipo&);
};
#endif // INSERT_H
