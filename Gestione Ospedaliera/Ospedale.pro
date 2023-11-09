QT       += core gui
QT       += charts
QT       += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    Classes/sources/messaggio.cpp \
    Classes/sources/check_mese.cpp \
    Classes/sources/tecnico.cpp \
    Classes/sources/infermiere.cpp\
    Classes/sources/medico.cpp\
    Classes/sources/persona.cpp\
    Model/sources/modifica_infermiere.cpp \
    Model/sources/modifica_medico.cpp \
    Model/sources/modifica_tecnico.cpp \
    View/sources/view_insert.cpp \
    View/sources/mainview.cpp\
    View/sources/insert.cpp\
    View/sources/DrawView.cpp\
    Model/sources/main_m.cpp\
    View/sources/view_insert_infermiere.cpp \
    View/sources/view_insert_medico.cpp \
    View/sources/view_insert_tecnico.cpp \
    main.cpp

HEADERS += \
    Classes/headers/ConstVisitor.h \
    Model/headers/modifica_infermiere.h \
    Model/headers/modifica_medico.h \
    Model/headers/modifica_tecnico.h \
    Classes/headers/messaggio.h \
    Classes/headers/check_mese.h \
    Classes/headers/tecnico.h \
    Classes/headers/infermiere.h\
    Classes/headers/medico.h\
    Classes/headers/persona.h\
    Classes/headers/vector.h\
    View/headers/insert.h\
    View/headers/view_insert.h\
    View/headers/mainview.h\
    View/headers/DrawView.h\
    Model/headers/main_m.h \
    View/headers/view_insert_infermiere.h \
    View/headers/view_insert_medico.h \
    View/headers/view_insert_tecnico.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES = risorse.qrc


