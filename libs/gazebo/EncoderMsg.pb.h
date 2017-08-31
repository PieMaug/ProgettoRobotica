// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: EncoderMsg.proto

#ifndef PROTOBUF_EncoderMsg_2eproto__INCLUDED
#define PROTOBUF_EncoderMsg_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3002000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3002000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
namespace gazebo {
namespace msgs {
class EncoderMsg;
class EncoderMsgDefaultTypeInternal;
extern EncoderMsgDefaultTypeInternal _EncoderMsg_default_instance_;
}  // namespace msgs
}  // namespace gazebo

namespace gazebo {
namespace msgs {

namespace protobuf_EncoderMsg_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::uint32 offsets[];
  static void InitDefaultsImpl();
  static void Shutdown();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_EncoderMsg_2eproto

// ===================================================================

class EncoderMsg : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:gazebo.msgs.EncoderMsg) */ {
 public:
  EncoderMsg();
  virtual ~EncoderMsg();

  EncoderMsg(const EncoderMsg& from);

  inline EncoderMsg& operator=(const EncoderMsg& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const EncoderMsg& default_instance();

  static inline const EncoderMsg* internal_default_instance() {
    return reinterpret_cast<const EncoderMsg*>(
               &_EncoderMsg_default_instance_);
  }

  void Swap(EncoderMsg* other);

  // implements Message ----------------------------------------------

  inline EncoderMsg* New() const PROTOBUF_FINAL { return New(NULL); }

  EncoderMsg* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const EncoderMsg& from);
  void MergeFrom(const EncoderMsg& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output)
      const PROTOBUF_FINAL {
    return InternalSerializeWithCachedSizesToArray(
        ::google::protobuf::io::CodedOutputStream::IsDefaultSerializationDeterministic(), output);
  }
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(EncoderMsg* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required float timestamp = 1;
  bool has_timestamp() const;
  void clear_timestamp();
  static const int kTimestampFieldNumber = 1;
  float timestamp() const;
  void set_timestamp(float value);

  // required float left_angle = 2;
  bool has_left_angle() const;
  void clear_left_angle();
  static const int kLeftAngleFieldNumber = 2;
  float left_angle() const;
  void set_left_angle(float value);

  // required float right_angle = 3;
  bool has_right_angle() const;
  void clear_right_angle();
  static const int kRightAngleFieldNumber = 3;
  float right_angle() const;
  void set_right_angle(float value);

  // required float left_velocity = 4;
  bool has_left_velocity() const;
  void clear_left_velocity();
  static const int kLeftVelocityFieldNumber = 4;
  float left_velocity() const;
  void set_left_velocity(float value);

  // required float right_velocity = 5;
  bool has_right_velocity() const;
  void clear_right_velocity();
  static const int kRightVelocityFieldNumber = 5;
  float right_velocity() const;
  void set_right_velocity(float value);

  // @@protoc_insertion_point(class_scope:gazebo.msgs.EncoderMsg)
 private:
  void set_has_timestamp();
  void clear_has_timestamp();
  void set_has_left_angle();
  void clear_has_left_angle();
  void set_has_right_angle();
  void clear_has_right_angle();
  void set_has_left_velocity();
  void clear_has_left_velocity();
  void set_has_right_velocity();
  void clear_has_right_velocity();

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  float timestamp_;
  float left_angle_;
  float right_angle_;
  float left_velocity_;
  float right_velocity_;
  friend struct  protobuf_EncoderMsg_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// EncoderMsg

// required float timestamp = 1;
inline bool EncoderMsg::has_timestamp() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void EncoderMsg::set_has_timestamp() {
  _has_bits_[0] |= 0x00000001u;
}
inline void EncoderMsg::clear_has_timestamp() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void EncoderMsg::clear_timestamp() {
  timestamp_ = 0;
  clear_has_timestamp();
}
inline float EncoderMsg::timestamp() const {
  // @@protoc_insertion_point(field_get:gazebo.msgs.EncoderMsg.timestamp)
  return timestamp_;
}
inline void EncoderMsg::set_timestamp(float value) {
  set_has_timestamp();
  timestamp_ = value;
  // @@protoc_insertion_point(field_set:gazebo.msgs.EncoderMsg.timestamp)
}

// required float left_angle = 2;
inline bool EncoderMsg::has_left_angle() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void EncoderMsg::set_has_left_angle() {
  _has_bits_[0] |= 0x00000002u;
}
inline void EncoderMsg::clear_has_left_angle() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void EncoderMsg::clear_left_angle() {
  left_angle_ = 0;
  clear_has_left_angle();
}
inline float EncoderMsg::left_angle() const {
  // @@protoc_insertion_point(field_get:gazebo.msgs.EncoderMsg.left_angle)
  return left_angle_;
}
inline void EncoderMsg::set_left_angle(float value) {
  set_has_left_angle();
  left_angle_ = value;
  // @@protoc_insertion_point(field_set:gazebo.msgs.EncoderMsg.left_angle)
}

// required float right_angle = 3;
inline bool EncoderMsg::has_right_angle() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void EncoderMsg::set_has_right_angle() {
  _has_bits_[0] |= 0x00000004u;
}
inline void EncoderMsg::clear_has_right_angle() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void EncoderMsg::clear_right_angle() {
  right_angle_ = 0;
  clear_has_right_angle();
}
inline float EncoderMsg::right_angle() const {
  // @@protoc_insertion_point(field_get:gazebo.msgs.EncoderMsg.right_angle)
  return right_angle_;
}
inline void EncoderMsg::set_right_angle(float value) {
  set_has_right_angle();
  right_angle_ = value;
  // @@protoc_insertion_point(field_set:gazebo.msgs.EncoderMsg.right_angle)
}

// required float left_velocity = 4;
inline bool EncoderMsg::has_left_velocity() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void EncoderMsg::set_has_left_velocity() {
  _has_bits_[0] |= 0x00000008u;
}
inline void EncoderMsg::clear_has_left_velocity() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void EncoderMsg::clear_left_velocity() {
  left_velocity_ = 0;
  clear_has_left_velocity();
}
inline float EncoderMsg::left_velocity() const {
  // @@protoc_insertion_point(field_get:gazebo.msgs.EncoderMsg.left_velocity)
  return left_velocity_;
}
inline void EncoderMsg::set_left_velocity(float value) {
  set_has_left_velocity();
  left_velocity_ = value;
  // @@protoc_insertion_point(field_set:gazebo.msgs.EncoderMsg.left_velocity)
}

// required float right_velocity = 5;
inline bool EncoderMsg::has_right_velocity() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void EncoderMsg::set_has_right_velocity() {
  _has_bits_[0] |= 0x00000010u;
}
inline void EncoderMsg::clear_has_right_velocity() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void EncoderMsg::clear_right_velocity() {
  right_velocity_ = 0;
  clear_has_right_velocity();
}
inline float EncoderMsg::right_velocity() const {
  // @@protoc_insertion_point(field_get:gazebo.msgs.EncoderMsg.right_velocity)
  return right_velocity_;
}
inline void EncoderMsg::set_right_velocity(float value) {
  set_has_right_velocity();
  right_velocity_ = value;
  // @@protoc_insertion_point(field_set:gazebo.msgs.EncoderMsg.right_velocity)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)


}  // namespace msgs
}  // namespace gazebo

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_EncoderMsg_2eproto__INCLUDED
