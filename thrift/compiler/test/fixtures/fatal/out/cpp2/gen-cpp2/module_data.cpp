/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/fatal/src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */

#include "thrift/compiler/test/fixtures/fatal/gen-cpp2/module_data.h"
#include "thrift/compiler/test/fixtures/fatal/gen-cpp2/module_constants.h"

#include <thrift/lib/cpp2/gen/module_data_cpp.h>

namespace apache::thrift {

THRIFT_DATA_MEMBER const std::string_view TStructDataStorage<::test_cpp2::cpp_reflection::union1>::name = "union1";
THRIFT_DATA_MEMBER const std::array<std::string_view, 4> TStructDataStorage<::test_cpp2::cpp_reflection::union1>::fields_names = { {
  "ui"sv,
  "ud"sv,
  "us"sv,
  "ue"sv,
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 4> TStructDataStorage<::test_cpp2::cpp_reflection::union1>::fields_ids = { {
  1,
  3,
  5,
  7,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 4> TStructDataStorage<::test_cpp2::cpp_reflection::union1>::fields_types = { {
  TType::T_I32,
  TType::T_DOUBLE,
  TType::T_STRING,
  TType::T_I32,
}};
THRIFT_DATA_MEMBER const std::array<int, 4> TStructDataStorage<::test_cpp2::cpp_reflection::union1>::isset_indexes = { {
  0,
  1,
  2,
  3,
}};

THRIFT_DATA_MEMBER const std::string_view TStructDataStorage<::test_cpp2::cpp_reflection::union2>::name = "union2";
THRIFT_DATA_MEMBER const std::array<std::string_view, 4> TStructDataStorage<::test_cpp2::cpp_reflection::union2>::fields_names = { {
  "ui_2"sv,
  "ud_2"sv,
  "us_2"sv,
  "ue_2"sv,
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 4> TStructDataStorage<::test_cpp2::cpp_reflection::union2>::fields_ids = { {
  1,
  2,
  3,
  4,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 4> TStructDataStorage<::test_cpp2::cpp_reflection::union2>::fields_types = { {
  TType::T_I32,
  TType::T_DOUBLE,
  TType::T_STRING,
  TType::T_I32,
}};
THRIFT_DATA_MEMBER const std::array<int, 4> TStructDataStorage<::test_cpp2::cpp_reflection::union2>::isset_indexes = { {
  0,
  1,
  2,
  3,
}};

THRIFT_DATA_MEMBER const std::string_view TStructDataStorage<::test_cpp2::cpp_reflection::union3>::name = "union3";
THRIFT_DATA_MEMBER const std::array<std::string_view, 4> TStructDataStorage<::test_cpp2::cpp_reflection::union3>::fields_names = { {
  "ui_3"sv,
  "ud_3"sv,
  "us_3"sv,
  "ue_3"sv,
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 4> TStructDataStorage<::test_cpp2::cpp_reflection::union3>::fields_ids = { {
  1,
  2,
  3,
  4,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 4> TStructDataStorage<::test_cpp2::cpp_reflection::union3>::fields_types = { {
  TType::T_I32,
  TType::T_DOUBLE,
  TType::T_STRING,
  TType::T_I32,
}};
THRIFT_DATA_MEMBER const std::array<int, 4> TStructDataStorage<::test_cpp2::cpp_reflection::union3>::isset_indexes = { {
  0,
  1,
  2,
  3,
}};

THRIFT_DATA_MEMBER const std::string_view TStructDataStorage<::test_cpp2::cpp_reflection::structA>::name = "structA";
THRIFT_DATA_MEMBER const std::array<std::string_view, 2> TStructDataStorage<::test_cpp2::cpp_reflection::structA>::fields_names = { {
  "a"sv,
  "b"sv,
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 2> TStructDataStorage<::test_cpp2::cpp_reflection::structA>::fields_ids = { {
  1,
  2,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 2> TStructDataStorage<::test_cpp2::cpp_reflection::structA>::fields_types = { {
  TType::T_I32,
  TType::T_STRING,
}};
THRIFT_DATA_MEMBER const std::array<int, 2> TStructDataStorage<::test_cpp2::cpp_reflection::structA>::isset_indexes = { {
  0,
  1,
}};

THRIFT_DATA_MEMBER const std::string_view TStructDataStorage<::test_cpp2::cpp_reflection::unionA>::name = "unionA";
THRIFT_DATA_MEMBER const std::array<std::string_view, 5> TStructDataStorage<::test_cpp2::cpp_reflection::unionA>::fields_names = { {
  "i"sv,
  "d"sv,
  "s"sv,
  "e"sv,
  "a"sv,
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 5> TStructDataStorage<::test_cpp2::cpp_reflection::unionA>::fields_ids = { {
  1,
  2,
  3,
  4,
  5,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 5> TStructDataStorage<::test_cpp2::cpp_reflection::unionA>::fields_types = { {
  TType::T_I32,
  TType::T_DOUBLE,
  TType::T_STRING,
  TType::T_I32,
  TType::T_STRUCT,
}};
THRIFT_DATA_MEMBER const std::array<int, 5> TStructDataStorage<::test_cpp2::cpp_reflection::unionA>::isset_indexes = { {
  0,
  1,
  2,
  3,
  4,
}};

THRIFT_DATA_MEMBER const std::string_view TStructDataStorage<::test_cpp2::cpp_reflection::structB>::name = "structB";
THRIFT_DATA_MEMBER const std::array<std::string_view, 2> TStructDataStorage<::test_cpp2::cpp_reflection::structB>::fields_names = { {
  "c"sv,
  "d"sv,
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 2> TStructDataStorage<::test_cpp2::cpp_reflection::structB>::fields_ids = { {
  1,
  2,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 2> TStructDataStorage<::test_cpp2::cpp_reflection::structB>::fields_types = { {
  TType::T_DOUBLE,
  TType::T_BOOL,
}};
THRIFT_DATA_MEMBER const std::array<int, 2> TStructDataStorage<::test_cpp2::cpp_reflection::structB>::isset_indexes = { {
  0,
  1,
}};

THRIFT_DATA_MEMBER const std::string_view TStructDataStorage<::test_cpp2::cpp_reflection::structC>::name = "structC";
THRIFT_DATA_MEMBER const std::array<std::string_view, 30> TStructDataStorage<::test_cpp2::cpp_reflection::structC>::fields_names = { {
  "a"sv,
  "b"sv,
  "c"sv,
  "d"sv,
  "e"sv,
  "f"sv,
  "g"sv,
  "h"sv,
  "i"sv,
  "j"sv,
  "j1"sv,
  "j2"sv,
  "j3"sv,
  "k"sv,
  "k1"sv,
  "k2"sv,
  "k3"sv,
  "l"sv,
  "l1"sv,
  "l2"sv,
  "l3"sv,
  "m1"sv,
  "m2"sv,
  "m3"sv,
  "n1"sv,
  "n2"sv,
  "n3"sv,
  "o1"sv,
  "o2"sv,
  "o3"sv,
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 30> TStructDataStorage<::test_cpp2::cpp_reflection::structC>::fields_ids = { {
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
  11,
  12,
  13,
  14,
  15,
  16,
  17,
  18,
  19,
  20,
  21,
  22,
  23,
  24,
  25,
  26,
  27,
  28,
  29,
  30,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 30> TStructDataStorage<::test_cpp2::cpp_reflection::structC>::fields_types = { {
  TType::T_I32,
  TType::T_STRING,
  TType::T_DOUBLE,
  TType::T_BOOL,
  TType::T_I32,
  TType::T_I32,
  TType::T_STRUCT,
  TType::T_STRUCT,
  TType::T_STRUCT,
  TType::T_LIST,
  TType::T_LIST,
  TType::T_LIST,
  TType::T_LIST,
  TType::T_SET,
  TType::T_SET,
  TType::T_SET,
  TType::T_SET,
  TType::T_MAP,
  TType::T_MAP,
  TType::T_MAP,
  TType::T_MAP,
  TType::T_MAP,
  TType::T_MAP,
  TType::T_MAP,
  TType::T_MAP,
  TType::T_MAP,
  TType::T_MAP,
  TType::T_MAP,
  TType::T_MAP,
  TType::T_MAP,
}};
THRIFT_DATA_MEMBER const std::array<int, 30> TStructDataStorage<::test_cpp2::cpp_reflection::structC>::isset_indexes = { {
  0,
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
  11,
  12,
  13,
  14,
  15,
  16,
  17,
  18,
  19,
  20,
  21,
  22,
  23,
  24,
  25,
  26,
  27,
  28,
  29,
}};

THRIFT_DATA_MEMBER const std::string_view TStructDataStorage<::test_cpp2::cpp_reflection::struct1>::name = "struct1";
THRIFT_DATA_MEMBER const std::array<std::string_view, 6> TStructDataStorage<::test_cpp2::cpp_reflection::struct1>::fields_names = { {
  "field0"sv,
  "field1"sv,
  "field2"sv,
  "field3"sv,
  "field4"sv,
  "field5"sv,
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 6> TStructDataStorage<::test_cpp2::cpp_reflection::struct1>::fields_ids = { {
  1,
  2,
  3,
  4,
  5,
  6,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 6> TStructDataStorage<::test_cpp2::cpp_reflection::struct1>::fields_types = { {
  TType::T_I32,
  TType::T_STRING,
  TType::T_I32,
  TType::T_I32,
  TType::T_STRUCT,
  TType::T_STRUCT,
}};
THRIFT_DATA_MEMBER const std::array<int, 6> TStructDataStorage<::test_cpp2::cpp_reflection::struct1>::isset_indexes = { {
  -1,
  0,
  1,
  -1,
  2,
  3,
}};

THRIFT_DATA_MEMBER const std::string_view TStructDataStorage<::test_cpp2::cpp_reflection::struct2>::name = "struct2";
THRIFT_DATA_MEMBER const std::array<std::string_view, 7> TStructDataStorage<::test_cpp2::cpp_reflection::struct2>::fields_names = { {
  "fieldA"sv,
  "fieldB"sv,
  "fieldC"sv,
  "fieldD"sv,
  "fieldE"sv,
  "fieldF"sv,
  "fieldG"sv,
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 7> TStructDataStorage<::test_cpp2::cpp_reflection::struct2>::fields_ids = { {
  1,
  2,
  3,
  4,
  5,
  6,
  7,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 7> TStructDataStorage<::test_cpp2::cpp_reflection::struct2>::fields_types = { {
  TType::T_I32,
  TType::T_STRING,
  TType::T_I32,
  TType::T_I32,
  TType::T_STRUCT,
  TType::T_STRUCT,
  TType::T_STRUCT,
}};
THRIFT_DATA_MEMBER const std::array<int, 7> TStructDataStorage<::test_cpp2::cpp_reflection::struct2>::isset_indexes = { {
  0,
  1,
  2,
  3,
  4,
  5,
  6,
}};

THRIFT_DATA_MEMBER const std::string_view TStructDataStorage<::test_cpp2::cpp_reflection::struct3>::name = "struct3";
THRIFT_DATA_MEMBER const std::array<std::string_view, 18> TStructDataStorage<::test_cpp2::cpp_reflection::struct3>::fields_names = { {
  "fieldA"sv,
  "fieldB"sv,
  "fieldC"sv,
  "fieldD"sv,
  "fieldE"sv,
  "fieldF"sv,
  "fieldG"sv,
  "fieldH"sv,
  "fieldI"sv,
  "fieldJ"sv,
  "fieldK"sv,
  "fieldL"sv,
  "fieldM"sv,
  "fieldN"sv,
  "fieldO"sv,
  "fieldP"sv,
  "fieldQ"sv,
  "fieldR"sv,
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 18> TStructDataStorage<::test_cpp2::cpp_reflection::struct3>::fields_ids = { {
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
  11,
  12,
  13,
  14,
  15,
  16,
  17,
  18,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 18> TStructDataStorage<::test_cpp2::cpp_reflection::struct3>::fields_types = { {
  TType::T_I32,
  TType::T_STRING,
  TType::T_I32,
  TType::T_I32,
  TType::T_STRUCT,
  TType::T_STRUCT,
  TType::T_STRUCT,
  TType::T_STRUCT,
  TType::T_LIST,
  TType::T_LIST,
  TType::T_LIST,
  TType::T_LIST,
  TType::T_SET,
  TType::T_SET,
  TType::T_SET,
  TType::T_SET,
  TType::T_MAP,
  TType::T_MAP,
}};
THRIFT_DATA_MEMBER const std::array<int, 18> TStructDataStorage<::test_cpp2::cpp_reflection::struct3>::isset_indexes = { {
  -1,
  0,
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
  11,
  12,
  13,
  14,
  15,
  16,
}};

THRIFT_DATA_MEMBER const std::string_view TStructDataStorage<::test_cpp2::cpp_reflection::struct4>::name = "struct4";
THRIFT_DATA_MEMBER const std::array<std::string_view, 4> TStructDataStorage<::test_cpp2::cpp_reflection::struct4>::fields_names = { {
  "field0"sv,
  "field1"sv,
  "field2"sv,
  "field3"sv,
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 4> TStructDataStorage<::test_cpp2::cpp_reflection::struct4>::fields_ids = { {
  1,
  2,
  3,
  6,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 4> TStructDataStorage<::test_cpp2::cpp_reflection::struct4>::fields_types = { {
  TType::T_I32,
  TType::T_STRING,
  TType::T_I32,
  TType::T_STRUCT,
}};
THRIFT_DATA_MEMBER const std::array<int, 4> TStructDataStorage<::test_cpp2::cpp_reflection::struct4>::isset_indexes = { {
  -1,
  0,
  1,
  -1,
}};

THRIFT_DATA_MEMBER const std::string_view TStructDataStorage<::test_cpp2::cpp_reflection::struct5>::name = "struct5";
THRIFT_DATA_MEMBER const std::array<std::string_view, 5> TStructDataStorage<::test_cpp2::cpp_reflection::struct5>::fields_names = { {
  "field0"sv,
  "field1"sv,
  "field2"sv,
  "field3"sv,
  "field4"sv,
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 5> TStructDataStorage<::test_cpp2::cpp_reflection::struct5>::fields_ids = { {
  1,
  2,
  3,
  4,
  5,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 5> TStructDataStorage<::test_cpp2::cpp_reflection::struct5>::fields_types = { {
  TType::T_I32,
  TType::T_STRING,
  TType::T_I32,
  TType::T_STRUCT,
  TType::T_STRUCT,
}};
THRIFT_DATA_MEMBER const std::array<int, 5> TStructDataStorage<::test_cpp2::cpp_reflection::struct5>::isset_indexes = { {
  -1,
  0,
  1,
  2,
  3,
}};

THRIFT_DATA_MEMBER const std::string_view TStructDataStorage<::test_cpp2::cpp_reflection::struct_binary>::name = "struct_binary";
THRIFT_DATA_MEMBER const std::array<std::string_view, 1> TStructDataStorage<::test_cpp2::cpp_reflection::struct_binary>::fields_names = { {
  "bi"sv,
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 1> TStructDataStorage<::test_cpp2::cpp_reflection::struct_binary>::fields_ids = { {
  1,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 1> TStructDataStorage<::test_cpp2::cpp_reflection::struct_binary>::fields_types = { {
  TType::T_STRING,
}};
THRIFT_DATA_MEMBER const std::array<int, 1> TStructDataStorage<::test_cpp2::cpp_reflection::struct_binary>::isset_indexes = { {
  0,
}};

THRIFT_DATA_MEMBER const std::string_view TStructDataStorage<::test_cpp2::cpp_reflection::dep_A_struct>::name = "dep_A_struct";
THRIFT_DATA_MEMBER const std::array<std::string_view, 3> TStructDataStorage<::test_cpp2::cpp_reflection::dep_A_struct>::fields_names = { {
  "b"sv,
  "c"sv,
  "i_a"sv,
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 3> TStructDataStorage<::test_cpp2::cpp_reflection::dep_A_struct>::fields_ids = { {
  1,
  2,
  3,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 3> TStructDataStorage<::test_cpp2::cpp_reflection::dep_A_struct>::fields_types = { {
  TType::T_STRUCT,
  TType::T_STRUCT,
  TType::T_I32,
}};
THRIFT_DATA_MEMBER const std::array<int, 3> TStructDataStorage<::test_cpp2::cpp_reflection::dep_A_struct>::isset_indexes = { {
  0,
  1,
  2,
}};

THRIFT_DATA_MEMBER const std::string_view TStructDataStorage<::test_cpp2::cpp_reflection::dep_B_struct>::name = "dep_B_struct";
THRIFT_DATA_MEMBER const std::array<std::string_view, 3> TStructDataStorage<::test_cpp2::cpp_reflection::dep_B_struct>::fields_names = { {
  "b"sv,
  "c"sv,
  "i_a"sv,
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 3> TStructDataStorage<::test_cpp2::cpp_reflection::dep_B_struct>::fields_ids = { {
  1,
  2,
  3,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 3> TStructDataStorage<::test_cpp2::cpp_reflection::dep_B_struct>::fields_types = { {
  TType::T_STRUCT,
  TType::T_STRUCT,
  TType::T_I32,
}};
THRIFT_DATA_MEMBER const std::array<int, 3> TStructDataStorage<::test_cpp2::cpp_reflection::dep_B_struct>::isset_indexes = { {
  0,
  1,
  2,
}};

THRIFT_DATA_MEMBER const std::string_view TStructDataStorage<::test_cpp2::cpp_reflection::annotated>::name = "annotated";
THRIFT_DATA_MEMBER const std::array<std::string_view, 1> TStructDataStorage<::test_cpp2::cpp_reflection::annotated>::fields_names = { {
  "a"sv,
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 1> TStructDataStorage<::test_cpp2::cpp_reflection::annotated>::fields_ids = { {
  1,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 1> TStructDataStorage<::test_cpp2::cpp_reflection::annotated>::fields_types = { {
  TType::T_I32,
}};
THRIFT_DATA_MEMBER const std::array<int, 1> TStructDataStorage<::test_cpp2::cpp_reflection::annotated>::isset_indexes = { {
  0,
}};

THRIFT_DATA_MEMBER const std::string_view TStructDataStorage<::test_cpp2::cpp_reflection::union_with_special_names>::name = "union_with_special_names";
THRIFT_DATA_MEMBER const std::array<std::string_view, 28> TStructDataStorage<::test_cpp2::cpp_reflection::union_with_special_names>::fields_names = { {
  "get"sv,
  "getter"sv,
  "lists"sv,
  "maps"sv,
  "name"sv,
  "name_to_value"sv,
  "names"sv,
  "prefix_tree"sv,
  "sets"sv,
  "setter"sv,
  "str"sv,
  "strings"sv,
  "type"sv,
  "value"sv,
  "value_to_name"sv,
  "values"sv,
  "id"sv,
  "ids"sv,
  "descriptor"sv,
  "descriptors"sv,
  "key"sv,
  "keys"sv,
  "annotation"sv,
  "annotations"sv,
  "member"sv,
  "members"sv,
  "field"sv,
  "fields"sv,
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 28> TStructDataStorage<::test_cpp2::cpp_reflection::union_with_special_names>::fields_ids = { {
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
  11,
  12,
  13,
  14,
  15,
  16,
  17,
  18,
  19,
  20,
  21,
  22,
  23,
  24,
  25,
  26,
  27,
  28,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 28> TStructDataStorage<::test_cpp2::cpp_reflection::union_with_special_names>::fields_types = { {
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
}};
THRIFT_DATA_MEMBER const std::array<int, 28> TStructDataStorage<::test_cpp2::cpp_reflection::union_with_special_names>::isset_indexes = { {
  0,
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
  11,
  12,
  13,
  14,
  15,
  16,
  17,
  18,
  19,
  20,
  21,
  22,
  23,
  24,
  25,
  26,
  27,
}};

THRIFT_DATA_MEMBER const std::string_view TStructDataStorage<::test_cpp2::cpp_reflection::struct_with_special_names>::name = "struct_with_special_names";
THRIFT_DATA_MEMBER const std::array<std::string_view, 28> TStructDataStorage<::test_cpp2::cpp_reflection::struct_with_special_names>::fields_names = { {
  "get"sv,
  "getter"sv,
  "lists"sv,
  "maps"sv,
  "name"sv,
  "name_to_value"sv,
  "names"sv,
  "prefix_tree"sv,
  "sets"sv,
  "setter"sv,
  "str"sv,
  "strings"sv,
  "type"sv,
  "value"sv,
  "value_to_name"sv,
  "values"sv,
  "id"sv,
  "ids"sv,
  "descriptor"sv,
  "descriptors"sv,
  "key"sv,
  "keys"sv,
  "annotation"sv,
  "annotations"sv,
  "member"sv,
  "members"sv,
  "field"sv,
  "fields"sv,
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 28> TStructDataStorage<::test_cpp2::cpp_reflection::struct_with_special_names>::fields_ids = { {
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
  11,
  12,
  13,
  14,
  15,
  16,
  17,
  18,
  19,
  20,
  21,
  22,
  23,
  24,
  25,
  26,
  27,
  28,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 28> TStructDataStorage<::test_cpp2::cpp_reflection::struct_with_special_names>::fields_types = { {
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
  TType::T_I32,
}};
THRIFT_DATA_MEMBER const std::array<int, 28> TStructDataStorage<::test_cpp2::cpp_reflection::struct_with_special_names>::isset_indexes = { {
  0,
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
  11,
  12,
  13,
  14,
  15,
  16,
  17,
  18,
  19,
  20,
  21,
  22,
  23,
  24,
  25,
  26,
  27,
}};

THRIFT_DATA_MEMBER const std::string_view TStructDataStorage<::test_cpp2::cpp_reflection::StructWithFieldAdapter>::name = "StructWithFieldAdapter";
THRIFT_DATA_MEMBER const std::array<std::string_view, 1> TStructDataStorage<::test_cpp2::cpp_reflection::StructWithFieldAdapter>::fields_names = { {
  "field"sv,
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 1> TStructDataStorage<::test_cpp2::cpp_reflection::StructWithFieldAdapter>::fields_ids = { {
  1,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 1> TStructDataStorage<::test_cpp2::cpp_reflection::StructWithFieldAdapter>::fields_types = { {
  TType::T_I32,
}};
THRIFT_DATA_MEMBER const std::array<int, 1> TStructDataStorage<::test_cpp2::cpp_reflection::StructWithFieldAdapter>::isset_indexes = { {
  0,
}};

THRIFT_DATA_MEMBER const std::string_view TStructDataStorage<::test_cpp2::cpp_reflection::UnionWithTypedefFieldAdapter>::name = "UnionWithTypedefFieldAdapter";
THRIFT_DATA_MEMBER const std::array<std::string_view, 1> TStructDataStorage<::test_cpp2::cpp_reflection::UnionWithTypedefFieldAdapter>::fields_names = { {
  "field"sv,
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 1> TStructDataStorage<::test_cpp2::cpp_reflection::UnionWithTypedefFieldAdapter>::fields_ids = { {
  1,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 1> TStructDataStorage<::test_cpp2::cpp_reflection::UnionWithTypedefFieldAdapter>::fields_types = { {
  TType::T_I32,
}};
THRIFT_DATA_MEMBER const std::array<int, 1> TStructDataStorage<::test_cpp2::cpp_reflection::UnionWithTypedefFieldAdapter>::isset_indexes = { {
  0,
}};

namespace detail {

::folly::Range<const ::std::string_view*>(*TSchemaAssociation<::test_cpp2::cpp_reflection::union1, false>::bundle)() =
    nullptr;

::folly::Range<const ::std::string_view*>(*TSchemaAssociation<::test_cpp2::cpp_reflection::union2, false>::bundle)() =
    nullptr;

::folly::Range<const ::std::string_view*>(*TSchemaAssociation<::test_cpp2::cpp_reflection::union3, false>::bundle)() =
    nullptr;

::folly::Range<const ::std::string_view*>(*TSchemaAssociation<::test_cpp2::cpp_reflection::structA, false>::bundle)() =
    nullptr;

::folly::Range<const ::std::string_view*>(*TSchemaAssociation<::test_cpp2::cpp_reflection::unionA, false>::bundle)() =
    nullptr;

::folly::Range<const ::std::string_view*>(*TSchemaAssociation<::test_cpp2::cpp_reflection::structB, false>::bundle)() =
    nullptr;

::folly::Range<const ::std::string_view*>(*TSchemaAssociation<::test_cpp2::cpp_reflection::structC, false>::bundle)() =
    nullptr;

::folly::Range<const ::std::string_view*>(*TSchemaAssociation<::test_cpp2::cpp_reflection::struct1, false>::bundle)() =
    nullptr;

::folly::Range<const ::std::string_view*>(*TSchemaAssociation<::test_cpp2::cpp_reflection::struct2, false>::bundle)() =
    nullptr;

::folly::Range<const ::std::string_view*>(*TSchemaAssociation<::test_cpp2::cpp_reflection::struct3, false>::bundle)() =
    nullptr;

::folly::Range<const ::std::string_view*>(*TSchemaAssociation<::test_cpp2::cpp_reflection::struct4, false>::bundle)() =
    nullptr;

::folly::Range<const ::std::string_view*>(*TSchemaAssociation<::test_cpp2::cpp_reflection::struct5, false>::bundle)() =
    nullptr;

::folly::Range<const ::std::string_view*>(*TSchemaAssociation<::test_cpp2::cpp_reflection::struct_binary, false>::bundle)() =
    nullptr;

::folly::Range<const ::std::string_view*>(*TSchemaAssociation<::test_cpp2::cpp_reflection::dep_A_struct, false>::bundle)() =
    nullptr;

::folly::Range<const ::std::string_view*>(*TSchemaAssociation<::test_cpp2::cpp_reflection::dep_B_struct, false>::bundle)() =
    nullptr;

::folly::Range<const ::std::string_view*>(*TSchemaAssociation<::test_cpp2::cpp_reflection::annotated, false>::bundle)() =
    nullptr;

::folly::Range<const ::std::string_view*>(*TSchemaAssociation<::test_cpp2::cpp_reflection::union_with_special_names, false>::bundle)() =
    nullptr;

::folly::Range<const ::std::string_view*>(*TSchemaAssociation<::test_cpp2::cpp_reflection::struct_with_special_names, false>::bundle)() =
    nullptr;

::folly::Range<const ::std::string_view*>(*TSchemaAssociation<::test_cpp2::cpp_reflection::StructWithFieldAdapter, false>::bundle)() =
    nullptr;

::folly::Range<const ::std::string_view*>(*TSchemaAssociation<::test_cpp2::cpp_reflection::UnionWithTypedefFieldAdapter, false>::bundle)() =
    nullptr;

::folly::Range<const ::std::string_view*>(*TSchemaAssociation<::test_cpp2::cpp_reflection::enum1, true>::bundle)() =
    nullptr;

::folly::Range<const ::std::string_view*>(*TSchemaAssociation<::test_cpp2::cpp_reflection::enum2, true>::bundle)() =
    nullptr;

::folly::Range<const ::std::string_view*>(*TSchemaAssociation<::test_cpp2::cpp_reflection::enum3, true>::bundle)() =
    nullptr;

::folly::Range<const ::std::string_view*>(*TSchemaAssociation<::test_cpp2::cpp_reflection::enum_with_special_names, true>::bundle)() =
    nullptr;

} // namespace detail
} // namespace apache::thrift
