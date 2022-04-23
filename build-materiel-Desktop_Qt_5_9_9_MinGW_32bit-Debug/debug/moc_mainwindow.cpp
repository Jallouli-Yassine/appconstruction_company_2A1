/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../materiel/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[333];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 12), // "update_label"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 26), // "on_ButtonAjouter_2_clicked"
QT_MOC_LITERAL(4, 52, 26), // "on_ButtonSupprimer_clicked"
QT_MOC_LITERAL(5, 79, 20), // "on_ButtonTri_clicked"
QT_MOC_LITERAL(6, 100, 26), // "on_ButtonAjouter_4_clicked"
QT_MOC_LITERAL(7, 127, 22), // "on_tableView_activated"
QT_MOC_LITERAL(8, 150, 5), // "index"
QT_MOC_LITERAL(9, 156, 26), // "on_Buttonrecherche_clicked"
QT_MOC_LITERAL(10, 183, 14), // "on_PDF_clicked"
QT_MOC_LITERAL(11, 198, 23), // "on_comboBox_4_activated"
QT_MOC_LITERAL(12, 222, 4), // "arg1"
QT_MOC_LITERAL(13, 227, 17), // "on_BtnIMG_clicked"
QT_MOC_LITERAL(14, 245, 13), // "on_on_clicked"
QT_MOC_LITERAL(15, 259, 14), // "on_off_clicked"
QT_MOC_LITERAL(16, 274, 15), // "on_plus_clicked"
QT_MOC_LITERAL(17, 290, 16), // "on_PDF_6_clicked"
QT_MOC_LITERAL(18, 307, 25) // "on_pushButton_OFF_clicked"

    },
    "MainWindow\0update_label\0\0"
    "on_ButtonAjouter_2_clicked\0"
    "on_ButtonSupprimer_clicked\0"
    "on_ButtonTri_clicked\0on_ButtonAjouter_4_clicked\0"
    "on_tableView_activated\0index\0"
    "on_Buttonrecherche_clicked\0on_PDF_clicked\0"
    "on_comboBox_4_activated\0arg1\0"
    "on_BtnIMG_clicked\0on_on_clicked\0"
    "on_off_clicked\0on_plus_clicked\0"
    "on_PDF_6_clicked\0on_pushButton_OFF_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    1,   94,    2, 0x08 /* Private */,
       9,    0,   97,    2, 0x08 /* Private */,
      10,    0,   98,    2, 0x08 /* Private */,
      11,    1,   99,    2, 0x08 /* Private */,
      13,    0,  102,    2, 0x08 /* Private */,
      14,    0,  103,    2, 0x08 /* Private */,
      15,    0,  104,    2, 0x08 /* Private */,
      16,    0,  105,    2, 0x08 /* Private */,
      17,    0,  106,    2, 0x08 /* Private */,
      18,    0,  107,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->update_label(); break;
        case 1: _t->on_ButtonAjouter_2_clicked(); break;
        case 2: _t->on_ButtonSupprimer_clicked(); break;
        case 3: _t->on_ButtonTri_clicked(); break;
        case 4: _t->on_ButtonAjouter_4_clicked(); break;
        case 5: _t->on_tableView_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->on_Buttonrecherche_clicked(); break;
        case 7: _t->on_PDF_clicked(); break;
        case 8: _t->on_comboBox_4_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_BtnIMG_clicked(); break;
        case 10: _t->on_on_clicked(); break;
        case 11: _t->on_off_clicked(); break;
        case 12: _t->on_plus_clicked(); break;
        case 13: _t->on_PDF_6_clicked(); break;
        case 14: _t->on_pushButton_OFF_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
