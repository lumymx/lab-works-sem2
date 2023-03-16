/****************************************************************************
** Meta object code from reading C++ file 'calculator.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../calculator/calculator.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calculator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_Calculator_t {
    uint offsetsAndSizes[22];
    char stringdata0[11];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[16];
    char stringdata5[14];
    char stringdata6[13];
    char stringdata7[14];
    char stringdata8[14];
    char stringdata9[13];
    char stringdata10[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Calculator_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Calculator_t qt_meta_stringdata_Calculator = {
    {
        QT_MOC_LITERAL(0, 10),  // "Calculator"
        QT_MOC_LITERAL(11, 13),  // "numberClicked"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 15),  // "operatorClicked"
        QT_MOC_LITERAL(42, 15),  // "functionClicked"
        QT_MOC_LITERAL(58, 13),  // "memoryClicked"
        QT_MOC_LITERAL(72, 12),  // "clearClicked"
        QT_MOC_LITERAL(85, 13),  // "deleteClicked"
        QT_MOC_LITERAL(99, 13),  // "negateClicked"
        QT_MOC_LITERAL(113, 12),  // "pointClicked"
        QT_MOC_LITERAL(126, 13)   // "equalsClicked"
    },
    "Calculator",
    "numberClicked",
    "",
    "operatorClicked",
    "functionClicked",
    "memoryClicked",
    "clearClicked",
    "deleteClicked",
    "negateClicked",
    "pointClicked",
    "equalsClicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Calculator[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x08,    1 /* Private */,
       3,    0,   69,    2, 0x08,    2 /* Private */,
       4,    0,   70,    2, 0x08,    3 /* Private */,
       5,    0,   71,    2, 0x08,    4 /* Private */,
       6,    0,   72,    2, 0x08,    5 /* Private */,
       7,    0,   73,    2, 0x08,    6 /* Private */,
       8,    0,   74,    2, 0x08,    7 /* Private */,
       9,    0,   75,    2, 0x08,    8 /* Private */,
      10,    0,   76,    2, 0x08,    9 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Calculator::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Calculator.offsetsAndSizes,
    qt_meta_data_Calculator,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Calculator_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Calculator, std::true_type>,
        // method 'numberClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'operatorClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'functionClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'memoryClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clearClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deleteClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'negateClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pointClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'equalsClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Calculator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Calculator *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->numberClicked(); break;
        case 1: _t->operatorClicked(); break;
        case 2: _t->functionClicked(); break;
        case 3: _t->memoryClicked(); break;
        case 4: _t->clearClicked(); break;
        case 5: _t->deleteClicked(); break;
        case 6: _t->negateClicked(); break;
        case 7: _t->pointClicked(); break;
        case 8: _t->equalsClicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *Calculator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Calculator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Calculator.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Calculator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
