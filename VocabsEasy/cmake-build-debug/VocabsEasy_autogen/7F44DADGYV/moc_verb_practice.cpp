/****************************************************************************
** Meta object code from reading C++ file 'verb_practice.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "vocabs_ui/verb_practice.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'verb_practice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VerbPractice_t {
    QByteArrayData data[12];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VerbPractice_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VerbPractice_t qt_meta_stringdata_VerbPractice = {
    {
QT_MOC_LITERAL(0, 0, 12), // "VerbPractice"
QT_MOC_LITERAL(1, 13, 6), // "goBack"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 13), // "onBackClicked"
QT_MOC_LITERAL(4, 35, 15), // "onRepeatClicked"
QT_MOC_LITERAL(5, 51, 15), // "onAnswerClicked"
QT_MOC_LITERAL(6, 67, 16), // "onOptionsClicked"
QT_MOC_LITERAL(7, 84, 13), // "onNextClicked"
QT_MOC_LITERAL(8, 98, 12), // "onVerbUpdate"
QT_MOC_LITERAL(9, 111, 4), // "Verb"
QT_MOC_LITERAL(10, 116, 4), // "verb"
QT_MOC_LITERAL(11, 121, 10) // "onIndexMax"

    },
    "VerbPractice\0goBack\0\0onBackClicked\0"
    "onRepeatClicked\0onAnswerClicked\0"
    "onOptionsClicked\0onNextClicked\0"
    "onVerbUpdate\0Verb\0verb\0onIndexMax"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VerbPractice[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   55,    2, 0x0a /* Public */,
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,
       8,    1,   60,    2, 0x0a /* Public */,
      11,    0,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,

       0        // eod
};

void VerbPractice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VerbPractice *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->goBack(); break;
        case 1: _t->onBackClicked(); break;
        case 2: _t->onRepeatClicked(); break;
        case 3: _t->onAnswerClicked(); break;
        case 4: _t->onOptionsClicked(); break;
        case 5: _t->onNextClicked(); break;
        case 6: _t->onVerbUpdate((*reinterpret_cast< const Verb(*)>(_a[1]))); break;
        case 7: _t->onIndexMax(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VerbPractice::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VerbPractice::goBack)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VerbPractice::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_VerbPractice.data,
    qt_meta_data_VerbPractice,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VerbPractice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VerbPractice::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VerbPractice.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int VerbPractice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void VerbPractice::goBack()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
