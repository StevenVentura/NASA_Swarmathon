/****************************************************************************
** Meta object code from reading C++ file 'rover_gui_plugin.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/rqt_rover_gui/src/rover_gui_plugin.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rover_gui_plugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rqt_rover_gui__RoverGUIPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      42,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      16,       // signalCount

 // signals: signature, parameters, type, tag, flags
      31,   30,   30,   30, 0x05,
      59,   30,   30,   30, 0x05,
      90,   87,   30,   30, 0x05,
     134,   30,   30,   30, 0x05,
     169,   30,   30,   30, 0x05,
     205,   30,   30,   30, 0x05,
     237,   30,   30,   30, 0x05,
     270,   30,   30,   30, 0x05,
     307,   30,   30,   30, 0x05,
     346,   30,   30,   30, 0x05,
     388,   30,   30,   30, 0x05,
     434,  429,   30,   30, 0x05,
     467,  429,   30,   30, 0x05,
     504,  429,   30,   30, 0x05,
     538,   30,   30,   30, 0x05,
     560,  429,   30,   30, 0x05,

 // slots: signature, parameters, type, tag, flags
     602,   87,   30,   30, 0x08,
     649,   30,   30,   30, 0x08,
     680,   30,   30,   30, 0x08,
     728,  711,   30,   30, 0x08,
     795,   30,   30,   30, 0x08,
     833,  825,   30,   30, 0x08,
     870,  825,   30,   30, 0x08,
     907,  825,   30,   30, 0x08,
     948,  825,   30,   30, 0x08,
    1012,  999,   30,   30, 0x08,
    1072, 1065,   30,   30, 0x08,
    1109, 1065,   30,   30, 0x08,
    1148,   30,   30,   30, 0x08,
    1178, 1065,   30,   30, 0x08,
    1216, 1065,   30,   30, 0x08,
    1256,   30,   30,   30, 0x08,
    1290,   30,   30,   30, 0x08,
    1318,   30,   30,   30, 0x08,
    1350, 1065,   30,   30, 0x08,
    1391,   30,   30,   30, 0x08,
    1427,   30,   30,   30, 0x08,
    1463,   30,   30,   30, 0x08,
    1503,   30,   30,   30, 0x08,
    1542, 1538,   30,   30, 0x08,
    1573, 1538,   30,   30, 0x08,
    1604,   30,   30,   30, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rqt_rover_gui__RoverGUIPlugin[] = {
    "rqt_rover_gui::RoverGUIPlugin\0\0"
    "sendInfoLogMessage(QString)\0"
    "sendDiagLogMessage(QString)\0,,\0"
    "sendDiagsDataUpdate(QString,QString,QColor)\0"
    "joystickDriveForwardUpdate(double)\0"
    "joystickDriveBackwardUpdate(double)\0"
    "joystickDriveLeftUpdate(double)\0"
    "joystickDriveRightUpdate(double)\0"
    "joystickGripperWristUpUpdate(double)\0"
    "joystickGripperWristDownUpdate(double)\0"
    "joystickGripperFingersCloseUpdate(double)\0"
    "joystickGripperFingersOpenUpdate(double)\0"
    "text\0updateObstacleCallCount(QString)\0"
    "updateNumberOfTagsCollected(QString)\0"
    "updateNumberOfSatellites(QString)\0"
    "allStopButtonSignal()\0"
    "updateCurrentSimulationTimeLabel(QString)\0"
    "receiveDiagsDataUpdate(QString,QString,QColor)\0"
    "receiveInfoLogMessage(QString)\0"
    "receiveDiagLogMessage(QString)\0"
    "current,previous\0"
    "currentRoverChangedEventHandler(QListWidgetItem*,QListWidgetItem*)\0"
    "pollRoversTimerEventHandler()\0checked\0"
    "GPSCheckboxToggledEventHandler(bool)\0"
    "EKFCheckboxToggledEventHandler(bool)\0"
    "encoderCheckboxToggledEventHandler(bool)\0"
    "overrideNumRoversCheckboxToggledEventHandler(bool)\0"
    "changed_item\0"
    "mapSelectionListItemChangedHandler(QListWidgetItem*)\0"
    "marked\0mapAutoRadioButtonEventHandler(bool)\0"
    "mapManualRadioButtonEventHandler(bool)\0"
    "mapPopoutButtonEventHandler()\0"
    "joystickRadioButtonEventHandler(bool)\0"
    "autonomousRadioButtonEventHandler(bool)\0"
    "allAutonomousButtonEventHandler()\0"
    "allStopButtonEventHandler()\0"
    "customWorldButtonEventHandler()\0"
    "customWorldRadioButtonEventHandler(bool)\0"
    "buildSimulationButtonEventHandler()\0"
    "clearSimulationButtonEventHandler()\0"
    "visualizeSimulationButtonEventHandler()\0"
    "gazeboServerFinishedEventHandler()\0"
    "msg\0displayInfoLogMessage(QString)\0"
    "displayDiagLogMessage(QString)\0"
    "refocusKeyboardEventHandler()\0"
};

void rqt_rover_gui::RoverGUIPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RoverGUIPlugin *_t = static_cast<RoverGUIPlugin *>(_o);
        switch (_id) {
        case 0: _t->sendInfoLogMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendDiagLogMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sendDiagsDataUpdate((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QColor(*)>(_a[3]))); break;
        case 3: _t->joystickDriveForwardUpdate((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->joystickDriveBackwardUpdate((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->joystickDriveLeftUpdate((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->joystickDriveRightUpdate((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->joystickGripperWristUpUpdate((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->joystickGripperWristDownUpdate((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->joystickGripperFingersCloseUpdate((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->joystickGripperFingersOpenUpdate((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->updateObstacleCallCount((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->updateNumberOfTagsCollected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->updateNumberOfSatellites((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->allStopButtonSignal(); break;
        case 15: _t->updateCurrentSimulationTimeLabel((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->receiveDiagsDataUpdate((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QColor(*)>(_a[3]))); break;
        case 17: _t->receiveInfoLogMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: _t->receiveDiagLogMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: _t->currentRoverChangedEventHandler((*reinterpret_cast< QListWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2]))); break;
        case 20: _t->pollRoversTimerEventHandler(); break;
        case 21: _t->GPSCheckboxToggledEventHandler((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->EKFCheckboxToggledEventHandler((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->encoderCheckboxToggledEventHandler((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: _t->overrideNumRoversCheckboxToggledEventHandler((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->mapSelectionListItemChangedHandler((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 26: _t->mapAutoRadioButtonEventHandler((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: _t->mapManualRadioButtonEventHandler((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 28: _t->mapPopoutButtonEventHandler(); break;
        case 29: _t->joystickRadioButtonEventHandler((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: _t->autonomousRadioButtonEventHandler((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 31: _t->allAutonomousButtonEventHandler(); break;
        case 32: _t->allStopButtonEventHandler(); break;
        case 33: _t->customWorldButtonEventHandler(); break;
        case 34: _t->customWorldRadioButtonEventHandler((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 35: _t->buildSimulationButtonEventHandler(); break;
        case 36: _t->clearSimulationButtonEventHandler(); break;
        case 37: _t->visualizeSimulationButtonEventHandler(); break;
        case 38: _t->gazeboServerFinishedEventHandler(); break;
        case 39: _t->displayInfoLogMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 40: _t->displayDiagLogMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 41: _t->refocusKeyboardEventHandler(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData rqt_rover_gui::RoverGUIPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rqt_rover_gui::RoverGUIPlugin::staticMetaObject = {
    { &rqt_gui_cpp::Plugin::staticMetaObject, qt_meta_stringdata_rqt_rover_gui__RoverGUIPlugin,
      qt_meta_data_rqt_rover_gui__RoverGUIPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rqt_rover_gui::RoverGUIPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rqt_rover_gui::RoverGUIPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rqt_rover_gui::RoverGUIPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rqt_rover_gui__RoverGUIPlugin))
        return static_cast<void*>(const_cast< RoverGUIPlugin*>(this));
    typedef rqt_gui_cpp::Plugin QMocSuperClass;
    return QMocSuperClass::qt_metacast(_clname);
}

int rqt_rover_gui::RoverGUIPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    typedef rqt_gui_cpp::Plugin QMocSuperClass;
    _id = QMocSuperClass::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 42)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 42;
    }
    return _id;
}

// SIGNAL 0
void rqt_rover_gui::RoverGUIPlugin::sendInfoLogMessage(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void rqt_rover_gui::RoverGUIPlugin::sendDiagLogMessage(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void rqt_rover_gui::RoverGUIPlugin::sendDiagsDataUpdate(QString _t1, QString _t2, QColor _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void rqt_rover_gui::RoverGUIPlugin::joystickDriveForwardUpdate(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void rqt_rover_gui::RoverGUIPlugin::joystickDriveBackwardUpdate(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void rqt_rover_gui::RoverGUIPlugin::joystickDriveLeftUpdate(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void rqt_rover_gui::RoverGUIPlugin::joystickDriveRightUpdate(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void rqt_rover_gui::RoverGUIPlugin::joystickGripperWristUpUpdate(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void rqt_rover_gui::RoverGUIPlugin::joystickGripperWristDownUpdate(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void rqt_rover_gui::RoverGUIPlugin::joystickGripperFingersCloseUpdate(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void rqt_rover_gui::RoverGUIPlugin::joystickGripperFingersOpenUpdate(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void rqt_rover_gui::RoverGUIPlugin::updateObstacleCallCount(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void rqt_rover_gui::RoverGUIPlugin::updateNumberOfTagsCollected(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void rqt_rover_gui::RoverGUIPlugin::updateNumberOfSatellites(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void rqt_rover_gui::RoverGUIPlugin::allStopButtonSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 14, 0);
}

// SIGNAL 15
void rqt_rover_gui::RoverGUIPlugin::updateCurrentSimulationTimeLabel(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}
QT_END_MOC_NAMESPACE
