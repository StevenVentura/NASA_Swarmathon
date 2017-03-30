; Auto-generated. Do not edit!


(cl:in-package ublox_msgs-msg)


;//! \htmlinclude CfgGNSS.msg.html

(cl:defclass <CfgGNSS> (roslisp-msg-protocol:ros-message)
  ((msgVer
    :reader msgVer
    :initarg :msgVer
    :type cl:fixnum
    :initform 0)
   (numTrkChHw
    :reader numTrkChHw
    :initarg :numTrkChHw
    :type cl:fixnum
    :initform 0)
   (numTrkChUse
    :reader numTrkChUse
    :initarg :numTrkChUse
    :type cl:fixnum
    :initform 0)
   (numConfigBlocks
    :reader numConfigBlocks
    :initarg :numConfigBlocks
    :type cl:fixnum
    :initform 0)
   (gnssId
    :reader gnssId
    :initarg :gnssId
    :type cl:fixnum
    :initform 0)
   (resTrkCh
    :reader resTrkCh
    :initarg :resTrkCh
    :type cl:fixnum
    :initform 0)
   (maxTrkCh
    :reader maxTrkCh
    :initarg :maxTrkCh
    :type cl:fixnum
    :initform 0)
   (reserved1
    :reader reserved1
    :initarg :reserved1
    :type cl:fixnum
    :initform 0)
   (flags
    :reader flags
    :initarg :flags
    :type cl:integer
    :initform 0))
)

