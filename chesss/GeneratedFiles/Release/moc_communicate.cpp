/****************************************************************************
** Meta object code from reading C++ file 'communicate.h'
**
** Created: Wed Mar 31 20:31:19 2010
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../communicate.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'communicate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Communicate[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      17,   13,   12,   12, 0x05,
      35,   13,   12,   12, 0x05,
      51,   13,   12,   12, 0x05,
      69,   12,   12,   12, 0x05,
      89,   13,   12,   12, 0x05,
     110,   13,   12,   12, 0x05,
     128,   13,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
     146,   12,   12,   12, 0x0a,
     163,   12,   12,   12, 0x0a,
     208,  188,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Communicate[] = {
    "Communicate\0\0str\0dataShow(QString)\0"
    "invite(QString)\0isInvite(QString)\0"
    "recChatMeg(QString)\0showMessage(QString)\0"
    "gameDate(QString)\0errorMeg(QString)\0"
    "receiveMessage()\0sendChatMessage(QString)\0"
    "x,y,offsetX,offsetY\0sendGameData(int,int,int,int)\0"
};

const QMetaObject Communicate::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Communicate,
      qt_meta_data_Communicate, 0 }
};

const QMetaObject *Communicate::metaObject() const
{
    return &staticMetaObject;
}

void *Communicate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Communicate))
        return static_cast<void*>(const_cast< Communicate*>(this));
    return QObject::qt_metacast(_clname);
}

int Communicate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: dataShow((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: invite((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: isInvite((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: recChatMeg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: showMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: gameDate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: errorMeg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: receiveMessage(); break;
        case 8: sendChatMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: sendGameData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        }
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Communicate::dataShow(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Communicate::invite(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Communicate::isInvite(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Communicate::recChatMeg(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Communicate::showMessage(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Communicate::gameDate(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Communicate::errorMeg(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
