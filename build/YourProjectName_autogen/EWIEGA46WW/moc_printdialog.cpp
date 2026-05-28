/****************************************************************************
** Meta object code from reading C++ file 'printdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../printdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'printdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PrintDialog_t {
    QByteArrayData data[13];
    char stringdata0[257];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PrintDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PrintDialog_t qt_meta_stringdata_PrintDialog = {
    {
QT_MOC_LITERAL(0, 0, 11), // "PrintDialog"
QT_MOC_LITERAL(1, 12, 10), // "updateTime"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 19), // "on_btn_back_clicked"
QT_MOC_LITERAL(4, 44, 19), // "on_btn_scan_clicked"
QT_MOC_LITERAL(5, 64, 27), // "on_btn_calculations_clicked"
QT_MOC_LITERAL(6, 92, 19), // "on_btn_both_clicked"
QT_MOC_LITERAL(7, 112, 25), // "on_btn_newPatient_clicked"
QT_MOC_LITERAL(8, 138, 20), // "on_btn_both2_clicked"
QT_MOC_LITERAL(9, 159, 20), // "on_btn_both3_clicked"
QT_MOC_LITERAL(10, 180, 28), // "on_btn_calculations2_clicked"
QT_MOC_LITERAL(11, 209, 20), // "on_btn_scan2_clicked"
QT_MOC_LITERAL(12, 230, 26) // "on_btn_newPatient2_clicked"

    },
    "PrintDialog\0updateTime\0\0on_btn_back_clicked\0"
    "on_btn_scan_clicked\0on_btn_calculations_clicked\0"
    "on_btn_both_clicked\0on_btn_newPatient_clicked\0"
    "on_btn_both2_clicked\0on_btn_both3_clicked\0"
    "on_btn_calculations2_clicked\0"
    "on_btn_scan2_clicked\0on_btn_newPatient2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PrintDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

 // slots: parameters
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

void PrintDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PrintDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateTime(); break;
        case 1: _t->on_btn_back_clicked(); break;
        case 2: _t->on_btn_scan_clicked(); break;
        case 3: _t->on_btn_calculations_clicked(); break;
        case 4: _t->on_btn_both_clicked(); break;
        case 5: _t->on_btn_newPatient_clicked(); break;
        case 6: _t->on_btn_both2_clicked(); break;
        case 7: _t->on_btn_both3_clicked(); break;
        case 8: _t->on_btn_calculations2_clicked(); break;
        case 9: _t->on_btn_scan2_clicked(); break;
        case 10: _t->on_btn_newPatient2_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject PrintDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_PrintDialog.data,
    qt_meta_data_PrintDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PrintDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PrintDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PrintDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int PrintDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
