/****************************************************************************
** Meta object code from reading C++ file 'calculatordialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "calculatordialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calculatordialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CalculatorDialog_t {
    QByteArrayData data[19];
    char stringdata0[429];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CalculatorDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CalculatorDialog_t qt_meta_stringdata_CalculatorDialog = {
    {
QT_MOC_LITERAL(0, 0, 16), // "CalculatorDialog"
QT_MOC_LITERAL(1, 17, 10), // "updateTime"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 39), // "on_comboBox_lensOne_currentIn..."
QT_MOC_LITERAL(4, 69, 5), // "index"
QT_MOC_LITERAL(5, 75, 39), // "on_comboBox_lensTwo_currentIn..."
QT_MOC_LITERAL(6, 115, 41), // "on_comboBox_lensThree_current..."
QT_MOC_LITERAL(7, 157, 19), // "on_btn_home_clicked"
QT_MOC_LITERAL(8, 177, 22), // "on_btn_measure_clicked"
QT_MOC_LITERAL(9, 200, 25), // "on_btn_newPatient_clicked"
QT_MOC_LITERAL(10, 226, 20), // "on_btn_print_clicked"
QT_MOC_LITERAL(11, 247, 19), // "on_btn_srkt_clicked"
QT_MOC_LITERAL(12, 267, 20), // "on_btn_srkii_clicked"
QT_MOC_LITERAL(13, 288, 22), // "on_btn_hofferq_clicked"
QT_MOC_LITERAL(14, 311, 23), // "on_btn_holladay_clicked"
QT_MOC_LITERAL(15, 335, 21), // "on_btn_haigis_clicked"
QT_MOC_LITERAL(16, 357, 23), // "on_btn_warning1_clicked"
QT_MOC_LITERAL(17, 381, 23), // "on_btn_warning2_clicked"
QT_MOC_LITERAL(18, 405, 23) // "on_btn_warning3_clicked"

    },
    "CalculatorDialog\0updateTime\0\0"
    "on_comboBox_lensOne_currentIndexChanged\0"
    "index\0on_comboBox_lensTwo_currentIndexChanged\0"
    "on_comboBox_lensThree_currentIndexChanged\0"
    "on_btn_home_clicked\0on_btn_measure_clicked\0"
    "on_btn_newPatient_clicked\0"
    "on_btn_print_clicked\0on_btn_srkt_clicked\0"
    "on_btn_srkii_clicked\0on_btn_hofferq_clicked\0"
    "on_btn_holladay_clicked\0on_btn_haigis_clicked\0"
    "on_btn_warning1_clicked\0on_btn_warning2_clicked\0"
    "on_btn_warning3_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CalculatorDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    1,   95,    2, 0x08 /* Private */,
       5,    1,   98,    2, 0x08 /* Private */,
       6,    1,  101,    2, 0x08 /* Private */,
       7,    0,  104,    2, 0x08 /* Private */,
       8,    0,  105,    2, 0x08 /* Private */,
       9,    0,  106,    2, 0x08 /* Private */,
      10,    0,  107,    2, 0x08 /* Private */,
      11,    0,  108,    2, 0x08 /* Private */,
      12,    0,  109,    2, 0x08 /* Private */,
      13,    0,  110,    2, 0x08 /* Private */,
      14,    0,  111,    2, 0x08 /* Private */,
      15,    0,  112,    2, 0x08 /* Private */,
      16,    0,  113,    2, 0x08 /* Private */,
      17,    0,  114,    2, 0x08 /* Private */,
      18,    0,  115,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CalculatorDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CalculatorDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateTime(); break;
        case 1: _t->on_comboBox_lensOne_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_comboBox_lensTwo_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_comboBox_lensThree_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_btn_home_clicked(); break;
        case 5: _t->on_btn_measure_clicked(); break;
        case 6: _t->on_btn_newPatient_clicked(); break;
        case 7: _t->on_btn_print_clicked(); break;
        case 8: _t->on_btn_srkt_clicked(); break;
        case 9: _t->on_btn_srkii_clicked(); break;
        case 10: _t->on_btn_hofferq_clicked(); break;
        case 11: _t->on_btn_holladay_clicked(); break;
        case 12: _t->on_btn_haigis_clicked(); break;
        case 13: _t->on_btn_warning1_clicked(); break;
        case 14: _t->on_btn_warning2_clicked(); break;
        case 15: _t->on_btn_warning3_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CalculatorDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CalculatorDialog.data,
    qt_meta_data_CalculatorDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CalculatorDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CalculatorDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CalculatorDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int CalculatorDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
