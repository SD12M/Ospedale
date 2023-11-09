/****************************************************************************
** Meta object code from reading C++ file 'mainview.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../View/headers/mainview.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainViewENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainViewENDCLASS = QtMocHelpers::stringData(
    "MainView",
    "ask_object_info",
    "",
    "u_int",
    "delete_at",
    "filename",
    "delete_selected_row",
    "aiuto",
    "enable_table",
    "create_choice_view",
    "create_insert_view",
    "Tipo",
    "onTableClicked",
    "QModelIndex",
    "show_specific_info",
    "Persona*",
    "info_clicked",
    "reset_index",
    "enable_disable_insert"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainViewENDCLASS_t {
    uint offsetsAndSizes[38];
    char stringdata0[9];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[10];
    char stringdata5[9];
    char stringdata6[20];
    char stringdata7[6];
    char stringdata8[13];
    char stringdata9[19];
    char stringdata10[19];
    char stringdata11[5];
    char stringdata12[15];
    char stringdata13[12];
    char stringdata14[19];
    char stringdata15[9];
    char stringdata16[13];
    char stringdata17[12];
    char stringdata18[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainViewENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainViewENDCLASS_t qt_meta_stringdata_CLASSMainViewENDCLASS = {
    {
        QT_MOC_LITERAL(0, 8),  // "MainView"
        QT_MOC_LITERAL(9, 15),  // "ask_object_info"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 5),  // "u_int"
        QT_MOC_LITERAL(32, 9),  // "delete_at"
        QT_MOC_LITERAL(42, 8),  // "filename"
        QT_MOC_LITERAL(51, 19),  // "delete_selected_row"
        QT_MOC_LITERAL(71, 5),  // "aiuto"
        QT_MOC_LITERAL(77, 12),  // "enable_table"
        QT_MOC_LITERAL(90, 18),  // "create_choice_view"
        QT_MOC_LITERAL(109, 18),  // "create_insert_view"
        QT_MOC_LITERAL(128, 4),  // "Tipo"
        QT_MOC_LITERAL(133, 14),  // "onTableClicked"
        QT_MOC_LITERAL(148, 11),  // "QModelIndex"
        QT_MOC_LITERAL(160, 18),  // "show_specific_info"
        QT_MOC_LITERAL(179, 8),  // "Persona*"
        QT_MOC_LITERAL(188, 12),  // "info_clicked"
        QT_MOC_LITERAL(201, 11),  // "reset_index"
        QT_MOC_LITERAL(213, 21)   // "enable_disable_insert"
    },
    "MainView",
    "ask_object_info",
    "",
    "u_int",
    "delete_at",
    "filename",
    "delete_selected_row",
    "aiuto",
    "enable_table",
    "create_choice_view",
    "create_insert_view",
    "Tipo",
    "onTableClicked",
    "QModelIndex",
    "show_specific_info",
    "Persona*",
    "info_clicked",
    "reset_index",
    "enable_disable_insert"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainViewENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   92,    2, 0x06,    1 /* Public */,
       4,    1,   95,    2, 0x06,    3 /* Public */,
       5,    1,   98,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,  101,    2, 0x08,    7 /* Private */,
       7,    0,  102,    2, 0x08,    8 /* Private */,
       8,    0,  103,    2, 0x08,    9 /* Private */,
       9,    0,  104,    2, 0x08,   10 /* Private */,
      10,    1,  105,    2, 0x08,   11 /* Private */,
      12,    1,  108,    2, 0x0a,   13 /* Public */,
      14,    1,  111,    2, 0x0a,   15 /* Public */,
      16,    0,  114,    2, 0x0a,   17 /* Public */,
      17,    0,  115,    2, 0x0a,   18 /* Public */,
      18,    0,  116,    2, 0x0a,   19 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainView::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainViewENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainViewENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainViewENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainView, std::true_type>,
        // method 'ask_object_info'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<u_int, std::false_type>,
        // method 'delete_at'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<u_int, std::false_type>,
        // method 'filename'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'delete_selected_row'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'aiuto'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'enable_table'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'create_choice_view'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'create_insert_view'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Tipo &, std::false_type>,
        // method 'onTableClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'show_specific_info'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Persona * const, std::false_type>,
        // method 'info_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'reset_index'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'enable_disable_insert'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->ask_object_info((*reinterpret_cast< std::add_pointer_t<u_int>>(_a[1]))); break;
        case 1: _t->delete_at((*reinterpret_cast< std::add_pointer_t<u_int>>(_a[1]))); break;
        case 2: _t->filename((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->delete_selected_row(); break;
        case 4: _t->aiuto(); break;
        case 5: _t->enable_table(); break;
        case 6: _t->create_choice_view(); break;
        case 7: _t->create_insert_view((*reinterpret_cast< std::add_pointer_t<Tipo>>(_a[1]))); break;
        case 8: _t->onTableClicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 9: _t->show_specific_info((*reinterpret_cast< std::add_pointer_t<Persona*>>(_a[1]))); break;
        case 10: _t->info_clicked(); break;
        case 11: _t->reset_index(); break;
        case 12: _t->enable_disable_insert(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainView::*)(u_int );
            if (_t _q_method = &MainView::ask_object_info; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainView::*)(u_int );
            if (_t _q_method = &MainView::delete_at; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainView::*)(const QString & );
            if (_t _q_method = &MainView::filename; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *MainView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainViewENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MainView::ask_object_info(u_int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainView::delete_at(u_int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainView::filename(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
