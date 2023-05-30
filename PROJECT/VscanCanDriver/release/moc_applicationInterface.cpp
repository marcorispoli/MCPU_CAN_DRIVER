/****************************************************************************
** Meta object code from reading C++ file 'applicationInterface.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../MCPU_SHARED_MODULES/MODULES/APPLICATION_INTERFACE/applicationInterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'applicationInterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SocketItem_t {
    const uint offsetsAndSize[24];
    char stringdata0[142];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SocketItem_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SocketItem_t qt_meta_stringdata_SocketItem = {
    {
QT_MOC_LITERAL(0, 10), // "SocketItem"
QT_MOC_LITERAL(11, 16), // "itemDisconnected"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 2), // "id"
QT_MOC_LITERAL(32, 18), // "receivedCommandSgn"
QT_MOC_LITERAL(51, 4), // "data"
QT_MOC_LITERAL(56, 12), // "disconnected"
QT_MOC_LITERAL(69, 11), // "socketError"
QT_MOC_LITERAL(81, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(110, 5), // "error"
QT_MOC_LITERAL(116, 12), // "socketRxData"
QT_MOC_LITERAL(129, 12) // "socketTxData"

    },
    "SocketItem\0itemDisconnected\0\0id\0"
    "receivedCommandSgn\0data\0disconnected\0"
    "socketError\0QAbstractSocket::SocketError\0"
    "error\0socketRxData\0socketTxData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SocketItem[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x06,    1 /* Public */,
       4,    2,   53,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   58,    2, 0x0a,    6 /* Public */,
       7,    1,   59,    2, 0x0a,    7 /* Public */,
      10,    0,   62,    2, 0x0a,    9 /* Public */,
      11,    1,   63,    2, 0x0a,   10 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UShort,    3,
    QMetaType::Void, QMetaType::UShort, QMetaType::QByteArray,    3,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    2,

       0        // eod
};

void SocketItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SocketItem *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->itemDisconnected((*reinterpret_cast< ushort(*)>(_a[1]))); break;
        case 1: _t->receivedCommandSgn((*reinterpret_cast< ushort(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 2: _t->disconnected(); break;
        case 3: _t->socketError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 4: _t->socketRxData(); break;
        case 5: _t->socketTxData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SocketItem::*)(ushort );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SocketItem::itemDisconnected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SocketItem::*)(ushort , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SocketItem::receivedCommandSgn)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject SocketItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SocketItem.offsetsAndSize,
    qt_meta_data_SocketItem,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_SocketItem_t
, QtPrivate::TypeAndForceComplete<SocketItem, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<ushort, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<ushort, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketError, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>


>,
    nullptr
} };


const QMetaObject *SocketItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SocketItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SocketItem.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SocketItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void SocketItem::itemDisconnected(ushort _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SocketItem::receivedCommandSgn(ushort _t1, QByteArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_applicationInterface_t {
    const uint offsetsAndSize[14];
    char stringdata0[71];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_applicationInterface_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_applicationInterface_t qt_meta_stringdata_applicationInterface = {
    {
QT_MOC_LITERAL(0, 20), // "applicationInterface"
QT_MOC_LITERAL(21, 7), // "txFrame"
QT_MOC_LITERAL(29, 0), // ""
QT_MOC_LITERAL(30, 4), // "data"
QT_MOC_LITERAL(35, 19), // "receivedCommandSlot"
QT_MOC_LITERAL(55, 2), // "id"
QT_MOC_LITERAL(58, 12) // "disconnected"

    },
    "applicationInterface\0txFrame\0\0data\0"
    "receivedCommandSlot\0id\0disconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_applicationInterface[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   32,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    2,   35,    2, 0x0a,    3 /* Public */,
       6,    1,   40,    2, 0x0a,    6 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::UShort, QMetaType::QByteArray,    5,    3,
    QMetaType::Void, QMetaType::UShort,    5,

       0        // eod
};

void applicationInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<applicationInterface *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->txFrame((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->receivedCommandSlot((*reinterpret_cast< ushort(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 2: _t->disconnected((*reinterpret_cast< ushort(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (applicationInterface::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&applicationInterface::txFrame)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject applicationInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QTcpServer::staticMetaObject>(),
    qt_meta_stringdata_applicationInterface.offsetsAndSize,
    qt_meta_data_applicationInterface,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_applicationInterface_t
, QtPrivate::TypeAndForceComplete<applicationInterface, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<ushort, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<ushort, std::false_type>


>,
    nullptr
} };


const QMetaObject *applicationInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *applicationInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_applicationInterface.stringdata0))
        return static_cast<void*>(this);
    return QTcpServer::qt_metacast(_clname);
}

int applicationInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void applicationInterface::txFrame(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
