/****************************************************************************
** Meta object code from reading C++ file 'qtcontactlist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../address-book-master/src/qtcontactlist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtcontactlist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QtContactList_t {
    QByteArrayData data[7];
    char stringdata0[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtContactList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtContactList_t qt_meta_stringdata_QtContactList = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QtContactList"
QT_MOC_LITERAL(1, 14, 15), // "contactSelected"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 18), // "Contact::ContactId"
QT_MOC_LITERAL(4, 50, 10), // "selectedId"
QT_MOC_LITERAL(5, 61, 18), // "refreshContactList"
QT_MOC_LITERAL(6, 80, 25) // "dispatchListItemContactId"

    },
    "QtContactList\0contactSelected\0\0"
    "Contact::ContactId\0selectedId\0"
    "refreshContactList\0dispatchListItemContactId"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtContactList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   32,    2, 0x0a /* Public */,
       6,    0,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QtContactList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtContactList *_t = static_cast<QtContactList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->contactSelected((*reinterpret_cast< Contact::ContactId(*)>(_a[1]))); break;
        case 1: _t->refreshContactList(); break;
        case 2: _t->dispatchListItemContactId(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QtContactList::*_t)(Contact::ContactId );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtContactList::contactSelected)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject QtContactList::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_QtContactList.data,
      qt_meta_data_QtContactList,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QtContactList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtContactList::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QtContactList.stringdata0))
        return static_cast<void*>(const_cast< QtContactList*>(this));
    return QListWidget::qt_metacast(_clname);
}

int QtContactList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void QtContactList::contactSelected(Contact::ContactId _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
