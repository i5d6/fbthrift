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

#include <thrift/lib/cpp2/util/DebugTree.h>

#include <thrift/lib/cpp2/type/NativeType.h>

using namespace apache::thrift::schema;

namespace apache::thrift::detail {
namespace {

// Return the field node in Structured based on FieldId
// * If not found or StructuredNode is null, returns nullptr.
const FieldNode* FOLLY_NULLABLE
getField(const StructuredNode* node, FieldId id) {
  if (!node) {
    return nullptr;
  }
  for (const auto& i : node->fields()) {
    if (i.id() == id) {
      return &i;
    }
  }
  return nullptr;
}

// Return the field name in Structured based on FieldId
// * If not found or StructuredNode is null, returns field id number.
std::string getFieldName(const StructuredNode* node, FieldId id) {
  if (auto field = getField(node, id)) {
    return std::string{field->name()};
  }
  return fmt::format("FieldId({})", folly::to_underlying(id));
}

// Return the field type in Structured based on FieldId
// * If not found or StructuredNode is null, returns nullopt.
OptionalTypeRef getFieldType(const StructuredNode* node, FieldId id) {
  if (auto field = getField(node, id)) {
    return field->type();
  }
  return {};
}

// Return the element type in a list typeref.
// * If typeref is not list, returns nullopt.
OptionalTypeRef getListElem(const OptionalTypeRef& typeref) {
  if (typeref && typeref->isList()) {
    return typeref->asList().elementType();
  }

  return {};
}

// Return the element type in a set typeref.
// * If typeref is not set, returns nullptr.
OptionalTypeRef getSetElem(const OptionalTypeRef& typeref) {
  if (typeref && typeref->isSet()) {
    return typeref->asSet().elementType();
  }

  return {};
}

// Return the key type in a map typeref.
// * If typeref is not map, returns nullptr.
OptionalTypeRef getMapKey(const OptionalTypeRef& typeref) {
  if (typeref && typeref->isMap()) {
    return typeref->asMap().keyType();
  }

  return {};
}

// Return the value type in a map typeref.
// * If typeref is not map, returns nullptr.
OptionalTypeRef getMapValue(const OptionalTypeRef& typeref) {
  if (typeref && typeref->isMap()) {
    return typeref->asMap().valueType();
  }

  return {};
}

const protocol::Object& emptyAny() {
  static const protocol::Object ret =
      protocol::asValueStruct<type::struct_t<type::AnyStruct>>({}).as_object();
  return ret;
}

// Deserialize protocol::Object to an AnyStruct.
std::optional<type::AnyStruct> ifAny(
    const protocol::Object& object, const OptionalTypeRef& ref) {
  try {
    if (ref) {
      auto type = ref->trueType();
      if (!type.isStruct() ||
          type.asStruct().uri() != apache::thrift::uri<type::AnyStruct>()) {
        // The type is not Any
        return {};
      }
    }
  } catch (apache::thrift::schema::InvalidSyntaxGraphError&) {
    // If we can't dereference the type, it might be Any.
  }

  type::AnyStruct any;
  if (object == emptyAny()) {
    // We need special logic to handle empty any -- it's only considered Any
    // if it matches the schema exactly.
    return any;
  }
  if (protocol::detail::ProtocolValueToThriftValue<
          type::struct_t<type::AnyStruct>>{}(object, any) &&
      any.type()->isValid()) {
    return any;
  }
  return {};
}

const schema::StructuredNode* FOLLY_NULLABLE
ifStructured(const OptionalTypeRef& typeref) {
  if (typeref && typeref->isStructured()) {
    return &typeref->asStructured();
  }

  return nullptr;
}

std::string getFieldName(const OptionalTypeRef& type, FieldId id) {
  return getFieldName(ifStructured(type), id);
}

auto getFieldType(const OptionalTypeRef& type, FieldId id) {
  return getFieldType(ifStructured(type), id);
}

// Change unprintable char to \xhh where hh is the hex value of the char.
std::string escape(std::string_view s) {
  std::string ret;
  for (char c : s) {
    if (std::isprint(c)) {
      ret += c;
    } else {
      ret += fmt::format("\\x{:x}", c);
    }
  }
  return ret;
}
} // namespace

std::unordered_map<std::string, TypeRef> SGWrapper::genUriToTypeRef() const {
  std::unordered_map<std::string, TypeRef> ret;
  for (auto p : programs()) {
    for (auto d : p->definitions()) {
      d->visit([&](auto& def) {
        if constexpr (__FBTHRIFT_IS_VALID(def, def.uri(), TypeRef::of(def))) {
          ret.emplace(def.uri(), TypeRef::of(def));
        }
      });
    }
  }
  return ret;
}
OptionalTypeRef SGWrapper::findType(const Uri& uri) const {
  if (auto p = folly::get_ptr(uriToType_, uri.uri)) {
    return *p;
  }

  return {};
}

OptionalTypeRef SGWrapper::findTypeInAny(const type::TypeStruct& type) const {
  const type::TypeUri* uri = nullptr;
  switch (auto t = type.name()->getType()) {
    case type::TypeName::Type::structType:
      uri = &*type.name()->structType_ref();
      break;
    case type::TypeName::Type::unionType:
      uri = &*type.name()->unionType_ref();
      break;
    default:
      return {};
  }
  return uri && uri->uri_ref() ? findType(Uri{*uri->uri_ref()}) : std::nullopt;
}

scope DebugTree<std::string>::operator()(
    const std::string& buf, const SGWrapper&, const OptionalTypeRef&) {
  if (buf.empty()) {
    return scope::make_root("\"\"");
  }
  return scope::make_root("{}", escape(buf));
}

scope DebugTree<folly::IOBuf>::operator()(
    const folly::IOBuf& buf,
    const SGWrapper& graph,
    const OptionalTypeRef& type) {
  return debugTree(buf.toString(), graph, type);
}

scope DebugTree<protocol::ValueList>::operator()(
    const protocol::ValueList& v,
    const SGWrapper& graph,
    const OptionalTypeRef& typeref) {
  auto msg = scope::make_root("<List>");
  for (auto& i : v) {
    msg.make_child() = debugTree(i, graph, getListElem(typeref));
  }
  return msg;
}

scope DebugTree<protocol::ValueSet>::operator()(
    const protocol::ValueSet& set,
    const SGWrapper& graph,
    const OptionalTypeRef& typeref) {
  std::vector<const protocol::Value*> keys;
  for (const auto& k : set) {
    keys.push_back(&k);
  }

  // always output keys in order
  std::sort(keys.begin(), keys.end(), [](auto* lhs, auto* rhs) {
    return *lhs < *rhs;
  });

  auto msg = scope::make_root("<Set>");
  for (auto& k : keys) {
    msg.make_child() = debugTree(*k, graph, getSetElem(typeref));
  }
  return msg;
}

scope DebugTree<protocol::ValueMap>::operator()(
    const protocol::ValueMap& map,
    const SGWrapper& graph,
    const OptionalTypeRef& typeref) {
  std::vector<const protocol::Value*> keys;
  for (const auto& [k, _] : map) {
    keys.push_back(&k);
  }

  // always output keys in order
  std::sort(keys.begin(), keys.end(), [](auto* lhs, auto* rhs) {
    return *lhs < *rhs;
  });

  auto msg = scope::make_root("<Map>");
  for (size_t i = 0; i < keys.size(); ++i) {
    auto key = scope::make_root("Key #{}", i);
    const auto& k = *keys[i];
    key.make_child() = debugTree(k, graph, getMapKey(typeref));

    auto value = scope::make_root("Value #{}", i);
    value.make_child() = debugTree(map.at(k), graph, getMapValue(typeref));
    msg.make_child() = std::move(key);
    msg.make_child() = std::move(value);
  }

  return msg;
}

scope DebugTree<protocol::Value>::operator()(
    const protocol::Value& value,
    const SGWrapper& graph,
    const OptionalTypeRef& typeref) {
  auto v = scope::make_root("<EMPTY PROTOCOL::VALUE>");
  op::for_each_field_id<protocol::detail::detail::Value>([&](auto ord) {
    if (auto p = op::get<decltype(ord)>(value.toThrift())) {
      v = debugTree(*p, graph, typeref);
    }
  });
  return v;
}

namespace {
std::string toDebugString(const DefinitionNode& definition) {
  std::string_view kindString = definition.visit(
      [](const StructNode&) { return "Struct"; },
      [](const UnionNode&) { return "Union"; },
      [](const ExceptionNode&) { return "Exception"; },
      [](const EnumNode&) { return "Enum"; },
      [](const TypedefNode&) { return "Typedef"; },
      [](const ConstantNode&) { return "Constant"; },
      [](const ServiceNode&) { return "Service"; },
      [](const InteractionNode&) { return "Interaction"; });
  return fmt::format(
      "Definition(kind={}, name='{}', program='{}.thrift')",
      kindString,
      definition.name(),
      definition.program().name());
}
} // namespace

scope DebugTree<protocol::Object>::operator()(
    const protocol::Object& object,
    const SGWrapper& graph,
    const OptionalTypeRef& type) {
  if (auto any = ifAny(object, type)) {
    return debugTree(*any, graph);
  }

  std::set<FieldId> ids;
  for (auto& field : object) {
    ids.emplace(FieldId{field.first});
  }

  const auto* node = ifStructured(type);
  auto ret = scope::make_root(
      "{}", node ? toDebugString(node->definition()) : "<UNKNOWN STRUCT>");
  for (auto id : ids) {
    auto next = scope::make_root("{}", getFieldName(node, id));
    next.make_child() = debugTree(object.at(id), graph, getFieldType(node, id));
    ret.make_child() = std::move(next);
  }

  return ret;
}

scope DebugTree<type::AnyStruct>::operator()(
    const type::AnyStruct& any,
    const SGWrapper& graph,
    const OptionalTypeRef&) {
  if (any == type::AnyStruct{}) {
    return scope::make_root("<Maybe Empty Thrift.Any>");
  }
  auto ret = scope::make_root(
      "<Thrift.Any, type={}, protocol={}>",
      any.type()->debugString(),
      any.protocol()->name());

  // We used heuristic to check whether a struct is Any. However, it might not
  // be a real Any, in which case `parseValueFromAny` will probably throw and we
  // still want to print the data we have.
  try {
    // NOLINTNEXTLINE(facebook-hte-DetailCall)
    auto value = protocol::detail::parseValueFromAny(any);
    ret.make_child() =
        debugTree(value, graph, graph.findTypeInAny(any.type()->toThrift()));
  } catch (std::exception&) {
    ret.make_child() =
        debugTree(*any.data(), graph, TypeRef::of(Primitive::BINARY));
  }
  return ret;
}

namespace {
struct BasePatchVisitor {
  // One patch operation, which contains the operation name and data.
  // Some operations don't have associated data, e.g., clear operation:
  //
  //   PatchOperation(name = "clear")
  //
  // Non-combinable operations always have single data entity, e.g., assign
  // operation:
  //
  //   PatchOperation(
  //     name = "assign",
  //     data = {protocol::Value{}: AssigneData}
  //   )
  //
  // Combinable operations (e.g., patch, ensure, remove), might have multiple
  // data entities, e.g., for ensure operation
  //
  //   PatchOperation(
  //     name = "ensure",
  //     data = {Field1: Value1, Field2: Value2}
  //   )
  //
  // The motivation is combining multiple operations together to improve the
  // readability. e.g. multiple `ensure` operations can be combined since the
  // order of ensuring each field doesn't matter. In this case `key` would be
  // the field id so that the result is always sorted by field id.
  struct PatchOperation {
    std::string name;
    std::multimap<protocol::Value, scope> data = {};
  };

