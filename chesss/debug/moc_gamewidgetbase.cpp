/****************************************************************************
** Meta object code from reading C++ file 'gamewidgetbase.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gamewidgetbase.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamewidgetbase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GameWidgetBase[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   16,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      45,   15,   15,   15, 0x08,
      71,   15,   15,   15, 0x08,
      95,   15,   15,   15, 0x08,
     133,   15,   15,   15, 0x08,
     154,   15,   15,   15, 0x08,
     170,  166,   15,   15, 0x08,
     201,   15,   15,   15, 0x08,
     231,  229,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GameWidgetBase[] = {
    "GameWidgetBase\0\0str\0sendChatMessage(QString)\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_clicked()\0"
    "on_lineEditSendmesage_returnPressed()\0"
    "showMessage(QString)\0updateLCD()\0,,,\0"
    "stepLCDNumber(int,int,int,int)\0"
    "handlerAnotherData(QString)\0i\0result(int)\0"
};

void GameWidgetBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GameWidgetBase *_t = static_cast<GameWidgetBase *>(_o);
        switch (_id) {
        case 0: _t->sendChatMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_2_clicked(); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_lineEditSendmesage_returnPressed(); break;
        case 4: _t->showMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->updateLCD(); break;
        case 6: _t->stepLCDNumber((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 7: _t->handlerAnotherData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->result((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GameWidgetBase::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GameWidgetBase::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GameWidgetBase,
      qt_meta_data_GameWidgetBase, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GameWidgetBase::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GameWidgetBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GameWidgetBase::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GameWidgetBase))
        return static_cast<void*>(const_cast< GameWidgetBase*>(this));
    return QWidget::qt_metacast(_clname);
}

int GameWidgetBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void GameWidgetBase::sendChatMessage(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
