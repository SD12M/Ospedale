#ifndef TABLEMODEL_H
#define TABLEMODEL_H
#include "modifica.h"
#include "Classes/headers/vector.h"
#include "Classes/headers/medico.h"
#include "Classes/headers/tecnico.h"
#include "Classes/headers/infermiere.h"
#include "Classes/headers/check_mese.h"
#include "Classes/headers/messaggio.h"

#include <string>
#include <QAbstractTableModel>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QTextStream>
#include <QDir>
#include <QValidator>
#include <QSoundEffect>

class TableModel : public QAbstractTableModel {
  Q_OBJECT
private:
    Vector<Persona*> vettore_dati;
    QJsonObject jsonData;
    QFile file;
    us_int anno_corrente;
    QSoundEffect* sound;
    Messaggio* show_message;
    void format_json_data(QJsonArray &, const QString&);
    bool dati_caricati;
    bool state_changed;
public:
    explicit TableModel(QObject *parent=nullptr);
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual QVariant data(const QModelIndex &,int role = Qt::DisplayRole) const override;
    virtual Qt::ItemFlags flags(const QModelIndex &) const override;
    virtual QVariant headerData(int, Qt::Orientation, int) const override;

    bool get_model_state() const;
    bool get_caricati() const;
    u_int get_dipendenti() const;
public slots:
    void salva_to_file(const QString&);
    void select_info(int);
    void inserisci(const QString&);
    void delete_obj_at_row(int indice);
    void load_from_file(const QString&);
    void modifica_state_changed();
signals:
    void draw_info(Persona * const);
    void insert_success();
    void delete_success();
    void data_saved();
    void data_loaded();
    void zero_data();
};
#endif // TABLEMODEL_H
