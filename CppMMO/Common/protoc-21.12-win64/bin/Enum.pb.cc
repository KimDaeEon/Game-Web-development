// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Enum.proto

#include "Enum.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace Protocol {
}  // namespace Protocol
static const ::_pb::EnumDescriptor* file_level_enum_descriptors_Enum_2eproto[1];
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_Enum_2eproto = nullptr;
const uint32_t TableStruct_Enum_2eproto::offsets[1] = {};
static constexpr ::_pbi::MigrationSchema* schemas = nullptr;
static constexpr ::_pb::Message* const* file_default_instances = nullptr;

const char descriptor_table_protodef_Enum_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\nEnum.proto\022\010Protocol*\226\001\n\tActorType\022\024\n\020"
  "PLAYER_TYPE_NONE\020\000\022\026\n\022PLAYER_TYPE_KNIGHT"
  "\020\001\022\024\n\020PLAYER_TYPE_MAGE\020\002\022\025\n\021MONSTER_TYPE"
  "_NONE\020\003\022\027\n\023MONSTER_TYPE_KNIGHT\020\004\022\025\n\021MONS"
  "TER_TYPE_MAGE\020\005b\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_Enum_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_Enum_2eproto = {
    false, false, 183, descriptor_table_protodef_Enum_2eproto,
    "Enum.proto",
    &descriptor_table_Enum_2eproto_once, nullptr, 0, 0,
    schemas, file_default_instances, TableStruct_Enum_2eproto::offsets,
    nullptr, file_level_enum_descriptors_Enum_2eproto,
    file_level_service_descriptors_Enum_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_Enum_2eproto_getter() {
  return &descriptor_table_Enum_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_Enum_2eproto(&descriptor_table_Enum_2eproto);
namespace Protocol {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ActorType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_Enum_2eproto);
  return file_level_enum_descriptors_Enum_2eproto[0];
}
bool ActorType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace Protocol
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
