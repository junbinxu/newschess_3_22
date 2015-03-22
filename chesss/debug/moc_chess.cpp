/****************************************************************************
** Meta object code from reading C++ file 'chess.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../chess.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chess.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_chess[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

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

void chess::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        chess *_t = static_cast<chess *>(_o);
        switch (_id) {
        case 0: _t->on_listWidget_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_3_clicked(); break;
        case 2: _t->dataShow((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->invite((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->isInvite((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->errorMeg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->result((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData chess::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject chess::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_chess,
      qt_meta_data_chess, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &chess::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *chess::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