  template <class T>
  void assign(const T& t) {
    addOp("assign", t);
  }

  void clear() { addOp("clear"); }

  void addOp(std::string name) { ops.push_back({std::move(name)}); }

  void addOp(std::string name, scope data) {
    addOp(std::move(name));
    ops.back().data.emplace(protocol::Value{}, std::move(data));
  }

  template <class T>
  void addOp(std::string name, const T& data) {
    addOp(std::move(name), debugTree(data, graph, typeRef));
  }

  template <class T>
  void addOpIfNotEmpty(std::string name, const T& data) {
    if (!data.empty()) {
      addOp(name, data);
    }
  }

  // Whether the operation can be combined with the last one.
  void addCombinableOp(std::string name, protocol::Value key, scope data) {
    if (ops.empty() || ops.back().name != name) {
      addOp(std::move(name));
    }
    ops.back().data.emplace(std::move(key), std::move(data));
  }

  scope finalize(std::string name) {
    auto root = scope::make_root("{}", name);
    for (auto& op : ops) {
      scope node = scope::make_root("{}", std::move(op.name));
      for (auto& [k, v] : op.data) {
        node.make_child() = std::move(v);
      }
      root.make_child() = std::move(node);
    }
    return root;
  }

  const SGWrapper& graph;
  const OptionalTypeRef& typeRef;
  std::vector<PatchOperation> ops = {};
};
struct BaseStructuredPatchVisitor : BasePatchVisitor {
  protocol::Value toValue(FieldId id) {
    return protocol::asValueStruct<type::i16_t>(folly::to_underlying(id));
  }
  scope toNode(FieldId id) {
    return scope::make_root("{}", getFieldName(typeRef, id));
  }
  void patchIfSet(FieldId id, const protocol::DynamicPatch& patch) {
    auto node = toNode(id);
    node.make_child() = debugTree(patch, graph, getFieldType(typeRef, id));
    addCombinableOp("patch", toValue(id), std::move(node));
  }
};
} // namespace

scope DebugTree<op::BoolPatch>::operator()(
    const op::BoolPatch& patch,
    const SGWrapper& graph,
    const OptionalTypeRef& typeRef) {
  struct Visitor : BasePatchVisitor {
    void invert() { addOp(__func__); }
  };

  Visitor v{graph, typeRef};
  patch.customVisit(v);
  return v.finalize("BoolPatch");
}

template <class Patch>
static scope debugTreeForNumericPatch(
    const Patch& patch,
    const SGWrapper& graph,
    const OptionalTypeRef& typeRef,
    std::string name) {
  struct Visitor : BasePatchVisitor {
    void add(typename Patch::value_type t) {
      if (t != 0) {
        addOp(__func__, t);
      }
    }
  };

  Visitor v{graph, typeRef};
  patch.customVisit(v);
  return v.finalize(std::move(name));
}

scope DebugTree<op::BytePatch>::operator()(
    const op::BytePatch& patch,
    const SGWrapper& graph,
    const OptionalTypeRef& type) {
  return debugTreeForNumericPatch(patch, graph, type, "BytePatch");
}
scope DebugTree<op::I16Patch>::operator()(
    const op::I16Patch& patch,
    const SGWrapper& graph,
    const OptionalTypeRef& type) {
  return debugTreeForNumericPatch(patch, graph, type, "I16Patch");
}
scope DebugTree<op::I32Patch>::operator()(
    const op::I32Patch& patch,
    const SGWrapper& graph,
    const OptionalTypeRef& type) {
  return debugTreeForNumericPatch(patch, graph, type, "I32Patch");
}
scope DebugTree<op::I64Patch>::operator()(
    const op::I64Patch& patch,
    const SGWrapper& graph,
    const OptionalTypeRef& type) {
  return debugTreeForNumericPatch(patch, graph, type, "I64Patch");
}
scope DebugTree<op::FloatPatch>::operator()(
    const op::FloatPatch& patch,
    const SGWrapper& graph,
    const OptionalTypeRef& type) {
  return debugTreeForNumericPatch(patch, graph, type, "FloatPatch");
}
scope DebugTree<op::DoublePatch>::operator()(
    const op::DoublePatch& patch,
    const SGWrapper& graph,
    const OptionalTypeRef& type) {
  return debugTreeForNumericPatch(patch, graph, type, "DoublePatch");
}

template <class Patch>
static scope debugTreeForStringPatch(
    const Patch& patch,
    const SGWrapper& graph,
    const OptionalTypeRef& typeref,
    std::string name) {
  struct Visitor : BasePatchVisitor {
    void prepend(const std::string& s) { addOpIfNotEmpty(__func__, s); }
    void append(const std::string& s) { addOpIfNotEmpty(__func__, s); }
    void prepend(const folly::IOBuf& s) { addOpIfNotEmpty(__func__, s); }
    void append(const folly::IOBuf& s) { addOpIfNotEmpty(__func__, s); }
  };

  Visitor v{graph, typeref};
  patch.customVisit(v);
  return v.finalize(std::move(name));
}

scope DebugTree<op::StringPatch>::operator()(
    const op::StringPatch& patch,
    const SGWrapper& graph,
    const OptionalTypeRef& type) {
  return debugTreeForStringPatch(patch, graph, type, "StringPatch");
}
scope DebugTree<op::BinaryPatch>::operator()(
    const op::BinaryPatch& patch,
    const SGWrapper& graph,
    const OptionalTypeRef& type) {
  return debugTreeForStringPatch(patch, graph, type, "BinaryPatch");
}

scope DebugTree<protocol::DynamicListPatch>::operator()(
    const protocol::DynamicListPatch& patch,
    const SGWrapper& graph,
    const OptionalTypeRef& listType) {
  struct Visitor : BasePatchVisitor {
    void push_back(const protocol::Value& v) {
      addOp("push_back", debugTree(v, graph, getListElem(typeRef)));
    }
  };

  Visitor v{graph, listType};
  patch.customVisit(v);
  return v.finalize("DynamicListPatch");
}

scope DebugTree<protocol::DynamicSetPatch>::operator()(
    const protocol::DynamicSetPatch& patch,
    const SGWrapper& graph,
    const OptionalTypeRef& setType) {
  struct Visitor : BasePatchVisitor {
    void addMulti(const protocol::ValueSet& set) {
      addOpIfNotEmpty(__func__, set);
    }
    void removeMulti(const protocol::ValueSet& set) {
      addOpIfNotEmpty(__func__, set);
    }
  };

  Visitor v{graph, setType};
  patch.customVisit(v);
  return v.finalize("DynamicSetPatch");
}

scope DebugTree<protocol::DynamicMapPatch>::operator()(
    const protocol::DynamicMapPatch& patch,
    const SGWrapper& graph,
    const OptionalTypeRef& mapType) {
  struct Visitor : BasePatchVisitor {
    void tryPutMulti(const protocol::ValueMap& map) {
      addOpIfNotEmpty(__func__, map);
    }
    void removeMulti(const protocol::ValueSet& set) {
      if (set.empty()) {
        return;
      }
      if (auto mapKey = getMapKey(typeRef)) {
        auto type = TypeRef::of(schema::Set::of(*mapKey));
        addOp(__func__, debugTree(set, graph, type));
        return;
      }
      addOp(__func__, debugTree(set, graph));
    }
    void putMulti(const protocol::ValueMap& map) {
      addOpIfNotEmpty(__func__, map);
    }
    void patchByKey(
        const protocol::Value& k, const protocol::DynamicPatch& patch) {
      auto root = scope::make_root("KeyAndSubPatch");
      root.make_child() = debugTree(k, graph, getMapKey(typeRef));
      root.make_child() = debugTree(patch, graph, getMapKey(typeRef));
      addCombinableOp("patch", k, std::move(root));
    }
  };

  Visitor v{graph, mapType};
  patch.customVisit(v);
  return v.finalize("DynamicMapPatch");
}

template <bool IsUnion>
static scope debugTreeForDynamicStructurePatch(
    const protocol::DynamicStructurePatch<IsUnion>& patch,
    const SGWrapper& graph,
    const OptionalTypeRef& type) {
  struct Visitor : BaseStructuredPatchVisitor {
    void remove(FieldId id) {
      addCombinableOp("remove", toValue(id), toNode(id));
    }
    void ensure(FieldId id, const protocol::Value& v) {
      std::string op = IsUnion ? "ensureUnion" : "ensure";
      auto node = toNode(id);
      node.make_child() = debugTree(v, graph, getFieldType(typeRef, id));
      addCombinableOp(op, toValue(id), std::move(node));
    }
  };

  Visitor v{graph, type};
  patch.customVisit(v);
  return v.finalize(IsUnion ? "DynamicUnionPatch" : "DynamicStructPatch");
}

scope DebugTree<protocol::DynamicStructPatch>::operator()(
    const protocol::DynamicStructPatch& patch,
    const SGWrapper& graph,
    const OptionalTypeRef& type) {
  return debugTreeForDynamicStructurePatch(patch, graph, type);
}

scope DebugTree<protocol::DynamicUnionPatch>::operator()(
    const protocol::DynamicUnionPatch& patch,
    const SGWrapper& graph,
    const OptionalTypeRef& type) {
  return debugTreeForDynamicStructurePatch(patch, graph, type);
}

scope DebugTree<protocol::DynamicUnknownPatch>::operator()(
    const protocol::DynamicUnknownPatch& patch,
    const SGWrapper& graph,
    const OptionalTypeRef& type) {
  struct Visitor : BaseStructuredPatchVisitor {
    void removeMulti(const protocol::ValueSet& set) {
      if (set.empty()) {
        return;
      }
      OptionalTypeRef elem = typeRef;
      if (typeRef && typeRef->isMap()) {
        elem = TypeRef::of(schema::Set::of(*getMapKey(typeRef)));
      }
      protocol::Value v;
      v.emplace_set(set);
      addOp(__func__, debugTree(v, graph, elem));
    }
  };

  Visitor v{graph, type};
  patch.customVisit(v);
  return v.finalize("UnknownPatch");
}

scope DebugTree<op::AnyPatch>::operator()(
    const op::AnyPatch& patch,
    const SGWrapper& graph,
    const OptionalTypeRef& typeref) {
  struct Visitor : BasePatchVisitor {
    void ensureAny(const type::AnyStruct& any) { addOp("ensure", any); }
    void patchIfTypeIs(
        const type::Type& type, const protocol::DynamicPatch& patch) {
      auto node = scope::make_root("{}", "type: " + type.debugString());
      node.make_child() =
          debugTree(patch, graph, graph.findTypeInAny(type.toThrift()));
      addCombinableOp(
          "patchIfTypeIs",
          protocol::asValueStruct<type::infer_tag<type::Type>>(type),
          std::move(node));
    }
  };

  Visitor v{graph, typeref};
  patch.customVisit(v);
  return v.finalize("AnyPatch");
}

scope DebugTree<protocol::DynamicPatch>::operator()(
    const protocol::DynamicPatch& patch,
    const SGWrapper& graph,
    const OptionalTypeRef& type) {
  return patch.visitPatch(
      [&](const auto& patch) { return debugTree(patch, graph, type); });
}
} // namespace apache::thrift::detail
