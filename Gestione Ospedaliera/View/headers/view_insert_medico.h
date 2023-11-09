#ifndef VIEW_INSERT_MEDICO_H
#define VIEW_INSERT_MEDICO_H
#include "View/headers/view_insert.h"
class VInsertMedico : public QWidget
{
    Q_OBJECT
private:

    ViewInsert* insert_common;

    QLineEdit* numero_morti_edit;
    QLineEdit* numero_salvati_edit;

    QLabel* label_morti;
    QLabel* label_salvati;

    QHBoxLayout* h_layout_morti;
    QHBoxLayout* h_layout_salvati;
    QHBoxLayout* h_main_layout;

    QValidator* validator_medico;


    QVBoxLayout* v_layout_common;
    QVBoxLayout* v_layout_specific;

    QAction* annulla_inserimento;
    QAction* inserisci_dato;

public:
    VInsertMedico(QWidget* parent = nullptr);
private slots:
    void prepare_and_send_data();
signals:
    void send_data(const QString);
};



#endif // VIEW_INSERT_MEDICO_H
