#ifndef VIEW_INSERT_INFERMIERE_H
#define VIEW_INSERT_INFERMIERE_H

#include "View/headers/view_insert.h"

class VInsertInfermiere : public QWidget
{
    Q_OBJECT
private:
    ViewInsert* insert_common;

    QLineEdit* numero_assistiti;

    QLabel* label_assistiti;

    QHBoxLayout* h_layout_assistiti;
    QValidator* validator_medico;


    QVBoxLayout* v_layout_common;
    QVBoxLayout* v_layout_specific;

    QGridLayout* grid_layout;

    QAction* annulla_inserimento;
    QAction* inserisci_dato;

public:
    VInsertInfermiere(QWidget* parent = nullptr);
private slots:
    void prepare_and_send_data();
signals:
    void send_data(const QString);
};


#endif // VIEW_INSERT_INFERMIERE_H
