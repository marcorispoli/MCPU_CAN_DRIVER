/****************************************************************************
** Meta object code from reading C++ file 'window.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../SOURCE/WINDOW/window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_debugWindow_t {
    const uint offsetsAndSize[28];
    char stringdata0[184];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_debugWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_debugWindow_t qt_meta_stringdata_debugWindow = {
    {
QT_MOC_LITERAL(0, 11), // "debugWindow"
QT_MOC_LITERAL(12, 16), // "onLogClearButton"
QT_MOC_LITERAL(29, 0), // ""
QT_MOC_LITERAL(30, 18), // "onDebugClearButton"
QT_MOC_LITERAL(49, 16), // "receivedCanFrame"
QT_MOC_LITERAL(66, 5), // "canId"
QT_MOC_LITERAL(72, 4), // "data"
QT_MOC_LITERAL(77, 9), // "sendToCan"
QT_MOC_LITERAL(87, 10), // "timerEvent"
QT_MOC_LITERAL(98, 12), // "QTimerEvent*"
QT_MOC_LITERAL(111, 2), // "ev"
QT_MOC_LITERAL(114, 30), // "on_logEnableCheck_stateChanged"
QT_MOC_LITERAL(145, 4), // "arg1"
QT_MOC_LITERAL(150, 33) // "on_logEnableEthCheck_stateCha..."

    },
    "debugWindow\0onLogClearButton\0\0"
    "onDebugClearButton\0receivedCanFrame\0"
    "canId\0data\0sendToCan\0timerEvent\0"
    "QTimerEvent*\0ev\0on_logEnableCheck_stateChanged\0"
    "arg1\0on_logEnableEthCheck_stateChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_debugWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x0a,    1 /* Public */,
       3,    0,   57,    2, 0x0a,    2 /* Public */,
       4,    2,   58,    2, 0x0a,    3 /* Public */,
       7,    2,   63,    2, 0x0a,    6 /* Public */,
       8,    1,   68,    2, 0x0a,    9 /* Public */,
      11,    1,   71,    2, 0x0a,   11 /* Public */,
      13,    1,   74,    2, 0x0a,   13 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UShort, QMetaType::QByteArray,    5,    6,
    QMetaType::Void, QMetaType::UShort, QMetaType::QByteArray,    5,    6,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void debugWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<debugWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onLogClearButton(); break;
        case 1: _t->onDebugClearButton(); break;
        case 2: _t->receivedCanFrame((*reinterpret_cast< ushort(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 3: _t->sendToCan((*reinterpret_cast< ushort(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 4: _t->timerEvent((*reinterpret_cast< QTimerEvent*(*)>(_a[1]))); break;
        case 5: _t->on_logEnableCheck_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_logEnableEthCheck_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject debugWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_debugWindow.offsetsAndSize,
    qt_meta_data_debugWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_debugWindow_t
, QtPrivate::TypeAndForceComplete<debugWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<ushort, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<ushort, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QTimerEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *debugWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *debugWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_debugWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int debugWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