(cl:defclass CfgGNSS (<CfgGNSS>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <CfgGNSS>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'CfgGNSS)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ublox_msgs-msg:<CfgGNSS> is deprecated: use ublox_msgs-msg:CfgGNSS instead.")))

(cl:ensure-generic-function 'msgVer-val :lambda-list '(m))
(cl:defmethod msgVer-val ((m <CfgGNSS>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:msgVer-val is deprecated.  Use ublox_msgs-msg:msgVer instead.")
  (msgVer m))

(cl:ensure-generic-function 'numTrkChHw-val :lambda-list '(m))
(cl:defmethod numTrkChHw-val ((m <CfgGNSS>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:numTrkChHw-val is deprecated.  Use ublox_msgs-msg:numTrkChHw instead.")
  (numTrkChHw m))

(cl:ensure-generic-function 'numTrkChUse-val :lambda-list '(m))
(cl:defmethod numTrkChUse-val ((m <CfgGNSS>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:numTrkChUse-val is deprecated.  Use ublox_msgs-msg:numTrkChUse instead.")
  (numTrkChUse m))

(cl:ensure-generic-function 'numConfigBlocks-val :lambda-list '(m))
(cl:defmethod numConfigBlocks-val ((m <CfgGNSS>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:numConfigBlocks-val is deprecated.  Use ublox_msgs-msg:numConfigBlocks instead.")
  (numConfigBlocks m))

(cl:ensure-generic-function 'gnssId-val :lambda-list '(m))
(cl:defmethod gnssId-val ((m <CfgGNSS>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:gnssId-val is deprecated.  Use ublox_msgs-msg:gnssId instead.")
  (gnssId m))

(cl:ensure-generic-function 'resTrkCh-val :lambda-list '(m))
(cl:defmethod resTrkCh-val ((m <CfgGNSS>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:resTrkCh-val is deprecated.  Use ublox_msgs-msg:resTrkCh instead.")
  (resTrkCh m))

(cl:ensure-generic-function 'maxTrkCh-val :lambda-list '(m))
(cl:defmethod maxTrkCh-val ((m <CfgGNSS>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:maxTrkCh-val is deprecated.  Use ublox_msgs-msg:maxTrkCh instead.")
  (maxTrkCh m))

(cl:ensure-generic-function 'reserved1-val :lambda-list '(m))
(cl:defmethod reserved1-val ((m <CfgGNSS>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:reserved1-val is deprecated.  Use ublox_msgs-msg:reserved1 instead.")
  (reserved1 m))

(cl:ensure-generic-function 'flags-val :lambda-list '(m))
(cl:defmethod flags-val ((m <CfgGNSS>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:flags-val is deprecated.  Use ublox_msgs-msg:flags instead.")
  (flags m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<CfgGNSS>)))
    "Constants for message type '<CfgGNSS>"
  '((:CLASS_ID . 6)
    (:MESSAGE_ID . 62)
    (:GNSS_ID_GPS . 0)
    (:GNSS_ID_SBAS . 1)
    (:GNSS_ID_GALILEO . 2)
    (:GNSS_ID_BEIDOU . 3)
    (:GNSS_ID_QZSS . 5)
    (:GNSS_ID_GLONASS . 6))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'CfgGNSS)))
    "Constants for message type 'CfgGNSS"
  '((:CLASS_ID . 6)
    (:MESSAGE_ID . 62)
    (:GNSS_ID_GPS . 0)
    (:GNSS_ID_SBAS . 1)
    (:GNSS_ID_GALILEO . 2)
    (:GNSS_ID_BEIDOU . 3)
    (:GNSS_ID_QZSS . 5)
    (:GNSS_ID_GLONASS . 6))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <CfgGNSS>) ostream)
  "Serializes a message object of type '<CfgGNSS>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'msgVer)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'numTrkChHw)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'numTrkChUse)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'numConfigBlocks)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'gnssId)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'resTrkCh)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'maxTrkCh)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved1)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'flags)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'flags)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'flags)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'flags)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <CfgGNSS>) istream)
  "Deserializes a message object of type '<CfgGNSS>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'msgVer)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'numTrkChHw)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'numTrkChUse)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'numConfigBlocks)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'gnssId)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'resTrkCh)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'maxTrkCh)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved1)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'flags)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'flags)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'flags)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'flags)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<CfgGNSS>)))
  "Returns string type for a message object of type '<CfgGNSS>"
  "ublox_msgs/CfgGNSS")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'CfgGNSS)))
  "Returns string type for a message object of type 'CfgGNSS"
  "ublox_msgs/CfgGNSS")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<CfgGNSS>)))
  "Returns md5sum for a message object of type '<CfgGNSS>"
  "b7f92af0b44aa7c047fd14c5926fb0fc")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'CfgGNSS)))
  "Returns md5sum for a message object of type 'CfgGNSS"
  "b7f92af0b44aa7c047fd14c5926fb0fc")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<CfgGNSS>)))
  "Returns full string definition for message of type '<CfgGNSS>"
  (cl:format cl:nil "# CFG-GNSS (0x06 0x3E)~%# GNSS Configuration~%# Gets or sets the GNSS system channel sharing configuration.~%~%uint8 CLASS_ID = 6~%uint8 MESSAGE_ID = 62~%~%uint8 msgVer            # Message version (= 0 for this version)~%uint8 numTrkChHw        # Number of tracking channels in hardware (read only)~%uint8 numTrkChUse       # Number of tracking channels to use (<= numTrkChHw)~%uint8 numConfigBlocks   # Number of configuration blocks following (set to 1)~%~%uint8 gnssId            # GNSS identifier (select from following list)~%~%uint8 GNSS_ID_GPS = 0~%uint8 GNSS_ID_SBAS = 1~%uint8 GNSS_ID_GALILEO = 2~%uint8 GNSS_ID_BEIDOU = 3~%uint8 GNSS_ID_QZSS = 5~%uint8 GNSS_ID_GLONASS = 6~%~%uint8 resTrkCh          # Number of reserved (minimum) tracking channels for this GNSS system~%uint8 maxTrkCh          # Maximum number of tracking channels (>=resTrkChn)~%uint8 reserved1         # Reserved~%uint32 flags            # Bitfield of flags (bit 0 = enable/disable)~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'CfgGNSS)))
  "Returns full string definition for message of type 'CfgGNSS"
  (cl:format cl:nil "# CFG-GNSS (0x06 0x3E)~%# GNSS Configuration~%# Gets or sets the GNSS system channel sharing configuration.~%~%uint8 CLASS_ID = 6~%uint8 MESSAGE_ID = 62~%~%uint8 msgVer            # Message version (= 0 for this version)~%uint8 numTrkChHw        # Number of tracking channels in hardware (read only)~%uint8 numTrkChUse       # Number of tracking channels to use (<= numTrkChHw)~%uint8 numConfigBlocks   # Number of configuration blocks following (set to 1)~%~%uint8 gnssId            # GNSS identifier (select from following list)~%~%uint8 GNSS_ID_GPS = 0~%uint8 GNSS_ID_SBAS = 1~%uint8 GNSS_ID_GALILEO = 2~%uint8 GNSS_ID_BEIDOU = 3~%uint8 GNSS_ID_QZSS = 5~%uint8 GNSS_ID_GLONASS = 6~%~%uint8 resTrkCh          # Number of reserved (minimum) tracking channels for this GNSS system~%uint8 maxTrkCh          # Maximum number of tracking channels (>=resTrkChn)~%uint8 reserved1         # Reserved~%uint32 flags            # Bitfield of flags (bit 0 = enable/disable)~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <CfgGNSS>))
  (cl:+ 0
     1
     1
     1
     1
     1
     1
     1
     1
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <CfgGNSS>))
  "Converts a ROS message object to a list"
  (cl:list 'CfgGNSS
    (cl:cons ':msgVer (msgVer msg))
    (cl:cons ':numTrkChHw (numTrkChHw msg))
    (cl:cons ':numTrkChUse (numTrkChUse msg))
    (cl:cons ':numConfigBlocks (numConfigBlocks msg))
    (cl:cons ':gnssId (gnssId msg))
    (cl:cons ':resTrkCh (resTrkCh msg))
    (cl:cons ':maxTrkCh (maxTrkCh msg))
    (cl:cons ':reserved1 (reserved1 msg))
    (cl:cons ':flags (flags msg))
))
