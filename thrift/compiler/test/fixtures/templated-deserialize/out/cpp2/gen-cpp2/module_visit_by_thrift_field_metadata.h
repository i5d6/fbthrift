/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/templated-deserialize/src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/visitation/visit_by_thrift_field_metadata.h>
#include "thrift/compiler/test/fixtures/templated-deserialize/gen-cpp2/module_metadata.h"

namespace apache {
namespace thrift {
namespace detail {

template <>
struct VisitByFieldId<::cpp2::SmallStruct> {
  template <typename F, typename T>
  void operator()([[maybe_unused]] F&& f, int32_t fieldId, [[maybe_unused]] T&& t) const {
    switch (fieldId) {
    case 1:
      return f(0, static_cast<T&&>(t).small_A_ref());
    case 2:
      return f(1, static_cast<T&&>(t).small_B_ref());
    default:
      throwInvalidThriftId(fieldId, "::cpp2::SmallStruct");
    }
  }
};

template <>
struct VisitByFieldId<::cpp2::containerStruct> {
  template <typename F, typename T>
  void operator()([[maybe_unused]] F&& f, int32_t fieldId, [[maybe_unused]] T&& t) const {
    switch (fieldId) {
    case 1:
      return f(0, static_cast<T&&>(t).fieldA_ref());
    case 2:
      return f(1, static_cast<T&&>(t).fieldB_ref());
    case 3:
      return f(2, static_cast<T&&>(t).fieldC_ref());
    case 4:
      return f(3, static_cast<T&&>(t).fieldD_ref());
    case 5:
      return f(4, static_cast<T&&>(t).fieldE_ref());
    case 6:
      return f(5, static_cast<T&&>(t).fieldF_ref());
    case 7:
      return f(6, static_cast<T&&>(t).fieldG_ref());
    case 8:
      return f(7, static_cast<T&&>(t).fieldH_ref());
    case 9:
      return f(8, static_cast<T&&>(t).fieldI_ref());
    case 10:
      return f(9, static_cast<T&&>(t).fieldJ_ref());
    case 11:
      return f(10, static_cast<T&&>(t).fieldK_ref());
    case 12:
      return f(11, static_cast<T&&>(t).fieldL_ref());
    case 13:
      return f(12, static_cast<T&&>(t).fieldM_ref());
    case 17:
      return f(13, static_cast<T&&>(t).fieldQ_ref());
    case 18:
      return f(14, static_cast<T&&>(t).fieldR_ref());
    case 19:
      return f(15, static_cast<T&&>(t).fieldS_ref());
    case 20:
      return f(16, static_cast<T&&>(t).fieldT_ref());
    case 21:
      return f(17, static_cast<T&&>(t).fieldU_ref());
    case 23:
      return f(18, static_cast<T&&>(t).fieldX_ref());
    default:
      throwInvalidThriftId(fieldId, "::cpp2::containerStruct");
    }
  }
};
} // namespace detail
} // namespace thrift
} // namespace apache
