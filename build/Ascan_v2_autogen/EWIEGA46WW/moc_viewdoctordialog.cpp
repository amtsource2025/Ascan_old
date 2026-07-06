/****************************************************************************
** Meta object code from reading C++ file 'viewdoctordialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../viewdoctordialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'viewdoctordialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ViewDoctorDialog_t {
    QByteArrayData data[11];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ViewDoctorDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ViewDoctorDialog_t qt_meta_stringdata_ViewDoctorDialog = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ViewDoctorDialog"
QT_MOC_LITERAL(1, 17, 18), // "on_btn_add_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 19), // "on_btn_edit_clicked"
QT_MOC_LITERAL(4, 57, 21), // "on_btn_delete_clicked"
QT_MOC_LITERAL(5, 79, 19), // "on_btn_view_clicked"
QT_MOC_LITERAL(6, 99, 20), // "on_btn_close_clicked"
QT_MOC_LITERAL(7, 120, 18), // "onDoctorRowClicked"
QT_MOC_LITERAL(8, 139, 3), // "row"
QT_MOC_LITERAL(9, 143, 6), // "column"
QT_MOC_LITERAL(10, 150, 10) // "updateTime"

    },
    "ViewDoctorDialog\0on_btn_add_clicked\0"
    "\0on_btn_edit_clicked\0on_btn_delete_clicked\0"
    "on_btn_view_clicked\0on_btn_close_clicked\0"
    "onDoctorRowClicked\0row\0column\0updateTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ViewDoctorDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    2,   54,    2, 0x08 /* Private */,
      10,    0,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void,

       0        // eod
};

void ViewDoctorDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ViewDoctorDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_btn_add_clicked(); break;
        case 1: _t->on_btn_edit_clicked(); break;
        case 2: _t->on_btn_delete_clicked(); break;
        case 3: _t->on_btn_view_clicked(); break;
        case 4: _t->on_btn_close_clicked(); break;
        case 5: _t->onDoctorRowClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->updateTime(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ViewDoctorDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_ViewDoctorDialog.data,
    qt_meta_data_ViewDoctorDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ViewDoctorDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ViewDoctorDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ViewDoctorDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ViewDoctorDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
