#include <QApplication>
#include "View/headers/mainview.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainView vista;
    vista.show();
    return a.exec();
}
