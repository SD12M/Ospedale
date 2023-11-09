#ifndef MODIFICA_H
#define MODIFICA_H
#include <QAbstractTableModel>
#include "Classes/headers/vector.h"
#include "Classes/headers/medico.h"



class Modifica : public QAbstractTableModel {
  Q_OBJECT
protected:
    QStringList dati;
    Persona* const persona;
    Modifica(const Modifica&);
public:
      explicit Modifica(Persona* const,QObject *parent=nullptr);
      ~Modifica();
      virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
      virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;
      virtual QVariant data(const QModelIndex &,int role = Qt::DisplayRole) const override;
      virtual QVariant headerData(int, Qt::Orientation, int) const override;
      virtual Qt::ItemFlags flags(const QModelIndex &) const override;
      virtual bool setData(const QModelIndex &, const QVariant &,int role = Qt::EditRole) override;
  signals:
      void state_changed();
      void send_message(const QString,const QString);
};
#endif
