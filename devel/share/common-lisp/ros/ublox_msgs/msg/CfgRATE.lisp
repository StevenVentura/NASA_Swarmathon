; Auto-generated. Do not edit!


(cl:in-package ublox_msgs-msg)


;//! \htmlinclude CfgRATE.msg.html

(cl:defclass <CfgRATE> (roslisp-msg-protocol:ros-message)
  ((measRate
    :reader measRate
    :initarg :measRate
    :type cl:fixnum
    :initform 0)
   (navRate
    :reader navRate
    :initarg :navRate
    :type cl:fixnum
    :initform 0)
   (timeRef
    :reader timeRef
    :initarg :timeRef
    :type cl:fixnum
    :initform 0))
)

(cl:defclass CfgRATE (<CfgRATE>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <CfgRATE>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'CfgRATE)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ublox_msgs-msg:<CfgRATE> is deprecated: use ublox_msgs-msg:CfgRATE instead.")))

(cl:ensure-generic-function 'measRate-val :lambda-list '(m))
(cl:defmethod measRate-val ((m <CfgRATE>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:measRate-val is deprecated.  Use ublox_msgs-msg:measRate instead.")
  (measRate m))

(cl:ensure-generic-function 'navRate-val :lambda-list '(m))
(cl:defmethod navRate-val ((m <CfgRATE>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:navRate-val is deprecated.  Use ublox_msgs-msg:navRate instead.")
  (navRate m))

(cl:ensure-generic-function 'timeRef-val :lambda-list '(m))
(cl:defmethod timeRef-val ((m <CfgRATE>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:timeRef-val is deprecated.  Use ublox_msgs-msg:timeRef instead.")
  (timeRef m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<CfgRATE>)))
    "Constants for message type '<CfgRATE>"
  '((:CLASS_ID . 6)
    (:MESSAGE_ID . 8)
    (:TIME_REF_UTC . 0)
    (:TIME_REF_GPS . 1))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'CfgRATE)))
    "Constants for message type 'CfgRATE"
  '((:CLASS_ID . 6)
    (:MESSAGE_ID . 8)
    (:TIME_REF_UTC . 0)
    (:TIME_REF_GPS . 1))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <CfgRATE>) ostream)
  "Serializes a message object of type '<CfgRATE>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'measRate)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'measRate)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'navRate)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'navRate)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'timeRef)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'timeRef)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <CfgRATE>) istream)
  "Deserializes a message object of type '<CfgRATE>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'measRate)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'measRate)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'navRate)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'navRate)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'timeRef)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'timeRef)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<CfgRATE>)))
  "Returns string type for a message object of type '<CfgRATE>"
  "ublox_msgs/CfgRATE")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'CfgRATE)))
  "Returns string type for a message object of type 'CfgRATE"
  "ublox_msgs/CfgRATE")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<CfgRATE>)))
  "Returns md5sum for a message object of type '<CfgRATE>"
  "da095554bde2600fd2a774def27fb48e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'CfgRATE)))
  "Returns md5sum for a message object of type 'CfgRATE"
  "da095554bde2600fd2a774def27fb48e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<CfgRATE>)))
  "Returns full string definition for message of type '<CfgRATE>"
  (cl:format cl:nil "# CFG-RATE (0x06 0x08)~%# Navigation/Measurement Rate Settings~%#~%~%uint8 CLASS_ID = 6~%uint8 MESSAGE_ID = 8~%~%uint16 measRate           # Measurement Rate, GPS measurements are~%                          # taken every measRate milliseconds [ms]~%uint16 navRate            # Navigation Rate, in number of measurement~%                          # cycles. On u-blox 5 and u-blox 6, this parameter~%                          # cannot be changed, and is always equals 1.~%uint16 timeRef            # Alignment to reference time: 0 = UTC time, 1 = GPS time~%uint16 TIME_REF_UTC = 0~%uint16 TIME_REF_GPS = 1~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'CfgRATE)))
  "Returns full string definition for message of type 'CfgRATE"
  (cl:format cl:nil "# CFG-RATE (0x06 0x08)~%# Navigation/Measurement Rate Settings~%#~%~%uint8 CLASS_ID = 6~%uint8 MESSAGE_ID = 8~%~%uint16 measRate           # Measurement Rate, GPS measurements are~%                          # taken every measRate milliseconds [ms]~%uint16 navRate            # Navigation Rate, in number of measurement~%                          # cycles. On u-blox 5 and u-blox 6, this parameter~%                          # cannot be changed, and is always equals 1.~%uint16 timeRef            # Alignment to reference time: 0 = UTC time, 1 = GPS time~%uint16 TIME_REF_UTC = 0~%uint16 TIME_REF_GPS = 1~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <CfgRATE>))
  (cl:+ 0
     2
     2
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <CfgRATE>))
  "Converts a ROS message object to a list"
  (cl:list 'CfgRATE
    (cl:cons ':measRate (measRate msg))
    (cl:cons ':navRate (navRate msg))
    (cl:cons ':timeRef (timeRef msg))
))
