/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/inject_metadata_fields/src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */

#include "thrift/compiler/test/fixtures/inject_metadata_fields/gen-cpp2/module_data.h"
#include "thrift/compiler/test/fixtures/inject_metadata_fields/gen-cpp2/module_constants.h"

#include <thrift/lib/cpp2/gen/module_data_cpp.h>

namespace apache::thrift {

THRIFT_DATA_MEMBER const std::string_view TStructDataStorage<::cpp2::Fields>::name = "Fields";
THRIFT_DATA_MEMBER const std::array<std::string_view, 1> TStructDataStorage<::cpp2::Fields>::fields_names = { {
  "injected_field"sv,
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 1> TStructDataStorage<::cpp2::Fields>::fields_ids = { {
  100,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 1> TStructDataStorage<::cpp2::Fields>::fields_types = { {
  TType::T_STRING,
}};
THRIFT_DATA_MEMBER const std::array<int, 1> TStructDataStorage<::cpp2::Fields>::isset_indexes = { {
  0,
}};

THRIFT_DATA_MEMBER const std::string_view TStructDataStorage<::cpp2::FieldsInjectedToEmptyStruct>::name = "FieldsInjectedToEmptyStruct";
THRIFT_DATA_MEMBER const std::array<std::string_view, 1> TStructDataStorage<::cpp2::FieldsInjectedToEmptyStruct>::fields_names = { {
  "injected_field"sv,
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 1> TStructDataStorage<::cpp2::FieldsInjectedToEmptyStruct>::fields_ids = { {
  -1100,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 1> TStructDataStorage<::cpp2::FieldsInjectedToEmptyStruct>::fields_types = { {
  TType::T_STRING,
}};
THRIFT_DATA_MEMBER const std::array<int, 1> TStructDataStorage<::cpp2::FieldsInjectedToEmptyStruct>::isset_indexes = { {
  0,
}};

THRIFT_DATA_MEMBER const std::string_view TStructDataStorage<::cpp2::FieldsInjectedToStruct>::name = "FieldsInjectedToStruct";
THRIFT_DATA_MEMBER const std::array<std::string_view, 2> TStructDataStorage<::cpp2::FieldsInjectedToStruct>::fields_names = { {
  "string_field"sv,
  "injected_field"sv,
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 2> TStructDataStorage<::cpp2::FieldsInjectedToStruct>::fields_ids = { {
  1,
  -1100,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 2> TStructDataStorage<::cpp2::FieldsInjectedToStruct>::fields_types = { {
  TType::T_STRING,
  TType::T_STRING,
}};
THRIFT_DATA_MEMBER const std::array<int, 2> TStructDataStorage<::cpp2::FieldsInjectedToStruct>::isset_indexes = { {
  0,
  1,
}};

THRIFT_DATA_MEMBER const std::string_view TStructDataStorage<::cpp2::FieldsInjectedWithIncludedStruct>::name = "FieldsInjectedWithIncludedStruct";
THRIFT_DATA_MEMBER const std::array<std::string_view, 4> TStructDataStorage<::cpp2::FieldsInjectedWithIncludedStruct>::fields_names = { {
  "string_field"sv,
  "injected_field"sv,
  "injected_structured_annotation_field"sv,
  "injected_unstructured_annotation_field"sv,
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 4> TStructDataStorage<::cpp2::FieldsInjectedWithIncludedStruct>::fields_ids = { {
  1,
  -1100,
  -1101,
  -1102,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 4> TStructDataStorage<::cpp2::FieldsInjectedWithIncludedStruct>::fields_types = { {
  TType::T_STRING,
  TType::T_STRING,
  TType::T_STRING,
  TType::T_STRING,
}};
THRIFT_DATA_MEMBER const std::array<int, 4> TStructDataStorage<::cpp2::FieldsInjectedWithIncludedStruct>::isset_indexes = { {
  0,
  1,
  -1,
  -1,
}};

namespace detail {

::folly::Range<const ::std::string_view*>(*TSchemaAssociation<::cpp2::Fields, false>::bundle)() =
    nullptr;

::folly::Range<const ::std::string_view*>(*TSchemaAssociation<::cpp2::FieldsInjectedToEmptyStruct, false>::bundle)() =
    nullptr;

::folly::Range<const ::std::string_view*>(*TSchemaAssociation<::cpp2::FieldsInjectedToStruct, false>::bundle)() =
    nullptr;

::folly::Range<const ::std::string_view*>(*TSchemaAssociation<::cpp2::FieldsInjectedWithIncludedStruct, false>::bundle)() =
    nullptr;

} // namespace detail
} // namespace apache::thrift
