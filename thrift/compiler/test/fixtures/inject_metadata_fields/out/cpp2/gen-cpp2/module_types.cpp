/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/inject_metadata_fields/src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#include "thrift/compiler/test/fixtures/inject_metadata_fields/gen-cpp2/module_types.h"
#include "thrift/compiler/test/fixtures/inject_metadata_fields/gen-cpp2/module_types.tcc"

#include <thrift/lib/cpp2/gen/module_types_cpp.h>

#include "thrift/compiler/test/fixtures/inject_metadata_fields/gen-cpp2/module_data.h"
[[maybe_unused]] static constexpr std::string_view kModuleName = "module";


namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::Fields>::translateFieldName(
    std::string_view _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::cpp2::Fields>;
  static const st::translate_field_name_table table{
      data::fields_size,
      data::fields_names.data(),
      data::fields_ids.data(),
      data::fields_types.data()};
  st::translate_field_name(_fname, fid, _ftype, table);
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace cpp2 {

std::string_view Fields::__fbthrift_get_field_name(::apache::thrift::FieldOrdinal ord) {
  if (ord == ::apache::thrift::FieldOrdinal{0}) { return {}; }
  return apache::thrift::TStructDataStorage<Fields>::fields_names[folly::to_underlying(ord) - 1];
}
std::string_view Fields::__fbthrift_get_class_name() {
  return apache::thrift::TStructDataStorage<Fields>::name;
}

Fields::Fields(const Fields&) = default;
Fields& Fields::operator=(const Fields&) = default;
Fields::Fields() {
}


Fields::~Fields() {}

Fields::Fields([[maybe_unused]] Fields&& other) noexcept :
    __fbthrift_field_injected_field(std::move(other.__fbthrift_field_injected_field)),
    __isset(other.__isset) {
}

Fields& Fields::operator=([[maybe_unused]] Fields&& other) noexcept {
    this->__fbthrift_field_injected_field = std::move(other.__fbthrift_field_injected_field);
    __isset = other.__isset;
    return *this;
}


Fields::Fields(apache::thrift::FragileConstructor, ::std::string injected_field__arg) :
    __fbthrift_field_injected_field(std::move(injected_field__arg)) { 
  __isset.set(folly::index_constant<0>(), true);
}


void Fields::__fbthrift_clear() {
  // clear all fields
  this->__fbthrift_field_injected_field = apache::thrift::StringTraits<::std::string>::fromStringLiteral("");
  __isset = {};
}

void Fields::__fbthrift_clear_terse_fields() {
}

bool Fields::__fbthrift_is_empty() const {
  return false;
}

bool Fields::operator==([[maybe_unused]] const Fields& rhs) const {
  return ::apache::thrift::op::detail::StructEquality{}(*this, rhs);
}

bool Fields::operator<([[maybe_unused]] const Fields& rhs) const {
  return ::apache::thrift::op::detail::StructLessThan{}(*this, rhs);
}


void swap([[maybe_unused]] Fields& a, [[maybe_unused]] Fields& b) {
  using ::std::swap;
  swap(a.__fbthrift_field_injected_field, b.__fbthrift_field_injected_field);
  swap(a.__isset, b.__isset);
}

template void Fields::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t Fields::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t Fields::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t Fields::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
#ifndef __FBTHRIFT_INSTANTIATE_COMPACT_PROTOCOL_IN_SEPARATE_TU
template void Fields::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t Fields::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t Fields::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t Fields::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;
#endif


} // namespace cpp2

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::FieldsInjectedToEmptyStruct>::translateFieldName(
    std::string_view _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::cpp2::FieldsInjectedToEmptyStruct>;
  static const st::translate_field_name_table table{
      data::fields_size,
      data::fields_names.data(),
      data::fields_ids.data(),
      data::fields_types.data()};
  st::translate_field_name(_fname, fid, _ftype, table);
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace cpp2 {

std::string_view FieldsInjectedToEmptyStruct::__fbthrift_get_field_name(::apache::thrift::FieldOrdinal ord) {
  if (ord == ::apache::thrift::FieldOrdinal{0}) { return {}; }
  return apache::thrift::TStructDataStorage<FieldsInjectedToEmptyStruct>::fields_names[folly::to_underlying(ord) - 1];
}
std::string_view FieldsInjectedToEmptyStruct::__fbthrift_get_class_name() {
  return apache::thrift::TStructDataStorage<FieldsInjectedToEmptyStruct>::name;
}

FieldsInjectedToEmptyStruct::FieldsInjectedToEmptyStruct(const FieldsInjectedToEmptyStruct&) = default;
FieldsInjectedToEmptyStruct& FieldsInjectedToEmptyStruct::operator=(const FieldsInjectedToEmptyStruct&) = default;
FieldsInjectedToEmptyStruct::FieldsInjectedToEmptyStruct() {
}


FieldsInjectedToEmptyStruct::~FieldsInjectedToEmptyStruct() {}

FieldsInjectedToEmptyStruct::FieldsInjectedToEmptyStruct([[maybe_unused]] FieldsInjectedToEmptyStruct&& other) noexcept :
    __fbthrift_field_injected_field(std::move(other.__fbthrift_field_injected_field)),
    __isset(other.__isset) {
}

FieldsInjectedToEmptyStruct& FieldsInjectedToEmptyStruct::operator=([[maybe_unused]] FieldsInjectedToEmptyStruct&& other) noexcept {
    this->__fbthrift_field_injected_field = std::move(other.__fbthrift_field_injected_field);
    __isset = other.__isset;
    return *this;
}


FieldsInjectedToEmptyStruct::FieldsInjectedToEmptyStruct(apache::thrift::FragileConstructor, ::std::string injected_field__arg) :
    __fbthrift_field_injected_field(std::move(injected_field__arg)) { 
  __isset.set(folly::index_constant<0>(), true);
}


void FieldsInjectedToEmptyStruct::__fbthrift_clear() {
  // clear all fields
  this->__fbthrift_field_injected_field = apache::thrift::StringTraits<::std::string>::fromStringLiteral("");
  __isset = {};
}

void FieldsInjectedToEmptyStruct::__fbthrift_clear_terse_fields() {
}

bool FieldsInjectedToEmptyStruct::__fbthrift_is_empty() const {
  return false;
}

bool FieldsInjectedToEmptyStruct::operator==([[maybe_unused]] const FieldsInjectedToEmptyStruct& rhs) const {
  return ::apache::thrift::op::detail::StructEquality{}(*this, rhs);
}

bool FieldsInjectedToEmptyStruct::operator<([[maybe_unused]] const FieldsInjectedToEmptyStruct& rhs) const {
  return ::apache::thrift::op::detail::StructLessThan{}(*this, rhs);
}


void swap([[maybe_unused]] FieldsInjectedToEmptyStruct& a, [[maybe_unused]] FieldsInjectedToEmptyStruct& b) {
  using ::std::swap;
  swap(a.__fbthrift_field_injected_field, b.__fbthrift_field_injected_field);
  swap(a.__isset, b.__isset);
}

template void FieldsInjectedToEmptyStruct::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t FieldsInjectedToEmptyStruct::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t FieldsInjectedToEmptyStruct::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t FieldsInjectedToEmptyStruct::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
#ifndef __FBTHRIFT_INSTANTIATE_COMPACT_PROTOCOL_IN_SEPARATE_TU
template void FieldsInjectedToEmptyStruct::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t FieldsInjectedToEmptyStruct::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t FieldsInjectedToEmptyStruct::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t FieldsInjectedToEmptyStruct::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;
#endif


} // namespace cpp2

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::FieldsInjectedToStruct>::translateFieldName(
    std::string_view _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::cpp2::FieldsInjectedToStruct>;
  static const st::translate_field_name_table table{
      data::fields_size,
      data::fields_names.data(),
      data::fields_ids.data(),
      data::fields_types.data()};
  st::translate_field_name(_fname, fid, _ftype, table);
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace cpp2 {

std::string_view FieldsInjectedToStruct::__fbthrift_get_field_name(::apache::thrift::FieldOrdinal ord) {
  if (ord == ::apache::thrift::FieldOrdinal{0}) { return {}; }
  return apache::thrift::TStructDataStorage<FieldsInjectedToStruct>::fields_names[folly::to_underlying(ord) - 1];
}
std::string_view FieldsInjectedToStruct::__fbthrift_get_class_name() {
  return apache::thrift::TStructDataStorage<FieldsInjectedToStruct>::name;
}

FieldsInjectedToStruct::FieldsInjectedToStruct(const FieldsInjectedToStruct&) = default;
FieldsInjectedToStruct& FieldsInjectedToStruct::operator=(const FieldsInjectedToStruct&) = default;
FieldsInjectedToStruct::FieldsInjectedToStruct() {
}


FieldsInjectedToStruct::~FieldsInjectedToStruct() {}

FieldsInjectedToStruct::FieldsInjectedToStruct([[maybe_unused]] FieldsInjectedToStruct&& other) noexcept :
    __fbthrift_field_string_field(std::move(other.__fbthrift_field_string_field)),
    __fbthrift_field_injected_field(std::move(other.__fbthrift_field_injected_field)),
    __isset(other.__isset) {
}

FieldsInjectedToStruct& FieldsInjectedToStruct::operator=([[maybe_unused]] FieldsInjectedToStruct&& other) noexcept {
    this->__fbthrift_field_string_field = std::move(other.__fbthrift_field_string_field);
    this->__fbthrift_field_injected_field = std::move(other.__fbthrift_field_injected_field);
    __isset = other.__isset;
    return *this;
}


FieldsInjectedToStruct::FieldsInjectedToStruct(apache::thrift::FragileConstructor, ::std::string string_field__arg, ::std::string injected_field__arg) :
    __fbthrift_field_string_field(std::move(string_field__arg)),
    __fbthrift_field_injected_field(std::move(injected_field__arg)) { 
  __isset.set(folly::index_constant<0>(), true);
  __isset.set(folly::index_constant<1>(), true);
}


void FieldsInjectedToStruct::__fbthrift_clear() {
  // clear all fields
  this->__fbthrift_field_string_field = apache::thrift::StringTraits<::std::string>::fromStringLiteral("");
  this->__fbthrift_field_injected_field = apache::thrift::StringTraits<::std::string>::fromStringLiteral("");
  __isset = {};
}

void FieldsInjectedToStruct::__fbthrift_clear_terse_fields() {
}

bool FieldsInjectedToStruct::__fbthrift_is_empty() const {
  return false;
}

bool FieldsInjectedToStruct::operator==([[maybe_unused]] const FieldsInjectedToStruct& rhs) const {
  return ::apache::thrift::op::detail::StructEquality{}(*this, rhs);
}

bool FieldsInjectedToStruct::operator<([[maybe_unused]] const FieldsInjectedToStruct& rhs) const {
  return ::apache::thrift::op::detail::StructLessThan{}(*this, rhs);
}


void swap([[maybe_unused]] FieldsInjectedToStruct& a, [[maybe_unused]] FieldsInjectedToStruct& b) {
  using ::std::swap;
  swap(a.__fbthrift_field_string_field, b.__fbthrift_field_string_field);
  swap(a.__fbthrift_field_injected_field, b.__fbthrift_field_injected_field);
  swap(a.__isset, b.__isset);
}

template void FieldsInjectedToStruct::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t FieldsInjectedToStruct::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t FieldsInjectedToStruct::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t FieldsInjectedToStruct::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
#ifndef __FBTHRIFT_INSTANTIATE_COMPACT_PROTOCOL_IN_SEPARATE_TU
template void FieldsInjectedToStruct::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t FieldsInjectedToStruct::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t FieldsInjectedToStruct::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t FieldsInjectedToStruct::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;
#endif


} // namespace cpp2

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::FieldsInjectedWithIncludedStruct>::translateFieldName(
    std::string_view _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::cpp2::FieldsInjectedWithIncludedStruct>;
  static const st::translate_field_name_table table{
      data::fields_size,
      data::fields_names.data(),
      data::fields_ids.data(),
      data::fields_types.data()};
  st::translate_field_name(_fname, fid, _ftype, table);
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace cpp2 {

std::string_view FieldsInjectedWithIncludedStruct::__fbthrift_get_field_name(::apache::thrift::FieldOrdinal ord) {
  if (ord == ::apache::thrift::FieldOrdinal{0}) { return {}; }
  return apache::thrift::TStructDataStorage<FieldsInjectedWithIncludedStruct>::fields_names[folly::to_underlying(ord) - 1];
}
std::string_view FieldsInjectedWithIncludedStruct::__fbthrift_get_class_name() {
  return apache::thrift::TStructDataStorage<FieldsInjectedWithIncludedStruct>::name;
}

FieldsInjectedWithIncludedStruct::FieldsInjectedWithIncludedStruct(const FieldsInjectedWithIncludedStruct&) = default;
FieldsInjectedWithIncludedStruct& FieldsInjectedWithIncludedStruct::operator=(const FieldsInjectedWithIncludedStruct&) = default;
FieldsInjectedWithIncludedStruct::FieldsInjectedWithIncludedStruct() {
}


FieldsInjectedWithIncludedStruct::~FieldsInjectedWithIncludedStruct() {}

FieldsInjectedWithIncludedStruct::FieldsInjectedWithIncludedStruct([[maybe_unused]] FieldsInjectedWithIncludedStruct&& other) noexcept :
    __fbthrift_field_string_field(std::move(other.__fbthrift_field_string_field)),
    __fbthrift_field_injected_field(std::move(other.__fbthrift_field_injected_field)),
    __fbthrift_field_injected_structured_annotation_field(std::move(other.__fbthrift_field_injected_structured_annotation_field)),
    __fbthrift_field_injected_unstructured_annotation_field(std::move(other.__fbthrift_field_injected_unstructured_annotation_field)),
    __isset(other.__isset) {
}

FieldsInjectedWithIncludedStruct& FieldsInjectedWithIncludedStruct::operator=([[maybe_unused]] FieldsInjectedWithIncludedStruct&& other) noexcept {
    this->__fbthrift_field_string_field = std::move(other.__fbthrift_field_string_field);
    this->__fbthrift_field_injected_field = std::move(other.__fbthrift_field_injected_field);
    this->__fbthrift_field_injected_structured_annotation_field = std::move(other.__fbthrift_field_injected_structured_annotation_field);
    this->__fbthrift_field_injected_unstructured_annotation_field = std::move(other.__fbthrift_field_injected_unstructured_annotation_field);
    __isset = other.__isset;
    return *this;
}


FieldsInjectedWithIncludedStruct::FieldsInjectedWithIncludedStruct(apache::thrift::FragileConstructor, ::std::string string_field__arg, ::std::string injected_field__arg, ::apache::thrift::detail::boxed_value_ptr<::std::string> injected_structured_annotation_field__arg, ::apache::thrift::detail::boxed_value_ptr<::std::string> injected_unstructured_annotation_field__arg) :
    __fbthrift_field_string_field(std::move(string_field__arg)),
    __fbthrift_field_injected_field(std::move(injected_field__arg)),
    __fbthrift_field_injected_structured_annotation_field(std::move(injected_structured_annotation_field__arg)),
    __fbthrift_field_injected_unstructured_annotation_field(std::move(injected_unstructured_annotation_field__arg)) { 
  __isset.set(folly::index_constant<0>(), true);
  __isset.set(folly::index_constant<1>(), true);
}


void FieldsInjectedWithIncludedStruct::__fbthrift_clear() {
  // clear all fields
  this->__fbthrift_field_string_field = apache::thrift::StringTraits<::std::string>::fromStringLiteral("");
  this->__fbthrift_field_injected_field = apache::thrift::StringTraits<::std::string>::fromStringLiteral("");
  this->__fbthrift_field_injected_structured_annotation_field.reset();
  this->__fbthrift_field_injected_unstructured_annotation_field.reset();
  __isset = {};
}

void FieldsInjectedWithIncludedStruct::__fbthrift_clear_terse_fields() {
}

bool FieldsInjectedWithIncludedStruct::__fbthrift_is_empty() const {
  return false;
}

bool FieldsInjectedWithIncludedStruct::operator==([[maybe_unused]] const FieldsInjectedWithIncludedStruct& rhs) const {
  return ::apache::thrift::op::detail::StructEquality{}(*this, rhs);
}

bool FieldsInjectedWithIncludedStruct::operator<([[maybe_unused]] const FieldsInjectedWithIncludedStruct& rhs) const {
  return ::apache::thrift::op::detail::StructLessThan{}(*this, rhs);
}


void swap([[maybe_unused]] FieldsInjectedWithIncludedStruct& a, [[maybe_unused]] FieldsInjectedWithIncludedStruct& b) {
  using ::std::swap;
  swap(a.__fbthrift_field_string_field, b.__fbthrift_field_string_field);
  swap(a.__fbthrift_field_injected_field, b.__fbthrift_field_injected_field);
  swap(a.__fbthrift_field_injected_structured_annotation_field, b.__fbthrift_field_injected_structured_annotation_field);
  swap(a.__fbthrift_field_injected_unstructured_annotation_field, b.__fbthrift_field_injected_unstructured_annotation_field);
  swap(a.__isset, b.__isset);
}

template void FieldsInjectedWithIncludedStruct::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t FieldsInjectedWithIncludedStruct::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t FieldsInjectedWithIncludedStruct::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t FieldsInjectedWithIncludedStruct::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
#ifndef __FBTHRIFT_INSTANTIATE_COMPACT_PROTOCOL_IN_SEPARATE_TU
template void FieldsInjectedWithIncludedStruct::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t FieldsInjectedWithIncludedStruct::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t FieldsInjectedWithIncludedStruct::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t FieldsInjectedWithIncludedStruct::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;
#endif


} // namespace cpp2

namespace cpp2 { namespace {
[[maybe_unused]] FOLLY_ERASE void validateAdapters() {
}
}} // namespace cpp2
namespace apache::thrift::detail::annotation {
}
