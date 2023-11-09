#include "Model/headers/modifica.h"

Modifica::Modifica(Persona* const persona,QObject *parent): QAbstractTableModel(parent), persona(persona)
{
    dati = QString::fromStdString(persona->get_info()).split("|");
}
QVariant Modifica::headerData(int section, Qt::Orientation orientation,int role) const {

  return {};
}
int Modifica::rowCount(const QModelIndex &index) const {
  Q_UNUSED(index)
  return 1;
}

int Modifica::columnCount(const QModelIndex &index) const {
  Q_UNUSED(index)

  return 7;
}
QVariant Modifica::data(const QModelIndex &index, int role) const {

  return {};
}
Qt::ItemFlags Modifica::flags(const QModelIndex &index) const {

    return {};
}

bool Modifica::setData(const QModelIndex &index, const QVariant &value,int role) {
    /*
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
            persona->set_stipendio(valore);
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
        if(dynamic_cast<Medico*>(persona))
        {
            if(esito1)
            {
                if(valore > 100)
                {
                    error_message.append("Il numero dei <FONT COLOR='#C70039'>pazienti morti</FONT> non può essere maggiore di 100.\n");
                }
                else
                {
                    static_cast<Medico*>(persona)->set_morti(valore);
                }
            }
            else
            {
                error_message.append("Il numero dei <FONT COLOR='#C70039'>pazienti morti</FONT> deve essere un numero. \n");
            }
        }
        if(dynamic_cast<Infermiere*>(persona))
        {
            if(esito1)
            {
                if(valore >=10 && valore < 101)
                {
                    static_cast<Infermiere*>(persona)->set_assistiti(valore);
                }
                else
                {
                    error_message.append("Il numero degli <FONT COLOR='#C70039'>interventi</FONT> deve essere un numero compreso tra 10 e 100.\n");
                }
            }
            else
            {
                error_message.append("Il numero degli <FONT COLOR='#C70039'>interventi</FONT> deve essere un numero. \n");
            }
        }
        if(dynamic_cast<Tecnico*>(persona))
        {
            if(esito1)
            {
                if(valore >=10 && valore < 101)
                {
                    static_cast<Tecnico*>(persona)->set_interventi(valore);
                }
                else
                {
                    error_message.append("Il numero degli <FONT COLOR='#C70039'>interventi</FONT> deve essere un numero compreso tra 10 e 100.\n");
                }
            }
            else
            {
                error_message.append("Il numero degli <FONT COLOR='#C70039'>interventi</FONT> deve essere un numero. \n");
            }
        }
      break;
    case 6:
        if(dynamic_cast<Medico*>(persona))
        {
            valore = value.toUInt(&esito1);
            if(esito1)
            {
                if(valore > 100)
                {
                    error_message.append("Il numero dei <FONT COLOR='#C70039'>pazienti salvati</FONT> non può essere maggiore di 100.\n");
                }
                else
                {
                    static_cast<Medico*>(persona)->set_salvati(valore);
                }
            }
            else
            {
                error_message.append("Il numero dei <FONT COLOR='#C70039'>pazienti salvati</FONT> deve essere un numero maggiore di 0.\n");
            }
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
        emit dataChanged(Modifica::index(0,index.column()),Modifica::index(0,index.column()));
        emit send_message(QString("Successo"),QString("Modifica avvenuta con successo !"));
        return true;
    }
  }
  return false;*/
    return {};
}
Modifica::~Modifica()
{
 //   (const_cast<Persona*>(persona)) = nullptr;
}
