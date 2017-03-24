; Auto-generated. Do not edit!


(cl:in-package ublox_msgs-msg)


;//! \htmlinclude CfgPRT.msg.html

(cl:defclass <CfgPRT> (roslisp-msg-protocol:ros-message)
  ((portID
    :reader portID
    :initarg :portID
    :type cl:fixnum
    :initform 0)
   (reserved0
    :reader reserved0
    :initarg :reserved0
    :type cl:fixnum
    :initform 0)
   (txReady
    :reader txReady
    :initarg :txReady
    :type cl:fixnum
    :initform 0)
   (mode
    :reader mode
    :initarg :mode
    :type cl:integer
    :initform 0)
   (baudRate
    :reader baudRate
    :initarg :baudRate
    :type cl:integer
    :initform 0)
   (inProtoMask
    :reader inProtoMask
    :initarg :inProtoMask
    :type cl:fixnum
    :initform 0)
   (outProtoMask
    :reader outProtoMask
    :initarg :outProtoMask
    :type cl:fixnum
    :initform 0)
   (reserved4
    :reader reserved4
    :initarg :reserved4
    :type cl:fixnum
    :initform 0)
   (reserved5
    :reader reserved5
    :initarg :reserved5
    :type cl:fixnum
    :initform 0))
)

(cl:defclass CfgPRT (<CfgPRT>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <CfgPRT>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'CfgPRT)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ublox_msgs-msg:<CfgPRT> is deprecated: use ublox_msgs-msg:CfgPRT instead.")))

(cl:ensure-generic-function 'portID-val :lambda-list '(m))
(cl:defmethod portID-val ((m <CfgPRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:portID-val is deprecated.  Use ublox_msgs-msg:portID instead.")
  (portID m))

(cl:ensure-generic-function 'reserved0-val :lambda-list '(m))
(cl:defmethod reserved0-val ((m <CfgPRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:reserved0-val is deprecated.  Use ublox_msgs-msg:reserved0 instead.")
  (reserved0 m))

(cl:ensure-generic-function 'txReady-val :lambda-list '(m))
(cl:defmethod txReady-val ((m <CfgPRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:txReady-val is deprecated.  Use ublox_msgs-msg:txReady instead.")
  (txReady m))

(cl:ensure-generic-function 'mode-val :lambda-list '(m))
(cl:defmethod mode-val ((m <CfgPRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:mode-val is deprecated.  Use ublox_msgs-msg:mode instead.")
  (mode m))

(cl:ensure-generic-function 'baudRate-val :lambda-list '(m))
(cl:defmethod baudRate-val ((m <CfgPRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:baudRate-val is deprecated.  Use ublox_msgs-msg:baudRate instead.")
  (baudRate m))

(cl:ensure-generic-function 'inProtoMask-val :lambda-list '(m))
(cl:defmethod inProtoMask-val ((m <CfgPRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:inProtoMask-val is deprecated.  Use ublox_msgs-msg:inProtoMask instead.")
  (inProtoMask m))

(cl:ensure-generic-function 'outProtoMask-val :lambda-list '(m))
(cl:defmethod outProtoMask-val ((m <CfgPRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:outProtoMask-val is deprecated.  Use ublox_msgs-msg:outProtoMask instead.")
  (outProtoMask m))

(cl:ensure-generic-function 'reserved4-val :lambda-list '(m))
(cl:defmethod reserved4-val ((m <CfgPRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:reserved4-val is deprecated.  Use ublox_msgs-msg:reserved4 instead.")
  (reserved4 m))

(cl:ensure-generic-function 'reserved5-val :lambda-list '(m))
(cl:defmethod reserved5-val ((m <CfgPRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:reserved5-val is deprecated.  Use ublox_msgs-msg:reserved5 instead.")
  (reserved5 m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<CfgPRT>)))
    "Constants for message type '<CfgPRT>"
  '((:CLASS_ID . 6)
    (:MESSAGE_ID . 0)
    (:PORT_ID_UART1 . 1)
    (:PORT_ID_UART2 . 2)
    (:PORT_ID_USB . 3)
    (:TX_READY_EN . 1)
    (:TX_READY_POLARITY_HIGH_ACTIVE . 0)
    (:TX_READY_POLARITY_LOW_ACTIVE . 2)
    (:TX_READY_PIN_SHIFT . 2)
    (:TX_READY_PIN_MASK . 124)
    (:TX_READY_THRES_SHIFT . 7)
    (:TX_READY_THRES_MASK . 65408)
    (:MODE_RESERVED1 . 16)
    (:MODE_CHAR_LEN_MASK . 192)
    (:MODE_CHAR_LEN_5BIT . 0)
    (:MODE_CHAR_LEN_6BIT . 64)
    (:MODE_CHAR_LEN_7BIT . 128)
    (:MODE_CHAR_LEN_8BIT . 192)
    (:MODE_PARITY_MASK . 3584)
    (:MODE_PARITY_EVEN . 0)
    (:MODE_PARITY_ODD . 512)
    (:MODE_PARITY_NO . 2048)
    (:MODE_STOP_BITS_MASK . 12288)
    (:MODE_STOP_BITS_1 . 0)
    (:MODE_STOP_BITS_15 . 4096)
    (:MODE_STOP_BITS_2 . 8192)
    (:MODE_STOP_BITS_05 . 12288)
    (:PROTO_UBX . 1)
    (:PROTO_NMEA . 2)
    (:PROTO_RTCM . 4))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'CfgPRT)))
    "Constants for message type 'CfgPRT"
  '((:CLASS_ID . 6)
    (:MESSAGE_ID . 0)
    (:PORT_ID_UART1 . 1)
    (:PORT_ID_UART2 . 2)
    (:PORT_ID_USB . 3)
    (:TX_READY_EN . 1)
    (:TX_READY_POLARITY_HIGH_ACTIVE . 0)
    (:TX_READY_POLARITY_LOW_ACTIVE . 2)
    (:TX_READY_PIN_SHIFT . 2)
    (:TX_READY_PIN_MASK . 124)
    (:TX_READY_THRES_SHIFT . 7)
    (:TX_READY_THRES_MASK . 65408)
    (:MODE_RESERVED1 . 16)
    (:MODE_CHAR_LEN_MASK . 192)
    (:MODE_CHAR_LEN_5BIT . 0)
    (:MODE_CHAR_LEN_6BIT . 64)
    (:MODE_CHAR_LEN_7BIT . 128)
    (:MODE_CHAR_LEN_8BIT . 192)
    (:MODE_PARITY_MASK . 3584)
    (:MODE_PARITY_EVEN . 0)
    (:MODE_PARITY_ODD . 512)
    (:MODE_PARITY_NO . 2048)
    (:MODE_STOP_BITS_MASK . 12288)
    (:MODE_STOP_BITS_1 . 0)
    (:MODE_STOP_BITS_15 . 4096)
    (:MODE_STOP_BITS_2 . 8192)
    (:MODE_STOP_BITS_05 . 12288)
    (:PROTO_UBX . 1)
    (:PROTO_NMEA . 2)
    (:PROTO_RTCM . 4))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <CfgPRT>) ostream)
  "Serializes a message object of type '<CfgPRT>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'portID)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'txReady)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'txReady)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'mode)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'mode)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'mode)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'mode)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'baudRate)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'baudRate)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'baudRate)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'baudRate)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'inProtoMask)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'inProtoMask)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'outProtoMask)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'outProtoMask)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved4)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'reserved4)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved5)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'reserved5)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <CfgPRT>) istream)
  "Deserializes a message object of type '<CfgPRT>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'portID)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved0)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'txReady)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'txReady)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'mode)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'mode)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'mode)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'mode)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'baudRate)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'baudRate)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'baudRate)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'baudRate)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'inProtoMask)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'inProtoMask)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'outProtoMask)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'outProtoMask)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved4)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'reserved4)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved5)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'reserved5)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<CfgPRT>)))
  "Returns string type for a message object of type '<CfgPRT>"
  "ublox_msgs/CfgPRT")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'CfgPRT)))
  "Returns string type for a message object of type 'CfgPRT"
  "ublox_msgs/CfgPRT")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<CfgPRT>)))
  "Returns md5sum for a message object of type '<CfgPRT>"
  "3679d3ad278d5329fb8543226a55acca")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'CfgPRT)))
  "Returns md5sum for a message object of type 'CfgPRT"
  "3679d3ad278d5329fb8543226a55acca")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<CfgPRT>)))
  "Returns full string definition for message of type '<CfgPRT>"
  (cl:format cl:nil "# CFG-PRT (0x06 0x00)~%# Port Configuration for UART~%#~%# Several configurations can be concatenated to one input message. In this case the payload~%# length can be a multiple of the normal length (see the other versions of CFG-PRT). Output~%# messages from the module contain only one configuration unit.~%#~%~%uint8 CLASS_ID = 6~%uint8 MESSAGE_ID = 0~%~%uint8 portID              # Port Identifier Number (= 1 or 2 for UART ports)~%uint8 PORT_ID_UART1 = 1~%uint8 PORT_ID_UART2 = 2~%uint8 PORT_ID_USB = 3~%~%uint8 reserved0           # Reserved~%~%uint16 txReady            # reserved (Alwyas set to zero) up to Firmware 7.01,~%                          # TX ready PIN configuration (since Firmware 7.01)~%uint16 TX_READY_EN = 1                    # Enable TX ready feature for this port~%uint16 TX_READY_POLARITY_HIGH_ACTIVE = 0  # Polarity High-active~%uint16 TX_READY_POLARITY_LOW_ACTIVE = 2   # Polarity Low-active~%uint16 TX_READY_PIN_SHIFT = 2             # PIO to be used (must not be in use already by another function)~%uint16 TX_READY_PIN_MASK = 124            #~%uint16 TX_READY_THRES_SHIFT = 7           # Threshold~%uint16 TX_READY_THRES_MASK = 65408        # The given threshold is multiplied by 8 bytes.~%                                          # The TX ready PIN goes active after >= thres*8 bytes are pending for the port and going inactive after the last~%                                          # pending bytes have been written to hardware (0-4 bytes before end of stream).~%~%uint32 mode               # A bit mask describing the UART mode~%uint32 MODE_RESERVED1 = 16                # Default 1 for compatibility with A4~%uint32 MODE_CHAR_LEN_MASK = 192           # Character Length~%uint32 MODE_CHAR_LEN_5BIT = 0               # 5bit (not supported)~%uint32 MODE_CHAR_LEN_6BIT = 64              # 6bit (not supported)~%uint32 MODE_CHAR_LEN_7BIT = 128             # 7bit (supported only with parity)~%uint32 MODE_CHAR_LEN_8BIT = 192             # 8bit~%uint32 MODE_PARITY_MASK = 3584            #~%uint32 MODE_PARITY_EVEN = 0                 # Even Parity~%uint32 MODE_PARITY_ODD = 512                # Odd Parity~%uint32 MODE_PARITY_NO = 2048                # No Parity~%uint32 MODE_STOP_BITS_MASK = 12288        # Number of Stop Bits~%uint32 MODE_STOP_BITS_1 = 0                 # 1 Stop Bit~%uint32 MODE_STOP_BITS_15 = 4096             # 1.5 Stop Bit~%uint32 MODE_STOP_BITS_2 = 8192              # 2 Stop Bit~%uint32 MODE_STOP_BITS_05 = 12288            # 0.5 Stop Bit~%~%uint32 baudRate           # Baudrate in bits/second [bits/s]~%~%uint16 inProtoMask        # A mask describing which input protocols are active.~%                          # Each bit of this mask is used for a protocol.~%                          # Through that, multiple protocols can be defined~%                          # on a single port.~%~%uint16 outProtoMask       # A mask describing which output protocols are active.~%                          # Each bit of this mask is used for a protocol.~%                          # Through that, multiple protocols can be defined~%                          # on a single port.~%~%uint16 PROTO_UBX = 1~%uint16 PROTO_NMEA = 2~%uint16 PROTO_RTCM = 4~%~%uint16 reserved4          # Always set to zero~%uint16 reserved5          # Always set to zero~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'CfgPRT)))
  "Returns full string definition for message of type 'CfgPRT"
  (cl:format cl:nil "# CFG-PRT (0x06 0x00)~%# Port Configuration for UART~%#~%# Several configurations can be concatenated to one input message. In this case the payload~%# length can be a multiple of the normal length (see the other versions of CFG-PRT). Output~%# messages from the module contain only one configuration unit.~%#~%~%uint8 CLASS_ID = 6~%uint8 MESSAGE_ID = 0~%~%uint8 portID              # Port Identifier Number (= 1 or 2 for UART ports)~%uint8 PORT_ID_UART1 = 1~%uint8 PORT_ID_UART2 = 2~%uint8 PORT_ID_USB = 3~%~%uint8 reserved0           # Reserved~%~%uint16 txReady            # reserved (Alwyas set to zero) up to Firmware 7.01,~%                          # TX ready PIN configuration (since Firmware 7.01)~%uint16 TX_READY_EN = 1                    # Enable TX ready feature for this port~%uint16 TX_READY_POLARITY_HIGH_ACTIVE = 0  # Polarity High-active~%uint16 TX_READY_POLARITY_LOW_ACTIVE = 2   # Polarity Low-active~%uint16 TX_READY_PIN_SHIFT = 2             # PIO to be used (must not be in use already by another function)~%uint16 TX_READY_PIN_MASK = 124            #~%uint16 TX_READY_THRES_SHIFT = 7           # Threshold~%uint16 TX_READY_THRES_MASK = 65408        # The given threshold is multiplied by 8 bytes.~%                                          # The TX ready PIN goes active after >= thres*8 bytes are pending for the port and going inactive after the last~%                                          # pending bytes have been written to hardware (0-4 bytes before end of stream).~%~%uint32 mode               # A bit mask describing the UART mode~%uint32 MODE_RESERVED1 = 16                # Default 1 for compatibility with A4~%uint32 MODE_CHAR_LEN_MASK = 192           # Character Length~%uint32 MODE_CHAR_LEN_5BIT = 0               # 5bit (not supported)~%uint32 MODE_CHAR_LEN_6BIT = 64              # 6bit (not supported)~%uint32 MODE_CHAR_LEN_7BIT = 128             # 7bit (supported only with parity)~%uint32 MODE_CHAR_LEN_8BIT = 192             # 8bit~%uint32 MODE_PARITY_MASK = 3584            #~%uint32 MODE_PARITY_EVEN = 0                 # Even Parity~%uint32 MODE_PARITY_ODD = 512                # Odd Parity~%uint32 MODE_PARITY_NO = 2048                # No Parity~%uint32 MODE_STOP_BITS_MASK = 12288        # Number of Stop Bits~%uint32 MODE_STOP_BITS_1 = 0                 # 1 Stop Bit~%uint32 MODE_STOP_BITS_15 = 4096             # 1.5 Stop Bit~%uint32 MODE_STOP_BITS_2 = 8192              # 2 Stop Bit~%uint32 MODE_STOP_BITS_05 = 12288            # 0.5 Stop Bit~%~%uint32 baudRate           # Baudrate in bits/second [bits/s]~%~%uint16 inProtoMask        # A mask describing which input protocols are active.~%                          # Each bit of this mask is used for a protocol.~%                          # Through that, multiple protocols can be defined~%                          # on a single port.~%~%uint16 outProtoMask       # A mask describing which output protocols are active.~%                          # Each bit of this mask is used for a protocol.~%                          # Through that, multiple protocols can be defined~%                          # on a single port.~%~%uint16 PROTO_UBX = 1~%uint16 PROTO_NMEA = 2~%uint16 PROTO_RTCM = 4~%~%uint16 reserved4          # Always set to zero~%uint16 reserved5          # Always set to zero~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <CfgPRT>))
  (cl:+ 0
     1
     1
     2
     4
     4
     2
     2
     2
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <CfgPRT>))
  "Converts a ROS message object to a list"
  (cl:list 'CfgPRT
    (cl:cons ':portID (portID msg))
    (cl:cons ':reserved0 (reserved0 msg))
    (cl:cons ':txReady (txReady msg))
    (cl:cons ':mode (mode msg))
    (cl:cons ':baudRate (baudRate msg))
    (cl:cons ':inProtoMask (inProtoMask msg))
    (cl:cons ':outProtoMask (outProtoMask msg))
    (cl:cons ':reserved4 (reserved4 msg))
    (cl:cons ':reserved5 (reserved5 msg))
))
