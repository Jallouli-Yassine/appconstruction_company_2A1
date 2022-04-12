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
    QByteArrayData data[17];
    char stringdata0[294];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 26), // "on_ButtonAjouter_2_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 26), // "on_ButtonSupprimer_clicked"
QT_MOC_LITERAL(4, 66, 20), // "on_ButtonTri_clicked"
QT_MOC_LITERAL(5, 87, 26), // "on_ButtonAjouter_4_clicked"
QT_MOC_LITERAL(6, 114, 22), // "on_tableView_activated"
QT_MOC_LITERAL(7, 137, 5), // "index"
QT_MOC_LITERAL(8, 143, 26), // "on_Buttonrecherche_clicked"
QT_MOC_LITERAL(9, 170, 14), // "on_PDF_clicked"
QT_MOC_LITERAL(10, 185, 23), // "on_comboBox_4_activated"
QT_MOC_LITERAL(11, 209, 4), // "arg1"
QT_MOC_LITERAL(12, 214, 17), // "on_BtnIMG_clicked"
QT_MOC_LITERAL(13, 232, 13), // "on_on_clicked"
QT_MOC_LITERAL(14, 246, 14), // "on_off_clicked"
QT_MOC_LITERAL(15, 261, 15), // "on_plus_clicked"
QT_MOC_LITERAL(16, 277, 16) // "on_PDF_6_clicked"

    },
    "MainWindow\0on_ButtonAjouter_2_clicked\0"
    "\0on_ButtonSupprimer_clicked\0"
    "on_ButtonTri_clicked\0on_ButtonAjouter_4_clicked\0"
    "on_tableView_activated\0index\0"
    "on_Buttonrecherche_clicked\0on_PDF_clicked\0"
    "on_comboBox_4_activated\0arg1\0"
    "on_BtnIMG_clicked\0on_on_clicked\0"
    "on_off_clicked\0on_plus_clicked\0"
    "on_PDF_6_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    1,   83,    2, 0x08 /* Private */,
       8,    0,   86,    2, 0x08 /* Private */,
       9,    0,   87,    2, 0x08 /* Private */,
      10,    1,   88,    2, 0x08 /* Private */,
      12,    0,   91,    2, 0x08 /* Private */,
      13,    0,   92,    2, 0x08 /* Private */,
      14,    0,   93,    2, 0x08 /* Private */,
      15,    0,   94,    2, 0x08 /* Private */,
      16,    0,   95,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
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
        case 0: _t->on_ButtonAjouter_2_clicked(); break;
        case 1: _t->on_ButtonSupprimer_clicked(); break;
        case 2: _t->on_ButtonTri_clicked(); break;
        case 3: _t->on_ButtonAjouter_4_clicked(); break;
        case 4: _t->on_tableView_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->on_Buttonrecherche_clicked(); break;
        case 6: _t->on_PDF_clicked(); break;
        case 7: _t->on_comboBox_4_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_BtnIMG_clicked(); break;
        case 9: _t->on_on_clicked(); break;
        case 10: _t->on_off_clicked(); break;
        case 11: _t->on_plus_clicked(); break;
        case 12: _t->on_PDF_6_clicked(); break;
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
