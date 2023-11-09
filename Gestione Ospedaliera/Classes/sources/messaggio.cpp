#include "Classes/headers/messaggio.h"
Messaggio::Messaggio(QWidget *parent) : QMessageBox(parent)
{

}
void Messaggio::messaggio(const QString& title, const QString& message)
{
    QMessageBox* box = new QMessageBox();
    box->setWindowTitle(title);
    box->setAttribute(Qt::WA_DeleteOnClose);
    box->setWindowModality(Qt::ApplicationModal);
    box->setText(message);
    if(title == "Errori inserimento" || title == "Errori di modifica" || title == "Errore salvataggio"
        || title == "Errore file" || title == "Errore scelta file" || title == "Errore dati" || title == "Errore caricamento")
    {
        box->setIcon(QMessageBox::Critical);
    }
    else if (title == "Salvataggio vuoto")
    {
        box->setIcon(QMessageBox::Warning);
    }
    else
    {
        box->setIcon(QMessageBox::Information);
    }
    box->show();
}
