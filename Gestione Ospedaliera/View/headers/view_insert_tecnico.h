#ifndef VIEW_INSERT_TECNICO_H
#define VIEW_INSERT_TECNICO_H
#include "View/headers/view_insert.h"
class VInsertTecnico : public QWidget
{
    Q_OBJECT
private:
    ViewInsert* insert_common;

    QLineEdit* numero_interventi;

    QLabel* label_interventi;

    QHBoxLayout* h_layout_interventi;
    QValidator* validator_medico;


    QVBoxLayout* v_layout_common;
    QVBoxLayout* v_layout_specific;

    QGridLayout* grid_layout;

    QAction* annulla_inserimento;
    QAction* inserisci_dato;
public:
    VInsertTecnico(QWidget* parent = nullptr);
private slots:
    void prepare_and_send_data();
signals:
    void send_data(const QString);
};



#endif // VIEW_INSERT_TECNICO_H
