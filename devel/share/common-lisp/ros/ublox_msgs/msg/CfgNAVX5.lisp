; Auto-generated. Do not edit!


(cl:in-package ublox_msgs-msg)


;//! \htmlinclude CfgNAVX5.msg.html

(cl:defclass <CfgNAVX5> (roslisp-msg-protocol:ros-message)
  ((version
    :reader version
    :initarg :version
    :type cl:fixnum
    :initform 0)
   (mask1
    :reader mask1
    :initarg :mask1
    :type cl:fixnum
    :initform 0)
   (reserved0
    :reader reserved0
    :initarg :reserved0
    :type cl:integer
    :initform 0)
   (reserved1
    :reader reserved1
    :initarg :reserved1
    :type cl:fixnum
    :initform 0)
   (reserved2
    :reader reserved2
    :initarg :reserved2
    :type cl:fixnum
    :initform 0)
   (minSVs
    :reader minSVs
    :initarg :minSVs
    :type cl:fixnum
    :initform 0)
   (maxSVs
    :reader maxSVs
    :initarg :maxSVs
    :type cl:fixnum
    :initform 0)
   (minCNO
    :reader minCNO
    :initarg :minCNO
    :type cl:fixnum
    :initform 0)
   (reserved5
    :reader reserved5
    :initarg :reserved5
    :type cl:fixnum
    :initform 0)
   (iniFix3D
    :reader iniFix3D
    :initarg :iniFix3D
    :type cl:fixnum
    :initform 0)
   (reserved6
    :reader reserved6
    :initarg :reserved6
    :type cl:fixnum
    :initform 0)
   (reserved7
    :reader reserved7
    :initarg :reserved7
    :type cl:fixnum
    :initform 0)
   (ackAiding
    :reader ackAiding
    :initarg :ackAiding
    :type cl:fixnum
    :initform 0)
   (wknRollover
    :reader wknRollover
    :initarg :wknRollover
    :type cl:fixnum
    :initform 0)
   (reserved8
    :reader reserved8
    :initarg :reserved8
    :type cl:integer
    :initform 0)
   (reserved9
    :reader reserved9
    :initarg :reserved9
    :type cl:fixnum
    :initform 0)
   (reserved10
    :reader reserved10
    :initarg :reserved10
    :type cl:fixnum
    :initform 0)
   (usePPP
    :reader usePPP
    :initarg :usePPP
    :type cl:fixnum
    :initform 0)
   (aopCfg
    :reader aopCfg
    :initarg :aopCfg
    :type cl:fixnum
    :initform 0)
   (reserved11
    :reader reserved11
    :initarg :reserved11
    :type cl:fixnum
    :initform 0)
   (reserved12
    :reader reserved12
    :initarg :reserved12
    :type cl:fixnum
    :initform 0)
   (aopOrbMaxErr
    :reader aopOrbMaxErr
    :initarg :aopOrbMaxErr
    :type cl:fixnum
    :initform 0)
   (reserved13
    :reader reserved13
    :initarg :reserved13
    :type cl:fixnum
    :initform 0)
   (reserved14
    :reader reserved14
    :initarg :reserved14
    :type cl:fixnum
    :initform 0)
   (reserved3
    :reader reserved3
    :initarg :reserved3
    :type cl:fixnum
    :initform 0)
   (reserved4
    :reader reserved4
    :initarg :reserved4
    :type cl:integer
    :initform 0))
)

