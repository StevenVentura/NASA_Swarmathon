// Generated by gencpp from file ublox_msgs/RxmRAW_SV.msg
// DO NOT EDIT!


#ifndef UBLOX_MSGS_MESSAGE_RXMRAW_SV_H
#define UBLOX_MSGS_MESSAGE_RXMRAW_SV_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace ublox_msgs
{
template <class ContainerAllocator>
struct RxmRAW_SV_
{
  typedef RxmRAW_SV_<ContainerAllocator> Type;

  RxmRAW_SV_()
    : cpMes(0.0)
    , prMes(0.0)
    , doMes(0.0)
    , sv(0)
    , mesQI(0)
    , cno(0)
    , lli(0)  {
    }
  RxmRAW_SV_(const ContainerAllocator& _alloc)
    : cpMes(0.0)
    , prMes(0.0)
    , doMes(0.0)
    , sv(0)
    , mesQI(0)
    , cno(0)
    , lli(0)  {
  (void)_alloc;
    }



   typedef double _cpMes_type;
  _cpMes_type cpMes;

   typedef double _prMes_type;
  _prMes_type prMes;

   typedef float _doMes_type;
  _doMes_type doMes;

   typedef uint8_t _sv_type;
  _sv_type sv;

   typedef int8_t _mesQI_type;
  _mesQI_type mesQI;

   typedef int8_t _cno_type;
  _cno_type cno;

   typedef uint8_t _lli_type;
  _lli_type lli;




  typedef boost::shared_ptr< ::ublox_msgs::RxmRAW_SV_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ublox_msgs::RxmRAW_SV_<ContainerAllocator> const> ConstPtr;

}; // struct RxmRAW_SV_

typedef ::ublox_msgs::RxmRAW_SV_<std::allocator<void> > RxmRAW_SV;

typedef boost::shared_ptr< ::ublox_msgs::RxmRAW_SV > RxmRAW_SVPtr;
typedef boost::shared_ptr< ::ublox_msgs::RxmRAW_SV const> RxmRAW_SVConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ublox_msgs::RxmRAW_SV_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ublox_msgs::RxmRAW_SV_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace ublox_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'ublox_msgs': ['/home/steven/rover_workspace/src/ublox/ublox_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::ublox_msgs::RxmRAW_SV_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ublox_msgs::RxmRAW_SV_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ublox_msgs::RxmRAW_SV_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ublox_msgs::RxmRAW_SV_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ublox_msgs::RxmRAW_SV_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ublox_msgs::RxmRAW_SV_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ublox_msgs::RxmRAW_SV_<ContainerAllocator> >
{
  static const char* value()
  {
    return "4b32efd29577416a2c280e629abcb69a";
  }

  static const char* value(const ::ublox_msgs::RxmRAW_SV_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x4b32efd29577416aULL;
  static const uint64_t static_value2 = 0x2c280e629abcb69aULL;
};

template<class ContainerAllocator>
struct DataType< ::ublox_msgs::RxmRAW_SV_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ublox_msgs/RxmRAW_SV";
  }

  static const char* value(const ::ublox_msgs::RxmRAW_SV_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ublox_msgs::RxmRAW_SV_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# see message RxmRAW\n\
#\n\
\n\
float64 cpMes             # Carrier phase measurement [L1 cycles]\n\
float64 prMes             # Pseudorange measurement [m]\n\
float32 doMes             # Doppler measurement [Hz]\n\
\n\
uint8 sv                  # Space Vehicle Number\n\
int8 mesQI                # Nav Measurements Quality Indicator\n\
                          #  >=4 : PR+DO OK\n\
                          #  >=5 : PR+DO+CP OK\n\
                          #  <6 : likely loss of carrier lock in previous interval\n\
int8 cno                  # Signal strength C/No. [dbHz]\n\
uint8 lli                 # Loss of lock indicator (RINEX definition)\n\
";
  }

  static const char* value(const ::ublox_msgs::RxmRAW_SV_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ublox_msgs::RxmRAW_SV_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.cpMes);
      stream.next(m.prMes);
      stream.next(m.doMes);
      stream.next(m.sv);
      stream.next(m.mesQI);
      stream.next(m.cno);
      stream.next(m.lli);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RxmRAW_SV_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ublox_msgs::RxmRAW_SV_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ublox_msgs::RxmRAW_SV_<ContainerAllocator>& v)
  {
    s << indent << "cpMes: ";
    Printer<double>::stream(s, indent + "  ", v.cpMes);
    s << indent << "prMes: ";
    Printer<double>::stream(s, indent + "  ", v.prMes);
    s << indent << "doMes: ";
    Printer<float>::stream(s, indent + "  ", v.doMes);
    s << indent << "sv: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.sv);
    s << indent << "mesQI: ";
    Printer<int8_t>::stream(s, indent + "  ", v.mesQI);
    s << indent << "cno: ";
    Printer<int8_t>::stream(s, indent + "  ", v.cno);
    s << indent << "lli: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.lli);
  }
};

} // namespace message_operations
} // namespace ros

#endif // UBLOX_MSGS_MESSAGE_RXMRAW_SV_H
