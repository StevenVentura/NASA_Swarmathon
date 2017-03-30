; Auto-generated. Do not edit!


(cl:in-package ublox_msgs-msg)


;//! \htmlinclude MonVER.msg.html

(cl:defclass <MonVER> (roslisp-msg-protocol:ros-message)
  ((swVersion
    :reader swVersion
    :initarg :swVersion
    :type (cl:vector cl:integer)
   :initform (cl:make-array 30 :element-type 'cl:integer :initial-element 0))
   (hwVersion
    :reader hwVersion
    :initarg :hwVersion
    :type (cl:vector cl:integer)
   :initform (cl:make-array 10 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass MonVER (<MonVER>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MonVER>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MonVER)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ublox_msgs-msg:<MonVER> is deprecated: use ublox_msgs-msg:MonVER instead.")))

(cl:ensure-generic-function 'swVersion-val :lambda-list '(m))
(cl:defmethod swVersion-val ((m <MonVER>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:swVersion-val is deprecated.  Use ublox_msgs-msg:swVersion instead.")
  (swVersion m))

(cl:ensure-generic-function 'hwVersion-val :lambda-list '(m))
(cl:defmethod hwVersion-val ((m <MonVER>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:hwVersion-val is deprecated.  Use ublox_msgs-msg:hwVersion instead.")
  (hwVersion m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<MonVER>)))
    "Constants for message type '<MonVER>"
  '((:CLASS_ID . 10)
    (:MESSAGE_ID . 4))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'MonVER)))
    "Constants for message type 'MonVER"
  '((:CLASS_ID . 10)
    (:MESSAGE_ID . 4))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MonVER>) ostream)
  "Serializes a message object of type '<MonVER>"
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'swVersion))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'hwVersion))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MonVER>) istream)
  "Deserializes a message object of type '<MonVER>"
  (cl:setf (cl:slot-value msg 'swVersion) (cl:make-array 30))
  (cl:let ((vals (cl:slot-value msg 'swVersion)))
    (cl:dotimes (i 30)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream))))
  (cl:setf (cl:slot-value msg 'hwVersion) (cl:make-array 10))
  (cl:let ((vals (cl:slot-value msg 'hwVersion)))
    (cl:dotimes (i 10)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MonVER>)))
  "Returns string type for a message object of type '<MonVER>"
  "ublox_msgs/MonVER")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MonVER)))
  "Returns string type for a message object of type 'MonVER"
  "ublox_msgs/MonVER")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MonVER>)))
  "Returns md5sum for a message object of type '<MonVER>"
  "89732a19b51c49be31e36fb80481a8d4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MonVER)))
  "Returns md5sum for a message object of type 'MonVER"
  "89732a19b51c49be31e36fb80481a8d4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MonVER>)))
  "Returns full string definition for message of type '<MonVER>"
  (cl:format cl:nil "# MON-VER (0xB5 0x62)~%# Receiver/Software Version~%# Returned when the version is polled.~%~%uint8 CLASS_ID = 10~%uint8 MESSAGE_ID = 4~%~%char[30] swVersion    # Zero-terminated software version string.~%char[10] hwVersion    # Zero-terminated hardware version string.~%~%# TODO: Implement support for dynamic char[] array in serializer.~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MonVER)))
  "Returns full string definition for message of type 'MonVER"
  (cl:format cl:nil "# MON-VER (0xB5 0x62)~%# Receiver/Software Version~%# Returned when the version is polled.~%~%uint8 CLASS_ID = 10~%uint8 MESSAGE_ID = 4~%~%char[30] swVersion    # Zero-terminated software version string.~%char[10] hwVersion    # Zero-terminated hardware version string.~%~%# TODO: Implement support for dynamic char[] array in serializer.~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MonVER>))
  (cl:+ 0
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'swVersion) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'hwVersion) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MonVER>))
  "Converts a ROS message object to a list"
  (cl:list 'MonVER
    (cl:cons ':swVersion (swVersion msg))
    (cl:cons ':hwVersion (hwVersion msg))
))
