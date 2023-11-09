#include "Model/headers/main_m.h"
TableModel::TableModel(QObject * parent): QAbstractTableModel(parent), dati_caricati(false),state_changed(false) {
    anno_corrente = QDate::currentDate().year();
    sound = new QSoundEffect(this);
    sound->setVolume(0.25f);
    sound->setLoopCount(0);
}
void TableModel::load_from_file(const QString& filename) {
    file.setFileName(filename);
    if(vettore_dati.size()>0)
    {
        vettore_dati.clear();
    }
    sound->setSource(QUrl::fromLocalFile(":/resources/audio/insert.wav"));
    file.setFileName(filename);
    if (file.open(QIODevice::ReadOnly) && file.size() > 0) {
        QTextStream in ( & file);
        in.setEncoding(QStringConverter::Utf8);
        QString values = QString(in.readAll());
        if(values.isEmpty())
        {
            show_message->messaggio("Errore caricamento","Il file selezionato è vuoto");
        }
        else
        {
            file.close();
            jsonData = QJsonDocument::fromJson(values.toUtf8()).object();
            if(!jsonData.isEmpty())
            {
                QJsonArray values_array;
                values_array = jsonData.value("medici").toArray();
                format_json_data(values_array, "medico");
                values_array = jsonData.value("infermieri").toArray();
                format_json_data(values_array, "infermiere");
                values_array = jsonData.value("tecnici").toArray();
                format_json_data(values_array, "tecnico");
                if(vettore_dati.size() > 0)
                {
                    beginResetModel();
                    sound->play();
                    dati_caricati = true;
                    state_changed = false;
                    emit data_loaded();
                    endResetModel();
                }
            }
            else
            {
                show_message->messaggio("Errore caricamento","Il file non è formattato correttamente");
            }
        }
    }
    else
    {
        show_message->messaggio("Errore file",file.errorString());
    }
}
void TableModel::format_json_data(QJsonArray & A,const QString & tipo_oggetto)
{
    QString mese;
    string mansione;
    string nome;
    string cognome;
    int eta;
    int stipendio;
    for (auto it = A.begin(), end = A.end(); it != end; ++it) {
        auto object = it[0].toObject();
        if(object.keys().count() > 0)
        {
            if( object.contains("nome") && object.contains("cognome") && object.contains("eta")
                && object.contains("mese") && object.contains("stipendio") && object.contains("mansione"))
            {
                if(object.value("nome").isString() && object.value("cognome").isString() && object.value("mese").isString()
                    && object.value("mansione").isString() && object.value("stipendio").isDouble() && object.value("eta").isDouble())
                {
                    nome = object.value("nome").toString().toLower().toStdString();
                    cognome = object.value("cognome").toString().toLower().toStdString();
                    mansione = object.value("mansione").toString().toLower().toStdString();
                    mese = object.value("mese").toString().toLower();
                    stipendio = object.value("stipendio").toInt();
                    eta = object.value("eta").toInt();

                    if(mansione != "medico" && mansione != "tecnico" && mansione != "infermiere")
                    {
                        continue;
                    }

                    if(nome.length() > 10 || nome.length() <= 2)
                    {
                        continue;
                    }
                    if(cognome.length() > 10 || cognome.length() <= 2)
                    {
                        continue;
                    }
                    if(eta < 25 || eta >= 70)
                    {
                        continue;
                    }
                    if(stipendio <= 1100 || stipendio > 2500)
                    {
                        continue;
                    }
                    if (!CheckMese::check_mese(mese)) {
                        continue;
                    }

                    if(tipo_oggetto == "medico" && object.keys().count() == 8) // due tipi aggiunti
                    {
                        if(object.contains("n_morti") && object.contains("n_salvati"))
                        {
                            if(object.value("n_morti").isDouble() && object.value("n_salvati").isDouble())
                            {
                                int numero_morti = object.value("n_morti").toInt();
                                int numero_salvati = object.value("n_salvati").toInt();

                                if(numero_morti < 0 || numero_morti >= 101)
                                {
                                    continue;
                                }
                                if(numero_salvati < 0 || numero_salvati >= 101)
                                {
                                    continue;
                                }
                                if(vettore_dati.find_presence(Medico(static_cast<unsigned int>(numero_morti),static_cast<unsigned int>(numero_salvati),static_cast<unsigned int>(stipendio), mansione, nome, cognome, static_cast<unsigned int>(eta), mese.toStdString())))
                                {
                                    vettore_dati.push_back(new Medico(static_cast<unsigned int>(numero_morti),static_cast<unsigned int>(numero_salvati),static_cast<unsigned int>(stipendio), mansione, nome, cognome, static_cast<unsigned int>(eta), mese.toStdString()));
                                }
                            }
                        }
                    }
                    if(tipo_oggetto == "infermiere" && object.keys().count() == 7)
                    {
                        if(object.contains("n_interventi"))
                        {
                            if(object.value("n_interventi").isDouble())
                            {
                                int numero_interventi = object.value("n_interventi").toInt();
                                if(numero_interventi < 10 || numero_interventi >= 101)
                                {
                                    continue;
                                }

                                if(vettore_dati.find_presence(Infermiere(static_cast<unsigned int>(numero_interventi),mese.toStdString(),static_cast<unsigned int>(stipendio), mansione, nome, cognome,static_cast<unsigned int>(eta))))
                                {
                                    vettore_dati.push_back(new Infermiere(static_cast<unsigned int>(numero_interventi),mese.toStdString(),static_cast<unsigned int>(stipendio), mansione, nome, cognome,static_cast<unsigned int>(eta)));
                                }
                            }
                        }
                    }
                    if(tipo_oggetto == "tecnico" && object.keys().count() == 7)
                    {
                        if(object.contains("n_interventi"))
                        {
                            if(object.value("n_interventi").isDouble())
                            {
                                int numero_interventi = object.value("n_interventi").toInt();
                                if(numero_interventi < 10 || numero_interventi >= 101)
                                {
                                    continue;
                                }

                                if(vettore_dati.find_presence(Tecnico(static_cast<unsigned int>(numero_interventi),mese.toStdString(),static_cast<unsigned int>(stipendio), mansione, nome, cognome, static_cast<unsigned int>(eta))))
                                {
                                    vettore_dati.push_back(new Tecnico(static_cast<unsigned int>(numero_interventi),mese.toStdString(),static_cast<unsigned int>(stipendio), mansione, nome, cognome, static_cast<unsigned int>(eta)));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const {
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
        }
    }
    return {};
}
int TableModel::rowCount(const QModelIndex & index) const {
    Q_UNUSED(index);
    return vettore_dati.size();
}
int TableModel::columnCount(const QModelIndex & index) const {
    Q_UNUSED(index);
    return 5;
}
QVariant TableModel::data(const QModelIndex & index, int role) const {
    if (role == Qt::DisplayRole && index.isValid() && vettore_dati[index.row()]) {
            auto x = vettore_dati[index.row()];
            switch (index.column()) {
            case 0:
                return QString::fromStdString(x -> get_mansione());
                break;
            case 1:
                return QString::fromStdString(x -> get_nome());
                break;
            case 2:
                return QString::fromStdString(x -> get_cognome());
                break;
            case 3:
                return QString::number(x -> get_età());
                    break;
            case 4:
                return QString::number(x -> get_stipendio());
                break;
            }
    }
    return {};
}
Qt::ItemFlags TableModel::flags(const QModelIndex & index) const {
    if (index.isValid()) {
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
    }
    return {};
}
void TableModel::select_info(int row)
{
    if(row >= 0)
    {
        emit draw_info(vettore_dati[row]);
    }
    else
    {
        show_message->messaggio("Informazioni aggiuntive","Selezionare prima la riga di interesse");
    }
}
void TableModel::inserisci(const QString & dati) {
    sound->setSource(QUrl::fromLocalFile(":/resources/audio/insert2.wav"));
    QStringList lista_dati = dati.split("|");

    QString error_message;
    string nome;
    string cognome;
    string mansione;
    string mese;
    double stipendio;

    bool esito1;
    bool esito2;

    us_int eta;
    us_int numero_morti;
    us_int numero_salvati;
    us_int numero_interventi;

    unsigned int tipoDato = 3;
    if(lista_dati.size() > 0)
    {
        nome = lista_dati[0].toLower().toStdString();
        cognome = lista_dati[1].toLower().toStdString();
        mansione = lista_dati[2].toLower().toStdString();
        eta = lista_dati[3].toUInt(&esito1);
        stipendio = lista_dati[4].toUInt(&esito2);
        mese = lista_dati[5].toLower().toStdString();

        if(mansione == "medico")
        {
            tipoDato = 0;
        }
        if(mansione == "infermiere")
        {
            tipoDato = 1;
        }
        if(mansione == "tecnico")
        {
            tipoDato = 2;
        }

        if (nome.empty()) {
            error_message.append("Il campo <FONT COLOR='#C70039'>nome</FONT> non può essere vuoto. \n");
        }
        if (cognome.empty()) {
            error_message.append("Il campo <FONT COLOR='#C70039'>cognome</FONT> non può essere vuoto. \n");
        }

        if (esito2) {
            if (stipendio < 1100) {
                error_message.append("Il campo <FONT COLOR='#C70039'>stipendio</FONT> non può essere inferiore ai 1100 euro. \n");
            }
            if (stipendio > 2500) {
                error_message.append("Il campo <FONT COLOR='#C70039'>stipendio</FONT> non può superare i 2500 euro. \n");
            }
        } else {
            error_message.append("Il campo <FONT COLOR='#C70039'>stipendio</FONT> deve contenere un numero. \n");
        }

        if (esito1) {
            if (eta > 60) {
                error_message.append("Il campo <FONT COLOR='#C70039'>età</FONT> non può essere maggiore ai 60 anni. \n");
            }
            if (eta < 25) {
                error_message.append("Il campo <FONT COLOR='#C70039'>età</FONT> non può essere inferiore ai 25 anni. \n");
            }
        } else {
            error_message.append("Il campo <FONT COLOR='#C70039'>età</FONT> deve contenere un numero. \n");
        }

        if(lista_dati.size() == 7)
        {
            numero_interventi = lista_dati[6].toUInt(&esito1);
            if(esito1)
            {
                if(numero_interventi < 10 || numero_interventi >= 101)
                {
                    error_message.append("Il campo numero degli interventi deve essere un numero tra 10 e 100. \n");
                }
            }
            else
            {
                error_message.append("Il campo <FONT COLOR='#C70039'>interventi</FONT> deve contenere un numero. \n");
            }

            if (!CheckMese::check_mese(QString::fromStdString(mese))) {
                error_message.append("Inserire correttamente il campo <FONT COLOR='#C70039'>mese</FONT>. \n");
            }
        }
        if(lista_dati.size() == 8)
        {
            numero_morti = lista_dati[6].toUInt(&esito1);
            numero_salvati = lista_dati[7].toUInt(&esito2);
            if(esito1)
            {
                if (numero_morti >= 101 || numero_morti < 10) {
                    error_message.append("Il campo <FONT COLOR='#C70039'>numero morti</FONT> deve essere un numero maggiore 10 e minore di 100. \n");
                }
            }
            else
            {
                error_message.append("Il campo <FONT COLOR='#C70039'>numero morti</FONT> deve contenere un numero. \n");
            }

            if(esito2)
            {
                if (numero_salvati >= 101 || numero_salvati < 10) {
                    error_message.append("Il campo <FONT COLOR='#C70039'>salvati</FONT> deve essere numero maggiore di 10 e minore di 100. \n");
                }
            }
            else
            {
                error_message.append("Il campo <FONT COLOR='#C70039'>numero salvati</FONT> deve contenere un numero. \n");
            }
            if (!CheckMese::check_mese(QString::fromStdString(mese))) {
                error_message.append("Inserire correttamente il campo <FONT COLOR='#C70039'>mese</FONT>. \n");
            }
        }

        if (error_message.isEmpty()) {
            state_changed = true;
            emit data_loaded();
            switch (tipoDato) {
            case 0:
                if(vettore_dati.find_presence(Medico(numero_morti,numero_salvati,stipendio,mansione,nome,cognome,eta,mese)))
                {
                    beginInsertRows({}, 0, 0);
                    vettore_dati.push_back(new Medico(numero_morti, numero_salvati, stipendio, mansione, nome, cognome, eta,mese));
                    endInsertRows();
                    sound->play();
                    emit insert_success();
                    show_message->messaggio("Inserimento dato","Dato inserito con <FONT COLOR='#097969'>successo !</FONT>");
                }
                else
                {
                    show_message->messaggio("Inserimento dato","Per il mese specifiato è già presente un dato.");
                }
                break;
            case 1:
               if(vettore_dati.find_presence(Infermiere(numero_interventi,mese,stipendio,mansione,nome,cognome,eta)))
                {
                    beginInsertRows({}, 0, 0);
                    vettore_dati.push_back(new Infermiere(numero_interventi,mese,stipendio, mansione, nome, cognome,eta));
                    endInsertRows();
                    sound->play();
                    emit insert_success();
                    show_message->messaggio("Inserimento dato","Dato inserito con <FONT COLOR='#097969'>successo !</FONT>");
                }
                else
                {
                    show_message->messaggio("Inserimento dato","Per il mese specifiato è già presente un dato.");
                }
                break;
            case 2:
                if(vettore_dati.find_presence(Tecnico(numero_interventi,mese,stipendio,mansione,nome,cognome,eta)))
                {
                    beginInsertRows({}, 0, 0);
                    vettore_dati.push_back(new Tecnico(numero_interventi,mese,stipendio, mansione, nome, cognome,eta));
                    endInsertRows();
                    sound->play();
                    show_message->messaggio("Inserimento dato","Dato inserito con <FONT COLOR='#097969'>successo !</FONT>");
                    emit insert_success();
                }
                else
                {
                    show_message->messaggio("Inserimento dato","Per il mese specifiato è già presente un dato.");
                }
                break;
            default:
                return;
                break;
            }
        } else {
            show_message->messaggio("Errori inserimento",error_message);
        }
    }
}
bool TableModel::get_caricati() const
{
    return dati_caricati;
}
void TableModel::delete_obj_at_row(int indice) {

    if(indice >= 0)
    {
        state_changed = true;
        sound->setSource(QUrl::fromLocalFile(":/resources/audio/delete.wav"));
        beginRemoveRows({}, indice, indice);
        vettore_dati.erase(indice);
        endRemoveRows();
        sound->play();
        emit delete_success();
        if(vettore_dati.empty())
        {
          emit zero_data();
        }
    }
}
void TableModel::salva_to_file(const QString& filename) {
    QJsonObject main_object;
    QJsonArray medici;
    QJsonArray infermieri;
    QJsonArray tecnici;

    if(vettore_dati.size() > 0 && state_changed)
    {
        for(auto i = vettore_dati.begin(); i != vettore_dati.end(); i++)
        {
            const Persona* persona = *i;
            QJsonObject item;
            item.insert("mansione",QString::fromStdString(persona->get_mansione()));
            item.insert("nome",QString::fromStdString(persona->get_nome()));
            item.insert("cognome",QString::fromStdString(persona->get_cognome()));
            item.insert("eta",persona->get_età());
            item.insert("stipendio",persona->get_stipendio());

            if(dynamic_cast<const Medico*>(persona))
            {
                const Medico* medico = static_cast<const Medico*>(persona);
                item.insert("n_morti",medico->get_morti());
                item.insert("n_salvati",medico->get_salvati());
                item.insert("mese",QString::fromStdString(medico->get_mese()));
                medici.push_back(item);
                continue;
            }

            if(dynamic_cast<const Infermiere*>(persona))
            {
                const Infermiere* infermiere = static_cast<const Infermiere*>(persona);
                item.insert("n_interventi",infermiere->get_interventi());
                item.insert("mese",QString::fromStdString(infermiere->get_mese()));
                infermieri.push_back(item);
                continue;
            }

            if(dynamic_cast<const Tecnico*>(persona))
            {
                const Tecnico* tecnico = static_cast<const Tecnico*>(persona);
                item.insert("n_interventi",tecnico->get_interventi());
                item.insert("mese",QString::fromStdString(tecnico->get_mese()));
                tecnici.push_back(item);
            }
        }
        main_object.insert("medici",medici);
        main_object.insert("infermieri",infermieri);
        main_object.insert("tecnici",tecnici);
        QJsonDocument doc;
        doc.setObject(main_object);
        QByteArray by = doc.toJson(QJsonDocument::Indented);

        QFile file(filename);
        if (file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
        {
            state_changed = false;
            QTextStream iStream(&file);
            iStream << by;
            file.close();
            show_message->messaggio("Salvataggio dati","Salvataggio dati avvenuto con <FONT COLOR='#097969'>successo</FONT>.");
        }
        else
        {
            show_message->messaggio("Errore salvataggio","Impossibile <FONT COLOR='#C70039'>aprire</FONT> il file.");
        }
    }
    else
    {
        show_message->messaggio("Salvataggio vuoto","Non ci sono modifiche da salvare.");
    }
}
bool TableModel::get_model_state() const
{
    return state_changed;
}
u_int TableModel::get_dipendenti() const
{
    return vettore_dati.size();
}
void TableModel::modifica_state_changed()
{
    state_changed = true;
}
