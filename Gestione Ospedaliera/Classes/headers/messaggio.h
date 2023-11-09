#ifndef MESSAGGIO_H
#define MESSAGGIO_H
#include <QMessageBox>
class Messaggio : public QMessageBox
{
public:
    explicit Messaggio(QWidget* parent = nullptr);
    void messaggio(const QString&,const QString&);
};
#endif // MESSAGGIO_H
