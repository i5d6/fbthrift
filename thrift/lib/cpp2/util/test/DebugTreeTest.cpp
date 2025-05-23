/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <gtest/gtest.h>
#include <folly/String.h>
#include <thrift/lib/cpp2/util/DebugTree.h>
#include <thrift/lib/cpp2/util/test/gen-cpp2/gen_patch_DebugTree_types.h>

namespace apache::thrift::detail {

using namespace test;

const SyntaxGraph& getGraph() {
  static auto merged = SchemaRegistry::get().getMergedSchema();
  static auto graph = SyntaxGraph::fromSchema(merged.get());
  return graph;
}

void expectEq(const scope& node, const std::string& text) {
  EXPECT_EQ(to_string(node), folly::stripLeftMargin(text));
}

TEST(DebugTreeTest, MyStruct) {
  MyStruct s;
  s.boolVal() = "true";
  s.byteVal() = 10;
  s.i16Val() = 20;
  s.i32Val() = 30;
  s.i64Val() = 40;
  s.floatVal() = 50;
  s.doubleVal() = 60;
  s.stringVal() = "70";
  constexpr char x[3] = {2, 1, 0}; // string with non-printable characters
  s.binaryVal() = folly::IOBuf::wrapBufferAsValue(x, 3);
  s.listVal()->push_back(200);
  s.listVal()->push_back(100);
  s.listVal()->push_back(300);
  s.setVal()->emplace("500");
  s.setVal()->emplace("400");
  s.setVal()->emplace("600");
  s.mapVal()["800"] = "888";
  s.mapVal()["700"] = "777";
  s.mapVal()["900"] = "999";

  auto v = protocol::asValueStruct<type::struct_t<MyStruct>>(s);

  erase_if(*v.as_object().members(), [](auto& kv) {
    // Remove fields we are not interested in.
    return op::invoke_by_field_id<MyStruct>(
        FieldId{kv.first},
        []<class Id>(Id) {
          return !folly::IsOneOf<
              op::get_ident<MyStruct, Id>,
              ident::boolVal,
              ident::byteVal,
              ident::i16Val,
              ident::i32Val,
              ident::i64Val,
              ident::floatVal,
              ident::doubleVal,
              ident::stringVal,
              ident::binaryVal,
              ident::listVal,
              ident::setVal,
              ident::mapVal>::value;
        },
        [] {
          CHECK(false);
          return false;
        });
  });

  expectEq(debugTree(v, getGraph(), Uri{apache::thrift::uri<MyStruct>()}), R"(
    Definition(kind=Struct, name='MyStruct', program='DebugTree.thrift')
    ├─ boolVal
    │  ╰─ true
    ├─ byteVal
    │  ╰─ 10
    ├─ i16Val
    │  ╰─ 20
    ├─ i32Val
    │  ╰─ 30
    ├─ i64Val
    │  ╰─ 40
    ├─ floatVal
    │  ╰─ 50
    ├─ doubleVal
    │  ╰─ 60
    ├─ stringVal
    │  ╰─ 70
    ├─ binaryVal
    │  ╰─ \x2\x1\x0
    ├─ listVal
    │  ╰─ <List>
    │     ├─ 200
    │     ├─ 100
    │     ╰─ 300
    ├─ setVal
    │  ╰─ <Set>
    │     ├─ 400
    │     ├─ 500
    │     ╰─ 600
    ╰─ mapVal
       ╰─ <Map>
          ├─ Key #0
          │  ╰─ 700
          ├─ Value #0
          │  ╰─ 777
          ├─ Key #1
          │  ╰─ 800
          ├─ Value #1
          │  ╰─ 888
          ├─ Key #2
          │  ╰─ 900
          ╰─ Value #2
             ╰─ 999
    )");
  expectEq(debugTree(v, getGraph()), R"(
    <UNKNOWN STRUCT>
    ├─ FieldId(1)
    │  ╰─ true
    ├─ FieldId(2)
    │  ╰─ 10
    ├─ FieldId(3)
    │  ╰─ 20
    ├─ FieldId(4)
    │  ╰─ 30
    ├─ FieldId(5)
    │  ╰─ 40
    ├─ FieldId(6)
    │  ╰─ 50
    ├─ FieldId(7)
    │  ╰─ 60
    ├─ FieldId(8)
    │  ╰─ 70
    ├─ FieldId(9)
    │  ╰─ \x2\x1\x0
    ├─ FieldId(36)
    │  ╰─ <List>
    │     ├─ 200
    │     ├─ 100
    │     ╰─ 300
    ├─ FieldId(37)
    │  ╰─ <Set>
    │     ├─ 400
    │     ├─ 500
    │     ╰─ 600
    ╰─ FieldId(38)
       ╰─ <Map>
          ├─ Key #0
          │  ╰─ 700
          ├─ Value #0
          │  ╰─ 777
          ├─ Key #1
          │  ╰─ 800
          ├─ Value #1
          │  ╰─ 888
          ├─ Key #2
          │  ╰─ 900
          ╰─ Value #2
             ╰─ 999
    )");
}

TEST(DebugTreeTest, ObjectWithAny) {
  StructWithAny nested;
  SharedPtr s;
  s.shared_field() = std::make_unique<std::string>("I_AM_SHARED");
  s.field2() = 2000;
  s.field3() = 3000;
  nested.any() = AnyData::toAny(s).toThrift();

  StructWithAny outer;
  outer.any() = AnyData::toAny(nested).toThrift();
  auto v = protocol::asValueStruct<type::struct_t<StructWithAny>>(outer);

  expectEq(debugTree(v, getGraph()), R"(
    <UNKNOWN STRUCT>
    ├─ FieldId(1)
    │  ╰─ <Thrift.Any, type=struct<StructWithAny>, protocol=Compact>
    │     ╰─ Definition(kind=Struct, name='StructWithAny', program='DebugTree.thrift')
    │        ├─ any
    │        │  ╰─ <Thrift.Any, type=struct<SharedPtr>, protocol=Compact>
    │        │     ╰─ Definition(kind=Struct, name='SharedPtr', program='DebugTree.thrift')
    │        │        ├─ shared_field
    │        │        │  ╰─ I_AM_SHARED
    │        │        ├─ field2
    │        │        │  ╰─ 2000
    │        │        ╰─ field3
    │        │           ╰─ 3000
    │        ├─ any_map
    │        │  ╰─ <Map>
    │        ╰─ anydata
    │           ╰─ <Maybe Empty Thrift.Any>
    ├─ FieldId(2)
    │  ╰─ <Map>
    ╰─ FieldId(3)
       ╰─ <Maybe Empty Thrift.Any>
    )");
}

TEST(DebugTreeTest, DynamicPrimitivePatch) {
  MyStructPatch patch;
  patch.patchIfSet<ident::boolVal>().invert();
  patch.patchIfSet<ident::byteVal>() += 1;
  patch.patchIfSet<ident::i16Val>() += 2;
  patch.patchIfSet<ident::i32Val>() += 3;
  patch.patchIfSet<ident::i64Val>() += 4;
  patch.patchIfSet<ident::floatVal>() += 5;
  patch.patchIfSet<ident::doubleVal>() += 6;
  patch.patchIfSet<ident::stringVal>().prepend("(");
  patch.patchIfSet<ident::stringVal>().append(")");
  auto dynPatch = protocol::DynamicPatch::fromObject(patch.toObject());
  expectEq(
      debugTree(dynPatch, getGraph(), Uri{apache::thrift::uri<MyStruct>()}), R"(
    DynamicStructPatch
    ├─ ensure
    │  ├─ boolVal
    │  │  ╰─ false
    │  ├─ byteVal
    │  │  ╰─ 0
    │  ├─ i16Val
    │  │  ╰─ 0
    │  ├─ i32Val
    │  │  ╰─ 0
    │  ├─ i64Val
    │  │  ╰─ 0
    │  ├─ floatVal
    │  │  ╰─ 0
    │  ├─ doubleVal
    │  │  ╰─ 0
    │  ╰─ stringVal
    │     ╰─ ""
    ╰─ patch
       ├─ boolVal
       │  ╰─ BoolPatch
       │     ╰─ invert
       ├─ byteVal
       │  ╰─ BytePatch
       │     ╰─ add
       │        ╰─ 1
       ├─ i16Val
       │  ╰─ I16Patch
       │     ╰─ add
       │        ╰─ 2
       ├─ i32Val
       │  ╰─ I32Patch
       │     ╰─ add
       │        ╰─ 3
       ├─ i64Val
       │  ╰─ I64Patch
       │     ╰─ add
       │        ╰─ 4
       ├─ floatVal
       │  ╰─ FloatPatch
       │     ╰─ add
       │        ╰─ 5
       ├─ doubleVal
       │  ╰─ DoublePatch
       │     ╰─ add
       │        ╰─ 6
       ╰─ stringVal
          ╰─ BinaryPatch
             ├─ prepend
             │  ╰─ (
             ╰─ append
                ╰─ )
    )");
  expectEq(debugTree(dynPatch, getGraph()), R"(
    DynamicStructPatch
    ├─ ensure
    │  ├─ FieldId(1)
    │  │  ╰─ false
    │  ├─ FieldId(2)
    │  │  ╰─ 0
    │  ├─ FieldId(3)
    │  │  ╰─ 0
    │  ├─ FieldId(4)
    │  │  ╰─ 0
    │  ├─ FieldId(5)
    │  │  ╰─ 0
    │  ├─ FieldId(6)
    │  │  ╰─ 0
    │  ├─ FieldId(7)
    │  │  ╰─ 0
    │  ╰─ FieldId(8)
    │     ╰─ ""
    ╰─ patch
       ├─ FieldId(1)
       │  ╰─ BoolPatch
       │     ╰─ invert
       ├─ FieldId(2)
       │  ╰─ BytePatch
       │     ╰─ add
       │        ╰─ 1
       ├─ FieldId(3)
       │  ╰─ I16Patch
       │     ╰─ add
       │        ╰─ 2
       ├─ FieldId(4)
       │  ╰─ I32Patch
       │     ╰─ add
       │        ╰─ 3
       ├─ FieldId(5)
       │  ╰─ I64Patch
       │     ╰─ add
       │        ╰─ 4
       ├─ FieldId(6)
       │  ╰─ FloatPatch
       │     ╰─ add
       │        ╰─ 5
       ├─ FieldId(7)
       │  ╰─ DoublePatch
       │     ╰─ add
       │        ╰─ 6
       ╰─ FieldId(8)
          ╰─ BinaryPatch
             ├─ prepend
             │  ╰─ (
             ╰─ append
                ╰─ )
    )");
}

TEST(DebugTreeTest, DynamicNestedStructPatch) {
  MyStructPatch patch;
  patch.patch<ident::structVal>().patchIfSet<ident::data1>() += ";";
  auto dynPatch = protocol::DynamicPatch::fromObject(patch.toObject());
  expectEq(
      debugTree(dynPatch, getGraph(), Uri{apache::thrift::uri<MyStruct>()}), R"(
    DynamicStructPatch
    ├─ ensure
    │  ╰─ structVal
    │     ╰─ Definition(kind=Struct, name='MyData', program='DebugTree.thrift')
    │        ├─ data1
    │        │  ╰─ ""
    │        ╰─ data2
    │           ╰─ 0
    ╰─ patch
       ╰─ structVal
          ╰─ DynamicStructPatch
             ├─ ensure
             │  ╰─ data1
             │     ╰─ ""
             ╰─ patch
                ╰─ data1
                   ╰─ BinaryPatch
                      ╰─ append
                         ╰─ ;
    )");
  expectEq(debugTree(dynPatch, getGraph()), R"(
    DynamicStructPatch
    ├─ ensure
    │  ╰─ FieldId(11)
    │     ╰─ <UNKNOWN STRUCT>
    │        ├─ FieldId(1)
    │        │  ╰─ ""
    │        ╰─ FieldId(2)
    │           ╰─ 0
    ╰─ patch
       ╰─ FieldId(11)
          ╰─ DynamicStructPatch
             ├─ ensure
             │  ╰─ FieldId(1)
             │     ╰─ ""
             ╰─ patch
                ╰─ FieldId(1)
                   ╰─ BinaryPatch
                      ╰─ append
                         ╰─ ;
    )");
}

TEST(DebugTreeTest, DynamicContainerPatch) {
  MyStructPatch patch;
  patch.patchIfSet<ident::optListVal>().push_back(42);
  patch.patchIfSet<ident::optSetVal>().insert("SetElem");
  patch.patchIfSet<ident::optMapVal>().patchByKey("Key").append("Suffix");
  auto dynPatch = protocol::DynamicPatch::fromObject(patch.toObject());
  // TODO(ytj): We knew it's a StructPatch, not UnknownPatch (from the Schema).
  expectEq(
      debugTree(dynPatch, getGraph(), Uri{apache::thrift::uri<MyStruct>()}), R"(
    UnknownPatch
    ╰─ patch
       ├─ optListVal
       │  ╰─ DynamicListPatch
       │     ╰─ push_back
       │        ╰─ 42
       ├─ optSetVal
       │  ╰─ DynamicSetPatch
       │     ╰─ addMulti
       │        ╰─ <Set>
       │           ╰─ SetElem
       ╰─ optMapVal
          ╰─ DynamicMapPatch
             ╰─ patch
                ╰─ KeyAndSubPatch
                   ├─ Key
                   ╰─ BinaryPatch
                      ╰─ append
                         ╰─ Suffix
    )");
  expectEq(debugTree(dynPatch, getGraph()), R"(
    UnknownPatch
    ╰─ patch
       ├─ FieldId(26)
       │  ╰─ DynamicListPatch
       │     ╰─ push_back
       │        ╰─ 42
       ├─ FieldId(27)
       │  ╰─ DynamicSetPatch
       │     ╰─ addMulti
       │        ╰─ <Set>
       │           ╰─ SetElem
       ╰─ FieldId(28)
          ╰─ DynamicMapPatch
             ╰─ patch
                ╰─ KeyAndSubPatch
                   ├─ Key
                   ╰─ BinaryPatch
                      ╰─ append
                         ╰─ Suffix
    )");
}

TEST(DebugTreeTest, AnyPatch) {
  MyStructPatch patch;
  patch.patchIfSet<ident::optBoolVal>().invert();
  StructWithAnyPatch anyPatch;
  anyPatch.patch<ident::any>().patchIfTypeIs(patch);

  Def def;
  def.field() = 42;
  anyPatch.patch<ident::any>().ensureAny(type::AnyData::toAny(def).toThrift());

  expectEq(debugTree(anyPatch, getGraph()), R"(
    DynamicStructPatch
    ├─ ensure
    │  ╰─ any
    │     ╰─ <Maybe Empty Thrift.Any>
    ╰─ patch
       ╰─ any
          ╰─ AnyPatch
             ├─ patchIfTypeIs
             │  ╰─ type: struct<MyStruct>
             │     ╰─ UnknownPatch
             │        ╰─ patch
             │           ╰─ optBoolVal
             │              ╰─ BoolPatch
             │                 ╰─ invert
             ╰─ ensure
                ╰─ <Thrift.Any, type=struct<Def>, protocol=Compact>
                   ╰─ Definition(kind=Struct, name='Def', program='DebugTree.thrift')
                      ╰─ field
                         ╰─ 42
    )");
}

} // namespace apache::thrift::detail
