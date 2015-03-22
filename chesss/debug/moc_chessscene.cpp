/****************************************************************************
** Meta object code from reading C++ file 'chessscene.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../chessscene.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chessscene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ChessScene[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      32,   12,   11,   11, 0x05,
      68,   66,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      84,   80,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ChessScene[] = {
    "ChessScene\0\0x,y,offsetX,offsetY\0"
    "sendMegToAnother(int,int,int,int)\0i\0"
    "result(int)\0str\0handlerAnotherData(QString)\0"
};

void ChessScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ChessScene *_t = static_cast<ChessScene *>(_o);
        switch (_id) {
        case 0: _t->sendMegToAnother((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: _t->result((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->handlerAnotherData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ChessScene::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ChessScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_ChessScene,
      qt_meta_data_ChessScene, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ChessScene::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ChessScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ChessScene::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChessScene))
        return static_cast<void*>(const_cast< ChessScene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int ChessScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ChessScene::sendMegToAnother(int _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ChessScene::result(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
