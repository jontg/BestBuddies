// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Data_Structures/Entity.proto

#ifndef PROTOBUF_Data_5fStructures_2fEntity_2eproto__INCLUDED
#define PROTOBUF_Data_5fStructures_2fEntity_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2004001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_reflection.h>
// @@protoc_insertion_point(includes)

namespace EnronProject {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_Data_5fStructures_2fEntity_2eproto();
void protobuf_AssignDesc_Data_5fStructures_2fEntity_2eproto();
void protobuf_ShutdownFile_Data_5fStructures_2fEntity_2eproto();

class Entity;

// ===================================================================

class Entity : public ::google::protobuf::Message {
 public:
  Entity();
  virtual ~Entity();
  
  Entity(const Entity& from);
  
  inline Entity& operator=(const Entity& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const Entity& default_instance();
  
  void Swap(Entity* other);
  
  // implements Message ----------------------------------------------
  
  Entity* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Entity& from);
  void MergeFrom(const Entity& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required string name = 1;
  inline bool has_name() const;
  inline void clear_name();
  static const int kNameFieldNumber = 1;
  inline const ::std::string& name() const;
  inline void set_name(const ::std::string& value);
  inline void set_name(const char* value);
  inline void set_name(const char* value, size_t size);
  inline ::std::string* mutable_name();
  inline ::std::string* release_name();
  
  // required string folder = 2;
  inline bool has_folder() const;
  inline void clear_folder();
  static const int kFolderFieldNumber = 2;
  inline const ::std::string& folder() const;
  inline void set_folder(const ::std::string& value);
  inline void set_folder(const char* value);
  inline void set_folder(const char* value, size_t size);
  inline ::std::string* mutable_folder();
  inline ::std::string* release_folder();
  
  // repeated string email = 3;
  inline int email_size() const;
  inline void clear_email();
  static const int kEmailFieldNumber = 3;
  inline const ::std::string& email(int index) const;
  inline ::std::string* mutable_email(int index);
  inline void set_email(int index, const ::std::string& value);
  inline void set_email(int index, const char* value);
  inline void set_email(int index, const char* value, size_t size);
  inline ::std::string* add_email();
  inline void add_email(const ::std::string& value);
  inline void add_email(const char* value);
  inline void add_email(const char* value, size_t size);
  inline const ::google::protobuf::RepeatedPtrField< ::std::string>& email() const;
  inline ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_email();
  
  // @@protoc_insertion_point(class_scope:EnronProject.Entity)
 private:
  inline void set_has_name();
  inline void clear_has_name();
  inline void set_has_folder();
  inline void clear_has_folder();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::std::string* name_;
  ::std::string* folder_;
  ::google::protobuf::RepeatedPtrField< ::std::string> email_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];
  
  friend void  protobuf_AddDesc_Data_5fStructures_2fEntity_2eproto();
  friend void protobuf_AssignDesc_Data_5fStructures_2fEntity_2eproto();
  friend void protobuf_ShutdownFile_Data_5fStructures_2fEntity_2eproto();
  
  void InitAsDefaultInstance();
  static Entity* default_instance_;
};
// ===================================================================


// ===================================================================

// Entity

// required string name = 1;
inline bool Entity::has_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Entity::set_has_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Entity::clear_has_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Entity::clear_name() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    name_->clear();
  }
  clear_has_name();
}
inline const ::std::string& Entity::name() const {
  return *name_;
}
inline void Entity::set_name(const ::std::string& value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void Entity::set_name(const char* value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void Entity::set_name(const char* value, size_t size) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Entity::mutable_name() {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  return name_;
}
inline ::std::string* Entity::release_name() {
  clear_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = name_;
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// required string folder = 2;
inline bool Entity::has_folder() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Entity::set_has_folder() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Entity::clear_has_folder() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Entity::clear_folder() {
  if (folder_ != &::google::protobuf::internal::kEmptyString) {
    folder_->clear();
  }
  clear_has_folder();
}
inline const ::std::string& Entity::folder() const {
  return *folder_;
}
inline void Entity::set_folder(const ::std::string& value) {
  set_has_folder();
  if (folder_ == &::google::protobuf::internal::kEmptyString) {
    folder_ = new ::std::string;
  }
  folder_->assign(value);
}
inline void Entity::set_folder(const char* value) {
  set_has_folder();
  if (folder_ == &::google::protobuf::internal::kEmptyString) {
    folder_ = new ::std::string;
  }
  folder_->assign(value);
}
inline void Entity::set_folder(const char* value, size_t size) {
  set_has_folder();
  if (folder_ == &::google::protobuf::internal::kEmptyString) {
    folder_ = new ::std::string;
  }
  folder_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Entity::mutable_folder() {
  set_has_folder();
  if (folder_ == &::google::protobuf::internal::kEmptyString) {
    folder_ = new ::std::string;
  }
  return folder_;
}
inline ::std::string* Entity::release_folder() {
  clear_has_folder();
  if (folder_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = folder_;
    folder_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// repeated string email = 3;
inline int Entity::email_size() const {
  return email_.size();
}
inline void Entity::clear_email() {
  email_.Clear();
}
inline const ::std::string& Entity::email(int index) const {
  return email_.Get(index);
}
inline ::std::string* Entity::mutable_email(int index) {
  return email_.Mutable(index);
}
inline void Entity::set_email(int index, const ::std::string& value) {
  email_.Mutable(index)->assign(value);
}
inline void Entity::set_email(int index, const char* value) {
  email_.Mutable(index)->assign(value);
}
inline void Entity::set_email(int index, const char* value, size_t size) {
  email_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Entity::add_email() {
  return email_.Add();
}
inline void Entity::add_email(const ::std::string& value) {
  email_.Add()->assign(value);
}
inline void Entity::add_email(const char* value) {
  email_.Add()->assign(value);
}
inline void Entity::add_email(const char* value, size_t size) {
  email_.Add()->assign(reinterpret_cast<const char*>(value), size);
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
Entity::email() const {
  return email_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
Entity::mutable_email() {
  return &email_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace EnronProject

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_Data_5fStructures_2fEntity_2eproto__INCLUDED