/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/frozen-struct/src/include1.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#include "thrift/compiler/test/fixtures/frozen-struct/gen-cpp2/include1_types.tcc"

namespace some::ns {

template void IncludedA::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t IncludedA::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t IncludedA::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t IncludedA::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

} // namespace some::ns
