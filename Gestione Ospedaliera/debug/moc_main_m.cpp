/****************************************************************************
** Meta object code from reading C++ file 'main_m.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Model/headers/main_m.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_m.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSTableModelENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSTableModelENDCLASS = QtMocHelpers::stringData(
    "TableModel",
    "draw_info",
    "",
    "Persona*",
    "insert_success",
    "delete_success",
    "data_saved",
    "data_loaded",
    "zero_data",
    "salva_to_file",
    "select_info",
    "inserisci",
    "delete_obj_at_row",
    "indice",
    "load_from_file",
    "modifica_state_changed"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSTableModelENDCLASS_t {
    uint offsetsAndSizes[32];
    char stringdata0[11];
    char stringdata1[10];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[15];
    char stringdata5[15];
    char stringdata6[11];
    char stringdata7[12];
    char stringdata8[10];
    char stringdata9[14];
    char stringdata10[12];
    char stringdata11[10];
    char stringdata12[18];
    char stringdata13[7];
    char stringdata14[15];
    char stringdata15[23];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSTableModelENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSTableModelENDCLASS_t qt_meta_stringdata_CLASSTableModelENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "TableModel"
        QT_MOC_LITERAL(11, 9),  // "draw_info"
        QT_MOC_LITERAL(21, 0),  // ""
        QT_MOC_LITERAL(22, 8),  // "Persona*"
        QT_MOC_LITERAL(31, 14),  // "insert_success"
        QT_MOC_LITERAL(46, 14),  // "delete_success"
        QT_MOC_LITERAL(61, 10),  // "data_saved"
        QT_MOC_LITERAL(72, 11),  // "data_loaded"
        QT_MOC_LITERAL(84, 9),  // "zero_data"
        QT_MOC_LITERAL(94, 13),  // "salva_to_file"
        QT_MOC_LITERAL(108, 11),  // "select_info"
        QT_MOC_LITERAL(120, 9),  // "inserisci"
        QT_MOC_LITERAL(130, 17),  // "delete_obj_at_row"
        QT_MOC_LITERAL(148, 6),  // "indice"
        QT_MOC_LITERAL(155, 14),  // "load_from_file"
        QT_MOC_LITERAL(170, 22)   // "modifica_state_changed"
    },
    "TableModel",
    "draw_info",
    "",
    "Persona*",
    "insert_success",
    "delete_success",
    "data_saved",
    "data_loaded",
    "zero_data",
    "salva_to_file",
    "select_info",
    "inserisci",
    "delete_obj_at_row",
    "indice",
    "load_from_file",
    "modifica_state_changed"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTableModelENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   86,    2, 0x06,    1 /* Public */,
       4,    0,   89,    2, 0x06,    3 /* Public */,
       5,    0,   90,    2, 0x06,    4 /* Public */,
       6,    0,   91,    2, 0x06,    5 /* Public */,
       7,    0,   92,    2, 0x06,    6 /* Public */,
       8,    0,   93,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    1,   94,    2, 0x0a,    8 /* Public */,
      10,    1,   97,    2, 0x0a,   10 /* Public */,
      11,    1,  100,    2, 0x0a,   12 /* Public */,
      12,    1,  103,    2, 0x0a,   14 /* Public */,
      14,    1,  106,    2, 0x0a,   16 /* Public */,
      15,    0,  109,    2, 0x0a,   18 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject TableModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractTableModel::staticMetaObject>(),
    qt_meta_stringdata_CLASSTableModelENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTableModelENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTableModelENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TableModel, std::true_type>,
        // method 'draw_info'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Persona * const, std::false_type>,
        // method 'insert_success'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'delete_success'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'data_saved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'data_loaded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'zero_data'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'salva_to_file'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'select_info'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'inserisci'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'delete_obj_at_row'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'load_from_file'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'modifica_state_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void TableModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TableModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->draw_info((*reinterpret_cast< std::add_pointer_t<Persona*>>(_a[1]))); break;
        case 1: _t->insert_success(); break;
        case 2: _t->delete_success(); break;
        case 3: _t->data_saved(); break;
        case 4: _t->data_loaded(); break;
        case 5: _t->zero_data(); break;
        case 6: _t->salva_to_file((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->select_info((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->inserisci((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->delete_obj_at_row((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->load_from_file((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: _t->modifica_state_changed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TableModel::*)(Persona * const );
            if (_t _q_method = &TableModel::draw_info; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TableModel::*)();
            if (_t _q_method = &TableModel::insert_success; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TableModel::*)();
            if (_t _q_method = &TableModel::delete_success; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TableModel::*)();
            if (_t _q_method = &TableModel::data_saved; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TableModel::*)();
            if (_t _q_method = &TableModel::data_loaded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (TableModel::*)();
            if (_t _q_method = &TableModel::zero_data; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject *TableModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TableModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTableModelENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QAbstractTableModel::qt_metacast(_clname);
}

int TableModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void TableModel::draw_info(Persona * const _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TableModel::insert_success()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TableModel::delete_success()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void TableModel::data_saved()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void TableModel::data_loaded()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void TableModel::zero_data()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
