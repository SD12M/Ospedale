#ifndef MODIFICA_INFERMIERE_H
#define MODIFICA_INFERMIERE_H
#include <QAbstractTableModel>
#include "Classes/headers/vector.h"
#include "Classes/headers/infermiere.h"
#include "Classes/headers/messaggio.h"

class ModificaInfermiere : public QAbstractTableModel
{
    Q_OBJECT
private:
    QStringList dati;
    Persona* const persona;
    ModificaInfermiere(const ModificaInfermiere&);
    Messaggio* show_message;
public:
    ModificaInfermiere(Persona* const, QObject* parent=nullptr);
    ~ModificaInfermiere() = default;
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override final;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override final;
    virtual QVariant data(const QModelIndex &,int role = Qt::DisplayRole) const override final;
    virtual QVariant headerData(int, Qt::Orientation, int) const override final;
    virtual Qt::ItemFlags flags(const QModelIndex &) const override final;
    virtual bool setData(const QModelIndex &, const QVariant &,int role = Qt::EditRole) override final;
signals:
    void state_changed();
    void send_message(const QString,const QString);
};

#endif // MODIFICA_INFERMIERE_H