(cl:defclass CfgNAVX5 (<CfgNAVX5>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <CfgNAVX5>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'CfgNAVX5)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ublox_msgs-msg:<CfgNAVX5> is deprecated: use ublox_msgs-msg:CfgNAVX5 instead.")))

(cl:ensure-generic-function 'version-val :lambda-list '(m))
(cl:defmethod version-val ((m <CfgNAVX5>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:version-val is deprecated.  Use ublox_msgs-msg:version instead.")
  (version m))

(cl:ensure-generic-function 'mask1-val :lambda-list '(m))
(cl:defmethod mask1-val ((m <CfgNAVX5>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:mask1-val is deprecated.  Use ublox_msgs-msg:mask1 instead.")
  (mask1 m))

(cl:ensure-generic-function 'reserved0-val :lambda-list '(m))
(cl:defmethod reserved0-val ((m <CfgNAVX5>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:reserved0-val is deprecated.  Use ublox_msgs-msg:reserved0 instead.")
  (reserved0 m))

(cl:ensure-generic-function 'reserved1-val :lambda-list '(m))
(cl:defmethod reserved1-val ((m <CfgNAVX5>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:reserved1-val is deprecated.  Use ublox_msgs-msg:reserved1 instead.")
  (reserved1 m))

(cl:ensure-generic-function 'reserved2-val :lambda-list '(m))
(cl:defmethod reserved2-val ((m <CfgNAVX5>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:reserved2-val is deprecated.  Use ublox_msgs-msg:reserved2 instead.")
  (reserved2 m))

(cl:ensure-generic-function 'minSVs-val :lambda-list '(m))
(cl:defmethod minSVs-val ((m <CfgNAVX5>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:minSVs-val is deprecated.  Use ublox_msgs-msg:minSVs instead.")
  (minSVs m))

(cl:ensure-generic-function 'maxSVs-val :lambda-list '(m))
(cl:defmethod maxSVs-val ((m <CfgNAVX5>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:maxSVs-val is deprecated.  Use ublox_msgs-msg:maxSVs instead.")
  (maxSVs m))

(cl:ensure-generic-function 'minCNO-val :lambda-list '(m))
(cl:defmethod minCNO-val ((m <CfgNAVX5>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:minCNO-val is deprecated.  Use ublox_msgs-msg:minCNO instead.")
  (minCNO m))

(cl:ensure-generic-function 'reserved5-val :lambda-list '(m))
(cl:defmethod reserved5-val ((m <CfgNAVX5>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:reserved5-val is deprecated.  Use ublox_msgs-msg:reserved5 instead.")
  (reserved5 m))

(cl:ensure-generic-function 'iniFix3D-val :lambda-list '(m))
(cl:defmethod iniFix3D-val ((m <CfgNAVX5>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:iniFix3D-val is deprecated.  Use ublox_msgs-msg:iniFix3D instead.")
  (iniFix3D m))

(cl:ensure-generic-function 'reserved6-val :lambda-list '(m))
(cl:defmethod reserved6-val ((m <CfgNAVX5>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:reserved6-val is deprecated.  Use ublox_msgs-msg:reserved6 instead.")
  (reserved6 m))

(cl:ensure-generic-function 'reserved7-val :lambda-list '(m))
(cl:defmethod reserved7-val ((m <CfgNAVX5>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:reserved7-val is deprecated.  Use ublox_msgs-msg:reserved7 instead.")
  (reserved7 m))

(cl:ensure-generic-function 'ackAiding-val :lambda-list '(m))
(cl:defmethod ackAiding-val ((m <CfgNAVX5>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:ackAiding-val is deprecated.  Use ublox_msgs-msg:ackAiding instead.")
  (ackAiding m))

(cl:ensure-generic-function 'wknRollover-val :lambda-list '(m))
(cl:defmethod wknRollover-val ((m <CfgNAVX5>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:wknRollover-val is deprecated.  Use ublox_msgs-msg:wknRollover instead.")
  (wknRollover m))

(cl:ensure-generic-function 'reserved8-val :lambda-list '(m))
(cl:defmethod reserved8-val ((m <CfgNAVX5>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:reserved8-val is deprecated.  Use ublox_msgs-msg:reserved8 instead.")
  (reserved8 m))

(cl:ensure-generic-function 'reserved9-val :lambda-list '(m))
(cl:defmethod reserved9-val ((m <CfgNAVX5>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:reserved9-val is deprecated.  Use ublox_msgs-msg:reserved9 instead.")
  (reserved9 m))

(cl:ensure-generic-function 'reserved10-val :lambda-list '(m))
(cl:defmethod reserved10-val ((m <CfgNAVX5>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:reserved10-val is deprecated.  Use ublox_msgs-msg:reserved10 instead.")
  (reserved10 m))

(cl:ensure-generic-function 'usePPP-val :lambda-list '(m))
(cl:defmethod usePPP-val ((m <CfgNAVX5>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:usePPP-val is deprecated.  Use ublox_msgs-msg:usePPP instead.")
  (usePPP m))

(cl:ensure-generic-function 'aopCfg-val :lambda-list '(m))
(cl:defmethod aopCfg-val ((m <CfgNAVX5>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:aopCfg-val is deprecated.  Use ublox_msgs-msg:aopCfg instead.")
  (aopCfg m))

(cl:ensure-generic-function 'reserved11-val :lambda-list '(m))
(cl:defmethod reserved11-val ((m <CfgNAVX5>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:reserved11-val is deprecated.  Use ublox_msgs-msg:reserved11 instead.")
  (reserved11 m))

(cl:ensure-generic-function 'reserved12-val :lambda-list '(m))
(cl:defmethod reserved12-val ((m <CfgNAVX5>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:reserved12-val is deprecated.  Use ublox_msgs-msg:reserved12 instead.")
  (reserved12 m))

(cl:ensure-generic-function 'aopOrbMaxErr-val :lambda-list '(m))
(cl:defmethod aopOrbMaxErr-val ((m <CfgNAVX5>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:aopOrbMaxErr-val is deprecated.  Use ublox_msgs-msg:aopOrbMaxErr instead.")
  (aopOrbMaxErr m))

(cl:ensure-generic-function 'reserved13-val :lambda-list '(m))
(cl:defmethod reserved13-val ((m <CfgNAVX5>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:reserved13-val is deprecated.  Use ublox_msgs-msg:reserved13 instead.")
  (reserved13 m))

(cl:ensure-generic-function 'reserved14-val :lambda-list '(m))
(cl:defmethod reserved14-val ((m <CfgNAVX5>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:reserved14-val is deprecated.  Use ublox_msgs-msg:reserved14 instead.")
  (reserved14 m))

(cl:ensure-generic-function 'reserved3-val :lambda-list '(m))
(cl:defmethod reserved3-val ((m <CfgNAVX5>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:reserved3-val is deprecated.  Use ublox_msgs-msg:reserved3 instead.")
  (reserved3 m))

(cl:ensure-generic-function 'reserved4-val :lambda-list '(m))
(cl:defmethod reserved4-val ((m <CfgNAVX5>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ublox_msgs-msg:reserved4-val is deprecated.  Use ublox_msgs-msg:reserved4 instead.")
  (reserved4 m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<CfgNAVX5>)))
    "Constants for message type '<CfgNAVX5>"
  '((:CLASS_ID . 6)
    (:MESSAGE_ID . 35)
    (:MASK_MIN_MAX . 4)
    (:MASK_MIN_CNO . 8)
    (:MASK_INITIAL_FIX_3D . 64)
    (:MASK_WKN_ROLL . 512)
    (:MASK_PPP . 8192)
    (:MASK_AOP . 16384))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'CfgNAVX5)))
    "Constants for message type 'CfgNAVX5"
  '((:CLASS_ID . 6)
    (:MESSAGE_ID . 35)
    (:MASK_MIN_MAX . 4)
    (:MASK_MIN_CNO . 8)
    (:MASK_INITIAL_FIX_3D . 64)
    (:MASK_WKN_ROLL . 512)
    (:MASK_PPP . 8192)
    (:MASK_AOP . 16384))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <CfgNAVX5>) ostream)
  "Serializes a message object of type '<CfgNAVX5>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'version)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'version)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'mask1)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'mask1)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'reserved0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'reserved0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'reserved0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved1)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved2)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'minSVs)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'maxSVs)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'minCNO)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved5)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'iniFix3D)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved6)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved7)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'ackAiding)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'wknRollover)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'wknRollover)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved8)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'reserved8)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'reserved8)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'reserved8)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved9)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved10)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'usePPP)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'aopCfg)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved11)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved12)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'aopOrbMaxErr)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'aopOrbMaxErr)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved13)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved14)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved3)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'reserved3)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved4)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'reserved4)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'reserved4)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'reserved4)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <CfgNAVX5>) istream)
  "Deserializes a message object of type '<CfgNAVX5>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'version)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'version)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'mask1)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'mask1)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved0)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'reserved0)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'reserved0)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'reserved0)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved1)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved2)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'minSVs)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'maxSVs)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'minCNO)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved5)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'iniFix3D)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved6)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved7)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'ackAiding)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'wknRollover)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'wknRollover)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved8)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'reserved8)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'reserved8)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'reserved8)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved9)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved10)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'usePPP)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'aopCfg)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved11)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved12)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'aopOrbMaxErr)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'aopOrbMaxErr)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved13)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved14)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved3)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'reserved3)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved4)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'reserved4)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'reserved4)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'reserved4)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<CfgNAVX5>)))
  "Returns string type for a message object of type '<CfgNAVX5>"
  "ublox_msgs/CfgNAVX5")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'CfgNAVX5)))
  "Returns string type for a message object of type 'CfgNAVX5"
  "ublox_msgs/CfgNAVX5")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<CfgNAVX5>)))
  "Returns md5sum for a message object of type '<CfgNAVX5>"
  "51508a96b05799aa4924b225bcb10fb3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'CfgNAVX5)))
  "Returns md5sum for a message object of type 'CfgNAVX5"
  "51508a96b05799aa4924b225bcb10fb3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<CfgNAVX5>)))
  "Returns full string definition for message of type '<CfgNAVX5>"
  (cl:format cl:nil "# CFG-NAVX5 (0x06 0x24)~%# Navigation Engine Expert Settings~%# Warning: Refer to u-blox protocol spec before changing these settings.~%~%uint8 CLASS_ID = 6~%uint8 MESSAGE_ID = 35~%~%uint16 version        # Message version (set to 0)~%~%uint16 mask1          # First parameters bitmask (possible values below)~%uint16 MASK_MIN_MAX        = 4~%uint16 MASK_MIN_CNO        = 8~%uint16 MASK_INITIAL_FIX_3D = 64~%uint16 MASK_WKN_ROLL       = 512~%uint16 MASK_PPP            = 8192~%uint16 MASK_AOP            = 16384~%~%uint32 reserved0      # Always set to zero~%uint8 reserved1       # Always set to zero~%uint8 reserved2       # Always set to zero~%~%uint8 minSVs          # Minimum number of satellites for navigation~%uint8 maxSVs          # Maximum number of satellites for navigation~%uint8 minCNO          # Minimum satellite signal level for navigation~%~%uint8 reserved5       # Always set to zero~%~%uint8 iniFix3D        # If set to 1, initial fix must be 3D~%~%uint8 reserved6       # Always set to zero~%uint8 reserved7       # Always set to zero~%~%uint8 ackAiding       # If set to 1, issue acknowledgements for assistance~%uint16 wknRollover    # GPS rollover number~%~%uint32 reserved8      # Always set to zero~%uint8 reserved9       # Always set to zero~%uint8 reserved10      # Always set to zero~%~%uint8 usePPP          # Enable/disable PPP (on supported units)~%uint8 aopCfg          # AssistNow Autonomous configuration~%~%uint8 reserved11      # Always set to zero~%uint8 reserved12      # Always set to zero~%~%uint16 aopOrbMaxErr   # Maximum acceptable (modelled) autonomous orbit error~%~%uint8 reserved13      # Always set to zero~%uint8 reserved14      # Always set to zero~%uint16 reserved3      # Always set to zero~%uint32 reserved4      # Always set to zero~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'CfgNAVX5)))
  "Returns full string definition for message of type 'CfgNAVX5"
  (cl:format cl:nil "# CFG-NAVX5 (0x06 0x24)~%# Navigation Engine Expert Settings~%# Warning: Refer to u-blox protocol spec before changing these settings.~%~%uint8 CLASS_ID = 6~%uint8 MESSAGE_ID = 35~%~%uint16 version        # Message version (set to 0)~%~%uint16 mask1          # First parameters bitmask (possible values below)~%uint16 MASK_MIN_MAX        = 4~%uint16 MASK_MIN_CNO        = 8~%uint16 MASK_INITIAL_FIX_3D = 64~%uint16 MASK_WKN_ROLL       = 512~%uint16 MASK_PPP            = 8192~%uint16 MASK_AOP            = 16384~%~%uint32 reserved0      # Always set to zero~%uint8 reserved1       # Always set to zero~%uint8 reserved2       # Always set to zero~%~%uint8 minSVs          # Minimum number of satellites for navigation~%uint8 maxSVs          # Maximum number of satellites for navigation~%uint8 minCNO          # Minimum satellite signal level for navigation~%~%uint8 reserved5       # Always set to zero~%~%uint8 iniFix3D        # If set to 1, initial fix must be 3D~%~%uint8 reserved6       # Always set to zero~%uint8 reserved7       # Always set to zero~%~%uint8 ackAiding       # If set to 1, issue acknowledgements for assistance~%uint16 wknRollover    # GPS rollover number~%~%uint32 reserved8      # Always set to zero~%uint8 reserved9       # Always set to zero~%uint8 reserved10      # Always set to zero~%~%uint8 usePPP          # Enable/disable PPP (on supported units)~%uint8 aopCfg          # AssistNow Autonomous configuration~%~%uint8 reserved11      # Always set to zero~%uint8 reserved12      # Always set to zero~%~%uint16 aopOrbMaxErr   # Maximum acceptable (modelled) autonomous orbit error~%~%uint8 reserved13      # Always set to zero~%uint8 reserved14      # Always set to zero~%uint16 reserved3      # Always set to zero~%uint32 reserved4      # Always set to zero~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <CfgNAVX5>))
  (cl:+ 0
     2
     2
     4
     1
     1
     1
     1
     1
     1
     1
     1
     1
     1
     2
     4
     1
     1
     1
     1
     1
     1
     2
     1
     1
     2
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <CfgNAVX5>))
  "Converts a ROS message object to a list"
  (cl:list 'CfgNAVX5
    (cl:cons ':version (version msg))
    (cl:cons ':mask1 (mask1 msg))
    (cl:cons ':reserved0 (reserved0 msg))
    (cl:cons ':reserved1 (reserved1 msg))
    (cl:cons ':reserved2 (reserved2 msg))
    (cl:cons ':minSVs (minSVs msg))
    (cl:cons ':maxSVs (maxSVs msg))
    (cl:cons ':minCNO (minCNO msg))
    (cl:cons ':reserved5 (reserved5 msg))
    (cl:cons ':iniFix3D (iniFix3D msg))
    (cl:cons ':reserved6 (reserved6 msg))
    (cl:cons ':reserved7 (reserved7 msg))
    (cl:cons ':ackAiding (ackAiding msg))
    (cl:cons ':wknRollover (wknRollover msg))
    (cl:cons ':reserved8 (reserved8 msg))
    (cl:cons ':reserved9 (reserved9 msg))
    (cl:cons ':reserved10 (reserved10 msg))
    (cl:cons ':usePPP (usePPP msg))
    (cl:cons ':aopCfg (aopCfg msg))
    (cl:cons ':reserved11 (reserved11 msg))
    (cl:cons ':reserved12 (reserved12 msg))
    (cl:cons ':aopOrbMaxErr (aopOrbMaxErr msg))
    (cl:cons ':reserved13 (reserved13 msg))
    (cl:cons ':reserved14 (reserved14 msg))
    (cl:cons ':reserved3 (reserved3 msg))
    (cl:cons ':reserved4 (reserved4 msg))
))
