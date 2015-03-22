/****************************************************************************
** Meta object code from reading C++ file 'chess.h'
**
** Created: Thu Apr 1 10:15:16 2010
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../chess.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chess.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_chess[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x08,
      57,    6,    6,    6, 0x08,
      87,   83,    6,    6, 0x08,
     105,   83,    6,    6, 0x08,
     121,   83,    6,    6, 0x08,
     139,   83,    6,    6, 0x08,
     157,    6,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_chess[] = {
    "chess\0\0on_listWidget_itemDoubleClicked(QListWidgetItem*)\0"
    "on_pushButton_3_clicked()\0str\0"
    "dataShow(QString)\0invite(QString)\0"
    "isInvite(QString)\0errorMeg(QString)\0"
    "result(int)\0"
};

const QMetaObject chess::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_chess,
      qt_meta_data_chess, 0 }
};

const QMetaObject *chess::metaObject() const
{
    return &staticMetaObject;
}

void *chess::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_chess))
        return static_cast<void*>(const_cast< chess*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int chess::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_listWidget_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 1: on_pushButton_3_clicked(); break;
        case 2: dataShow((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: invite((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: isInvite((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: errorMeg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: result((*reinterpret_cast< int(*)>(_a[1]))); break;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
