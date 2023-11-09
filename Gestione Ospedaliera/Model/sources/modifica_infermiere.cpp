#include "Model/headers/modifica_infermiere.h"
ModificaInfermiere::ModificaInfermiere(Persona * const p, QObject* parent) : QAbstractTableModel(parent), persona(p)
{
    dati = QString::fromStdString(persona->get_info()).split("|");
}
int ModificaInfermiere::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 1;
}
int ModificaInfermiere::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 7;
}
QVariant ModificaInfermiere::headerData(int section, Qt::Orientation orientation,int role) const {
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        switch (section) {
        case 0:
            return QString("Mansione");
            break;
        case 1:
            return QString("Nome");
            break;
        case 2:
            return QString("Cognome");
            break;
        case 3:
            return QString("Età");
                break;
        case 4:
            return QString("Stipendio");
            break;
        case 5:
            return QString("Assistiti");
            break;
        case 6:
            return QString("Mese");
            break;
        }
    }
    return {};
}
QVariant ModificaInfermiere::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole && index.isValid()) {

        unsigned short int col_number = index.column();
        switch (col_number) {
        case 0:
            return dati.at(col_number);
            break;
        case 1:
            return dati.at(col_number);
            break;
        case 2:
            return dati.at(col_number);
            break;
        case 3:
            return dati.at(col_number);
            break;
        case 4:
            return dati.at(col_number);
            break;
        case 5:
            return dati.at(col_number);
            break;
        case 6:
            return dati.at(col_number);
            break;
        }
    }
    return {};
}

Qt::ItemFlags ModificaInfermiere::flags(const QModelIndex &index) const {
    if (index.isValid())
    {
        switch(index.column())
        {
        case 0:
        case 1:
        case 2:
        case 3:
        case 6:
            return Qt::ItemIsSelectable;
        case 4:
        case 5:
            return Qt::ItemIsEnabled | Qt::ItemIsEditable;
        }
    }
    return {};
}

bool ModificaInfermiere::setData(const QModelIndex &index, const QVariant &value,int role)
{
    QString error_message;
    bool esito1;
    unsigned int valore;

    if (role == Qt::EditRole && index.isValid()) {
        int col_number = index.column();
        switch (col_number) {
        case 4:
            valore = value.toUInt(&esito1);
            if(esito1)
            {
                if(valore >= 1100 && valore <= 2500)
                {
                    //
                    (const_cast<Persona*>(persona))->set_stipendio(valore);
                }
                else
                {
                    error_message.append("Il valore dello <FONT COLOR='#C70039'>stipendio</FONT> deve essere compreso tra 1100 e 2500 euro.\n");
                }
            }
            else
            {
                error_message.append("Il valore dello <FONT COLOR='#C70039'>stipendio</FONT> deve essere un numero.\n");
            }
            break;
        case 5:
            valore = value.toUInt(&esito1);
            if(esito1)
            {
                if(dynamic_cast<Infermiere* const>(persona))
                {
                    if(valore > 100)
                    {
                        error_message.append("Il numero degli <FONT COLOR='#C70039'>interventi</FONT> non può essere maggiore di 100.\n");
                    }
                    else
                    {
                        static_cast<Infermiere* const>(persona)->set_assistiti(valore);
                    }
                }
            }
            else
            {
                error_message.append("Il numero degli <FONT COLOR='#C70039'>interventi</FONT> deve essere un numero. \n");
            }

            break;
        }
        if (!error_message.isEmpty())
        {
            emit send_message(QString("Errori di modifica"),QString(error_message));
        }
        else
        {
            emit state_changed();
            dati = QString::fromStdString(persona->get_info()).split("|");
            emit dataChanged(ModificaInfermiere::index(0,index.column()),ModificaInfermiere::index(0,index.column()));
            show_message->messaggio("","Modifica avvenuta con successo !");
            return true;
        }
    }
    return false;
}
