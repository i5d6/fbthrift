#
# Autogenerated by Thrift for thrift/compiler/test/fixtures/py3/src/module.thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#
cimport cython as __cython
from cython.operator cimport dereference as deref
from libcpp.utility cimport move as cmove
from thrift.py3.types cimport (
    assign_unique_ptr,
    assign_shared_ptr,
    assign_shared_const_ptr,
    bytes_to_string,
    make_unique,
    make_shared,
    make_const_shared,
)
cimport thrift.py3.types
from thrift.py3.types cimport (
    reset_field as __reset_field,
    StructFieldsSetter as __StructFieldsSetter
)

from thrift.py3.types cimport const_pointer_cast
from thrift.python.types cimport BadEnum as _fbthrift_BadEnum
from thrift.py3.types import _from_python_or_raise


import module.types as _module_types


@__cython.auto_pickle(False)
cdef class __SimpleException_FieldsSetter(__StructFieldsSetter):

    @staticmethod
    cdef __SimpleException_FieldsSetter _fbthrift_create(_module_cbindings.cSimpleException* struct_cpp_obj):
        cdef __SimpleException_FieldsSetter __fbthrift_inst = __SimpleException_FieldsSetter.__new__(__SimpleException_FieldsSetter)
        __fbthrift_inst._struct_cpp_obj = struct_cpp_obj
        __fbthrift_inst._setters[__cstring_view(<const char*>"err_code")] = __SimpleException_FieldsSetter._set_field_0
        return __fbthrift_inst

    cdef void set_field(__SimpleException_FieldsSetter self, const char* name, object value) except *:
        cdef __cstring_view cname = __cstring_view(name)
        cdef cumap[__cstring_view, __SimpleException_FieldsSetterFunc].iterator found = self._setters.find(cname)
        if found == self._setters.end():
            raise TypeError(f"invalid field name {name.decode('utf-8')}")
        deref(found).second(self, value)

    cdef void _set_field_0(self, _fbthrift_value) except *:
        # for field err_code
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cSimpleException](deref(self._struct_cpp_obj), 0)
            return
        if not isinstance(_fbthrift_value, int):
            raise TypeError(f'err_code is not a { int !r}.')
        _fbthrift_value = <cint16_t> _fbthrift_value
        deref(self._struct_cpp_obj).err_code_ref().assign(_fbthrift_value)


@__cython.auto_pickle(False)
cdef class __OptionalRefStruct_FieldsSetter(__StructFieldsSetter):

    @staticmethod
    cdef __OptionalRefStruct_FieldsSetter _fbthrift_create(_module_cbindings.cOptionalRefStruct* struct_cpp_obj):
        cdef __OptionalRefStruct_FieldsSetter __fbthrift_inst = __OptionalRefStruct_FieldsSetter.__new__(__OptionalRefStruct_FieldsSetter)
        __fbthrift_inst._struct_cpp_obj = struct_cpp_obj
        __fbthrift_inst._setters[__cstring_view(<const char*>"optional_blob")] = __OptionalRefStruct_FieldsSetter._set_field_0
        return __fbthrift_inst

    cdef void set_field(__OptionalRefStruct_FieldsSetter self, const char* name, object value) except *:
        cdef __cstring_view cname = __cstring_view(name)
        cdef cumap[__cstring_view, __OptionalRefStruct_FieldsSetterFunc].iterator found = self._setters.find(cname)
        if found == self._setters.end():
            raise TypeError(f"invalid field name {name.decode('utf-8')}")
        deref(found).second(self, value)

    cdef void _set_field_0(self, _fbthrift_value) except *:
        # for field optional_blob
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cOptionalRefStruct](deref(self._struct_cpp_obj), 0)
            return
        if not isinstance(_fbthrift_value, _fbthrift_iobuf.IOBuf):
            raise TypeError(f'optional_blob is not a { _fbthrift_iobuf.IOBuf !r}.')
        deref(self._struct_cpp_obj).optional_blob_ref().assign((<_fbthrift_iobuf.IOBuf?>_fbthrift_value).c_clone())


@__cython.auto_pickle(False)
cdef class __SimpleStruct_FieldsSetter(__StructFieldsSetter):

    @staticmethod
    cdef __SimpleStruct_FieldsSetter _fbthrift_create(_module_cbindings.cSimpleStruct* struct_cpp_obj):
        cdef __SimpleStruct_FieldsSetter __fbthrift_inst = __SimpleStruct_FieldsSetter.__new__(__SimpleStruct_FieldsSetter)
        __fbthrift_inst._struct_cpp_obj = struct_cpp_obj
        __fbthrift_inst._setters[__cstring_view(<const char*>"is_on")] = __SimpleStruct_FieldsSetter._set_field_0
        __fbthrift_inst._setters[__cstring_view(<const char*>"tiny_int")] = __SimpleStruct_FieldsSetter._set_field_1
        __fbthrift_inst._setters[__cstring_view(<const char*>"small_int")] = __SimpleStruct_FieldsSetter._set_field_2
        __fbthrift_inst._setters[__cstring_view(<const char*>"nice_sized_int")] = __SimpleStruct_FieldsSetter._set_field_3
        __fbthrift_inst._setters[__cstring_view(<const char*>"big_int")] = __SimpleStruct_FieldsSetter._set_field_4
        __fbthrift_inst._setters[__cstring_view(<const char*>"real")] = __SimpleStruct_FieldsSetter._set_field_5
        __fbthrift_inst._setters[__cstring_view(<const char*>"smaller_real")] = __SimpleStruct_FieldsSetter._set_field_6
        __fbthrift_inst._setters[__cstring_view(<const char*>"something")] = __SimpleStruct_FieldsSetter._set_field_7
        __fbthrift_inst._setters[__cstring_view(<const char*>"opt_default_int")] = __SimpleStruct_FieldsSetter._set_field_8
        __fbthrift_inst._setters[__cstring_view(<const char*>"opt_default_str")] = __SimpleStruct_FieldsSetter._set_field_9
        __fbthrift_inst._setters[__cstring_view(<const char*>"opt_default_enum")] = __SimpleStruct_FieldsSetter._set_field_10
        return __fbthrift_inst

    cdef void set_field(__SimpleStruct_FieldsSetter self, const char* name, object value) except *:
        cdef __cstring_view cname = __cstring_view(name)
        cdef cumap[__cstring_view, __SimpleStruct_FieldsSetterFunc].iterator found = self._setters.find(cname)
        if found == self._setters.end():
            raise TypeError(f"invalid field name {name.decode('utf-8')}")
        deref(found).second(self, value)

    cdef void _set_field_0(self, _fbthrift_value) except *:
        # for field is_on
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cSimpleStruct](deref(self._struct_cpp_obj), 0)
            return
        if not isinstance(_fbthrift_value, bool):
            raise TypeError(f'is_on is not a { bool !r}.')
        deref(self._struct_cpp_obj).is_on_ref().assign(_fbthrift_value)

    cdef void _set_field_1(self, _fbthrift_value) except *:
        # for field tiny_int
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cSimpleStruct](deref(self._struct_cpp_obj), 1)
            return
        if not isinstance(_fbthrift_value, int):
            raise TypeError(f'tiny_int is not a { int !r}.')
        _fbthrift_value = <cint8_t> _fbthrift_value
        deref(self._struct_cpp_obj).tiny_int_ref().assign(_fbthrift_value)

    cdef void _set_field_2(self, _fbthrift_value) except *:
        # for field small_int
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cSimpleStruct](deref(self._struct_cpp_obj), 2)
            return
        if not isinstance(_fbthrift_value, int):
            raise TypeError(f'small_int is not a { int !r}.')
        _fbthrift_value = <cint16_t> _fbthrift_value
        deref(self._struct_cpp_obj).small_int_ref().assign(_fbthrift_value)

    cdef void _set_field_3(self, _fbthrift_value) except *:
        # for field nice_sized_int
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cSimpleStruct](deref(self._struct_cpp_obj), 3)
            return
        if not isinstance(_fbthrift_value, int):
            raise TypeError(f'nice_sized_int is not a { int !r}.')
        _fbthrift_value = <cint32_t> _fbthrift_value
        deref(self._struct_cpp_obj).nice_sized_int_ref().assign(_fbthrift_value)

    cdef void _set_field_4(self, _fbthrift_value) except *:
        # for field big_int
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cSimpleStruct](deref(self._struct_cpp_obj), 4)
            return
        if not isinstance(_fbthrift_value, int):
            raise TypeError(f'big_int is not a { int !r}.')
        _fbthrift_value = <cint64_t> _fbthrift_value
        deref(self._struct_cpp_obj).big_int_ref().assign(_fbthrift_value)

    cdef void _set_field_5(self, _fbthrift_value) except *:
        # for field real
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cSimpleStruct](deref(self._struct_cpp_obj), 5)
            return
        if not isinstance(_fbthrift_value, (float, int)):
            raise TypeError(f'real is not a { float !r}.')
        deref(self._struct_cpp_obj).real_ref().assign(_fbthrift_value)

    cdef void _set_field_6(self, _fbthrift_value) except *:
        # for field smaller_real
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cSimpleStruct](deref(self._struct_cpp_obj), 6)
            return
        if not isinstance(_fbthrift_value, (float, int)):
            raise TypeError(f'smaller_real is not a { float !r}.')
        deref(self._struct_cpp_obj).smaller_real_ref().assign(_fbthrift_value)

    cdef void _set_field_7(self, _fbthrift_value) except *:
        # for field something
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cSimpleStruct](deref(self._struct_cpp_obj), 7)
            return
        deref(self._struct_cpp_obj).something_ref().assign(_module_types._std_unordered_map__Map__i32_i32__make_instance(_fbthrift_value))

    cdef void _set_field_8(self, _fbthrift_value) except *:
        # for field opt_default_int
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cSimpleStruct](deref(self._struct_cpp_obj), 8)
            return
        if not isinstance(_fbthrift_value, int):
            raise TypeError(f'opt_default_int is not a { int !r}.')
        _fbthrift_value = <cint32_t> _fbthrift_value
        deref(self._struct_cpp_obj).opt_default_int_ref().assign(_fbthrift_value)

    cdef void _set_field_9(self, _fbthrift_value) except *:
        # for field opt_default_str
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cSimpleStruct](deref(self._struct_cpp_obj), 9)
            return
        if not isinstance(_fbthrift_value, str):
            raise TypeError(f'opt_default_str is not a { str !r}.')
        deref(self._struct_cpp_obj).opt_default_str_ref().assign(cmove(bytes_to_string(_fbthrift_value.encode('utf-8'))))

    cdef void _set_field_10(self, _fbthrift_value) except *:
        # for field opt_default_enum
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cSimpleStruct](deref(self._struct_cpp_obj), 10)
            return
        if not isinstance(_fbthrift_value, _fbthrift_BadEnum) and not isinstance(_fbthrift_value, _module_types.AnEnum):
            raise TypeError(f'field opt_default_enum value: {repr(_fbthrift_value)} is not of the enum type { _module_types.AnEnum }.')
        deref(self._struct_cpp_obj).opt_default_enum_ref().assign(<_module_cbindings.cAnEnum><int>_fbthrift_value)


@__cython.auto_pickle(False)
cdef class __HiddenTypeFieldsStruct_FieldsSetter(__StructFieldsSetter):

    @staticmethod
    cdef __HiddenTypeFieldsStruct_FieldsSetter _fbthrift_create(_module_cbindings.cHiddenTypeFieldsStruct* struct_cpp_obj):
        cdef __HiddenTypeFieldsStruct_FieldsSetter __fbthrift_inst = __HiddenTypeFieldsStruct_FieldsSetter.__new__(__HiddenTypeFieldsStruct_FieldsSetter)
        __fbthrift_inst._struct_cpp_obj = struct_cpp_obj
        return __fbthrift_inst

    cdef void set_field(__HiddenTypeFieldsStruct_FieldsSetter self, const char* name, object value) except *:
        cdef __cstring_view cname = __cstring_view(name)
        cdef cumap[__cstring_view, __HiddenTypeFieldsStruct_FieldsSetterFunc].iterator found = self._setters.find(cname)
        if found == self._setters.end():
            raise TypeError(f"invalid field name {name.decode('utf-8')}")
        deref(found).second(self, value)


@__cython.auto_pickle(False)
cdef class __ComplexStruct_FieldsSetter(__StructFieldsSetter):

    @staticmethod
    cdef __ComplexStruct_FieldsSetter _fbthrift_create(_module_cbindings.cComplexStruct* struct_cpp_obj):
        cdef __ComplexStruct_FieldsSetter __fbthrift_inst = __ComplexStruct_FieldsSetter.__new__(__ComplexStruct_FieldsSetter)
        __fbthrift_inst._struct_cpp_obj = struct_cpp_obj
        __fbthrift_inst._setters[__cstring_view(<const char*>"structOne")] = __ComplexStruct_FieldsSetter._set_field_0
        __fbthrift_inst._setters[__cstring_view(<const char*>"structTwo")] = __ComplexStruct_FieldsSetter._set_field_1
        __fbthrift_inst._setters[__cstring_view(<const char*>"an_integer")] = __ComplexStruct_FieldsSetter._set_field_2
        __fbthrift_inst._setters[__cstring_view(<const char*>"name")] = __ComplexStruct_FieldsSetter._set_field_3
        __fbthrift_inst._setters[__cstring_view(<const char*>"an_enum")] = __ComplexStruct_FieldsSetter._set_field_4
        __fbthrift_inst._setters[__cstring_view(<const char*>"some_bytes")] = __ComplexStruct_FieldsSetter._set_field_5
        __fbthrift_inst._setters[__cstring_view(<const char*>"sender")] = __ComplexStruct_FieldsSetter._set_field_6
        __fbthrift_inst._setters[__cstring_view(<const char*>"cdef_")] = __ComplexStruct_FieldsSetter._set_field_7
        __fbthrift_inst._setters[__cstring_view(<const char*>"bytes_with_cpp_type")] = __ComplexStruct_FieldsSetter._set_field_8
        return __fbthrift_inst

    cdef void set_field(__ComplexStruct_FieldsSetter self, const char* name, object value) except *:
        cdef __cstring_view cname = __cstring_view(name)
        cdef cumap[__cstring_view, __ComplexStruct_FieldsSetterFunc].iterator found = self._setters.find(cname)
        if found == self._setters.end():
            raise TypeError(f"invalid field name {name.decode('utf-8')}")
        deref(found).second(self, value)

    cdef void _set_field_0(self, _fbthrift_value) except *:
        # for field structOne
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cComplexStruct](deref(self._struct_cpp_obj), 0)
            return
        if not isinstance(_fbthrift_value, _module_types.SimpleStruct):
            _fbthrift_value = _from_python_or_raise(_fbthrift_value, "structOne", _module_types.SimpleStruct)
        deref(self._struct_cpp_obj).structOne_ref().assign(deref((<_module_types.SimpleStruct?> _fbthrift_value)._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE))

    cdef void _set_field_1(self, _fbthrift_value) except *:
        # for field structTwo
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cComplexStruct](deref(self._struct_cpp_obj), 1)
            return
        if not isinstance(_fbthrift_value, _module_types.SimpleStruct):
            _fbthrift_value = _from_python_or_raise(_fbthrift_value, "structTwo", _module_types.SimpleStruct)
        deref(self._struct_cpp_obj).structTwo_ref().assign(deref((<_module_types.SimpleStruct?> _fbthrift_value)._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE))

    cdef void _set_field_2(self, _fbthrift_value) except *:
        # for field an_integer
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cComplexStruct](deref(self._struct_cpp_obj), 2)
            return
        if not isinstance(_fbthrift_value, int):
            raise TypeError(f'an_integer is not a { int !r}.')
        _fbthrift_value = <cint32_t> _fbthrift_value
        deref(self._struct_cpp_obj).an_integer_ref().assign(_fbthrift_value)

    cdef void _set_field_3(self, _fbthrift_value) except *:
        # for field name
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cComplexStruct](deref(self._struct_cpp_obj), 3)
            return
        if not isinstance(_fbthrift_value, str):
            raise TypeError(f'name is not a { str !r}.')
        deref(self._struct_cpp_obj).name_ref().assign(cmove(bytes_to_string(_fbthrift_value.encode('utf-8'))))

    cdef void _set_field_4(self, _fbthrift_value) except *:
        # for field an_enum
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cComplexStruct](deref(self._struct_cpp_obj), 4)
            return
        if not isinstance(_fbthrift_value, _fbthrift_BadEnum) and not isinstance(_fbthrift_value, _module_types.AnEnum):
            raise TypeError(f'field an_enum value: {repr(_fbthrift_value)} is not of the enum type { _module_types.AnEnum }.')
        deref(self._struct_cpp_obj).an_enum_ref().assign(<_module_cbindings.cAnEnum><int>_fbthrift_value)

    cdef void _set_field_5(self, _fbthrift_value) except *:
        # for field some_bytes
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cComplexStruct](deref(self._struct_cpp_obj), 5)
            return
        if not isinstance(_fbthrift_value, bytes):
            raise TypeError(f'some_bytes is not a { bytes !r}.')
        deref(self._struct_cpp_obj).some_bytes_ref().assign(cmove(bytes_to_string(_fbthrift_value)))

    cdef void _set_field_6(self, _fbthrift_value) except *:
        # for field sender
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cComplexStruct](deref(self._struct_cpp_obj), 6)
            return
        if not isinstance(_fbthrift_value, str):
            raise TypeError(f'sender is not a { str !r}.')
        deref(self._struct_cpp_obj).sender_ref().assign(cmove(bytes_to_string(_fbthrift_value.encode('utf-8'))))

    cdef void _set_field_7(self, _fbthrift_value) except *:
        # for field cdef_
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cComplexStruct](deref(self._struct_cpp_obj), 7)
            return
        if not isinstance(_fbthrift_value, str):
            raise TypeError(f'cdef_ is not a { str !r}.')
        deref(self._struct_cpp_obj).cdef__ref().assign(cmove(bytes_to_string(_fbthrift_value.encode('utf-8'))))

    cdef void _set_field_8(self, _fbthrift_value) except *:
        # for field bytes_with_cpp_type
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cComplexStruct](deref(self._struct_cpp_obj), 8)
            return
        if not isinstance(_fbthrift_value, bytes):
            raise TypeError(f'bytes_with_cpp_type is not a { bytes !r}.')
        deref(self._struct_cpp_obj).bytes_with_cpp_type_ref().assign(_module_cbindings.foo_Bar(cmove(<string>_fbthrift_value)))


@__cython.auto_pickle(False)
cdef class __BinaryUnionStruct_FieldsSetter(__StructFieldsSetter):

    @staticmethod
    cdef __BinaryUnionStruct_FieldsSetter _fbthrift_create(_module_cbindings.cBinaryUnionStruct* struct_cpp_obj):
        cdef __BinaryUnionStruct_FieldsSetter __fbthrift_inst = __BinaryUnionStruct_FieldsSetter.__new__(__BinaryUnionStruct_FieldsSetter)
        __fbthrift_inst._struct_cpp_obj = struct_cpp_obj
        __fbthrift_inst._setters[__cstring_view(<const char*>"u")] = __BinaryUnionStruct_FieldsSetter._set_field_0
        return __fbthrift_inst

    cdef void set_field(__BinaryUnionStruct_FieldsSetter self, const char* name, object value) except *:
        cdef __cstring_view cname = __cstring_view(name)
        cdef cumap[__cstring_view, __BinaryUnionStruct_FieldsSetterFunc].iterator found = self._setters.find(cname)
        if found == self._setters.end():
            raise TypeError(f"invalid field name {name.decode('utf-8')}")
        deref(found).second(self, value)

    cdef void _set_field_0(self, _fbthrift_value) except *:
        # for field u
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cBinaryUnionStruct](deref(self._struct_cpp_obj), 0)
            return
        if not isinstance(_fbthrift_value, _module_types.BinaryUnion):
            _fbthrift_value = _from_python_or_raise(_fbthrift_value, "u", _module_types.BinaryUnion)
        deref(self._struct_cpp_obj).u_ref().assign(deref((<_module_types.BinaryUnion?> _fbthrift_value)._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE))


@__cython.auto_pickle(False)
cdef class __CustomFields_FieldsSetter(__StructFieldsSetter):

    @staticmethod
    cdef __CustomFields_FieldsSetter _fbthrift_create(_module_cbindings.cCustomFields* struct_cpp_obj):
        cdef __CustomFields_FieldsSetter __fbthrift_inst = __CustomFields_FieldsSetter.__new__(__CustomFields_FieldsSetter)
        __fbthrift_inst._struct_cpp_obj = struct_cpp_obj
        __fbthrift_inst._setters[__cstring_view(<const char*>"bool_field")] = __CustomFields_FieldsSetter._set_field_0
        __fbthrift_inst._setters[__cstring_view(<const char*>"integer_field")] = __CustomFields_FieldsSetter._set_field_1
        __fbthrift_inst._setters[__cstring_view(<const char*>"double_field")] = __CustomFields_FieldsSetter._set_field_2
        __fbthrift_inst._setters[__cstring_view(<const char*>"string_field")] = __CustomFields_FieldsSetter._set_field_3
        __fbthrift_inst._setters[__cstring_view(<const char*>"binary_field")] = __CustomFields_FieldsSetter._set_field_4
        __fbthrift_inst._setters[__cstring_view(<const char*>"list_field")] = __CustomFields_FieldsSetter._set_field_5
        __fbthrift_inst._setters[__cstring_view(<const char*>"set_field")] = __CustomFields_FieldsSetter._set_field_6
        __fbthrift_inst._setters[__cstring_view(<const char*>"map_field")] = __CustomFields_FieldsSetter._set_field_7
        __fbthrift_inst._setters[__cstring_view(<const char*>"struct_field")] = __CustomFields_FieldsSetter._set_field_8
        return __fbthrift_inst

    cdef void set_field(__CustomFields_FieldsSetter self, const char* name, object value) except *:
        cdef __cstring_view cname = __cstring_view(name)
        cdef cumap[__cstring_view, __CustomFields_FieldsSetterFunc].iterator found = self._setters.find(cname)
        if found == self._setters.end():
            raise TypeError(f"invalid field name {name.decode('utf-8')}")
        deref(found).second(self, value)

    cdef void _set_field_0(self, _fbthrift_value) except *:
        # for field bool_field
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cCustomFields](deref(self._struct_cpp_obj), 0)
            return
        if not isinstance(_fbthrift_value, bool):
            raise TypeError(f'bool_field is not a { bool !r}.')
        deref(self._struct_cpp_obj).bool_field_ref().assign(_fbthrift_value)

    cdef void _set_field_1(self, _fbthrift_value) except *:
        # for field integer_field
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cCustomFields](deref(self._struct_cpp_obj), 1)
            return
        if not isinstance(_fbthrift_value, int):
            raise TypeError(f'integer_field is not a { int !r}.')
        _fbthrift_value = <cint64_t> _fbthrift_value
        deref(self._struct_cpp_obj).integer_field_ref().assign(_fbthrift_value)

    cdef void _set_field_2(self, _fbthrift_value) except *:
        # for field double_field
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cCustomFields](deref(self._struct_cpp_obj), 2)
            return
        if not isinstance(_fbthrift_value, (float, int)):
            raise TypeError(f'double_field is not a { float !r}.')
        deref(self._struct_cpp_obj).double_field_ref().assign(_fbthrift_value)

    cdef void _set_field_3(self, _fbthrift_value) except *:
        # for field string_field
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cCustomFields](deref(self._struct_cpp_obj), 3)
            return
        if not isinstance(_fbthrift_value, str):
            raise TypeError(f'string_field is not a { str !r}.')
        deref(self._struct_cpp_obj).string_field_ref().assign(cmove(bytes_to_string(_fbthrift_value.encode('utf-8'))))

    cdef void _set_field_4(self, _fbthrift_value) except *:
        # for field binary_field
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cCustomFields](deref(self._struct_cpp_obj), 4)
            return
        if not isinstance(_fbthrift_value, bytes):
            raise TypeError(f'binary_field is not a { bytes !r}.')
        deref(self._struct_cpp_obj).binary_field_ref().assign(_module_cbindings._MyType(cmove(<string>_fbthrift_value)))

    cdef void _set_field_5(self, _fbthrift_value) except *:
        # for field list_field
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cCustomFields](deref(self._struct_cpp_obj), 5)
            return
        deref(self._struct_cpp_obj).list_field_ref().assign(_module_types._MyType__List__i32__make_instance(_fbthrift_value))

    cdef void _set_field_6(self, _fbthrift_value) except *:
        # for field set_field
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cCustomFields](deref(self._struct_cpp_obj), 6)
            return
        deref(self._struct_cpp_obj).set_field_ref().assign(_module_types._MyType__Set__i32__make_instance(_fbthrift_value))

    cdef void _set_field_7(self, _fbthrift_value) except *:
        # for field map_field
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cCustomFields](deref(self._struct_cpp_obj), 7)
            return
        deref(self._struct_cpp_obj).map_field_ref().assign(_module_types._MyType__Map__i32_i32__make_instance(_fbthrift_value))

    cdef void _set_field_8(self, _fbthrift_value) except *:
        # for field struct_field
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cCustomFields](deref(self._struct_cpp_obj), 8)
            return
        if not isinstance(_fbthrift_value, _module_types.SimpleStruct):
            _fbthrift_value = _from_python_or_raise(_fbthrift_value, "struct_field", _module_types.SimpleStruct)
        deref(self._struct_cpp_obj).struct_field_ref().assign(deref((<_module_types.SimpleStruct?> _fbthrift_value)._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE))


@__cython.auto_pickle(False)
cdef class __CustomTypedefFields_FieldsSetter(__StructFieldsSetter):

    @staticmethod
    cdef __CustomTypedefFields_FieldsSetter _fbthrift_create(_module_cbindings.cCustomTypedefFields* struct_cpp_obj):
        cdef __CustomTypedefFields_FieldsSetter __fbthrift_inst = __CustomTypedefFields_FieldsSetter.__new__(__CustomTypedefFields_FieldsSetter)
        __fbthrift_inst._struct_cpp_obj = struct_cpp_obj
        __fbthrift_inst._setters[__cstring_view(<const char*>"bool_field")] = __CustomTypedefFields_FieldsSetter._set_field_0
        __fbthrift_inst._setters[__cstring_view(<const char*>"integer_field")] = __CustomTypedefFields_FieldsSetter._set_field_1
        __fbthrift_inst._setters[__cstring_view(<const char*>"double_field")] = __CustomTypedefFields_FieldsSetter._set_field_2
        __fbthrift_inst._setters[__cstring_view(<const char*>"string_field")] = __CustomTypedefFields_FieldsSetter._set_field_3
        __fbthrift_inst._setters[__cstring_view(<const char*>"binary_field")] = __CustomTypedefFields_FieldsSetter._set_field_4
        __fbthrift_inst._setters[__cstring_view(<const char*>"list_field")] = __CustomTypedefFields_FieldsSetter._set_field_5
        __fbthrift_inst._setters[__cstring_view(<const char*>"set_field")] = __CustomTypedefFields_FieldsSetter._set_field_6
        __fbthrift_inst._setters[__cstring_view(<const char*>"map_field")] = __CustomTypedefFields_FieldsSetter._set_field_7
        __fbthrift_inst._setters[__cstring_view(<const char*>"struct_field")] = __CustomTypedefFields_FieldsSetter._set_field_8
        return __fbthrift_inst

    cdef void set_field(__CustomTypedefFields_FieldsSetter self, const char* name, object value) except *:
        cdef __cstring_view cname = __cstring_view(name)
        cdef cumap[__cstring_view, __CustomTypedefFields_FieldsSetterFunc].iterator found = self._setters.find(cname)
        if found == self._setters.end():
            raise TypeError(f"invalid field name {name.decode('utf-8')}")
        deref(found).second(self, value)

    cdef void _set_field_0(self, _fbthrift_value) except *:
        # for field bool_field
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cCustomTypedefFields](deref(self._struct_cpp_obj), 0)
            return
        if not isinstance(_fbthrift_value, bool):
            raise TypeError(f'bool_field is not a { bool !r}.')
        deref(self._struct_cpp_obj).bool_field_ref().assign(_fbthrift_value)

    cdef void _set_field_1(self, _fbthrift_value) except *:
        # for field integer_field
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cCustomTypedefFields](deref(self._struct_cpp_obj), 1)
            return
        if not isinstance(_fbthrift_value, int):
            raise TypeError(f'integer_field is not a { int !r}.')
        _fbthrift_value = <cint64_t> _fbthrift_value
        deref(self._struct_cpp_obj).integer_field_ref().assign(_fbthrift_value)

    cdef void _set_field_2(self, _fbthrift_value) except *:
        # for field double_field
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cCustomTypedefFields](deref(self._struct_cpp_obj), 2)
            return
        if not isinstance(_fbthrift_value, (float, int)):
            raise TypeError(f'double_field is not a { float !r}.')
        deref(self._struct_cpp_obj).double_field_ref().assign(_fbthrift_value)

    cdef void _set_field_3(self, _fbthrift_value) except *:
        # for field string_field
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cCustomTypedefFields](deref(self._struct_cpp_obj), 3)
            return
        if not isinstance(_fbthrift_value, str):
            raise TypeError(f'string_field is not a { str !r}.')
        deref(self._struct_cpp_obj).string_field_ref().assign(cmove(bytes_to_string(_fbthrift_value.encode('utf-8'))))

    cdef void _set_field_4(self, _fbthrift_value) except *:
        # for field binary_field
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cCustomTypedefFields](deref(self._struct_cpp_obj), 4)
            return
        if not isinstance(_fbthrift_value, bytes):
            raise TypeError(f'binary_field is not a { bytes !r}.')
        deref(self._struct_cpp_obj).binary_field_ref().assign(_module_cbindings._MyType(cmove(<string>_fbthrift_value)))

    cdef void _set_field_5(self, _fbthrift_value) except *:
        # for field list_field
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cCustomTypedefFields](deref(self._struct_cpp_obj), 5)
            return
        deref(self._struct_cpp_obj).list_field_ref().assign(_module_types._MyType__List__i32__make_instance(_fbthrift_value))

    cdef void _set_field_6(self, _fbthrift_value) except *:
        # for field set_field
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cCustomTypedefFields](deref(self._struct_cpp_obj), 6)
            return
        deref(self._struct_cpp_obj).set_field_ref().assign(_module_types._MyType__Set__i32__make_instance(_fbthrift_value))

    cdef void _set_field_7(self, _fbthrift_value) except *:
        # for field map_field
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cCustomTypedefFields](deref(self._struct_cpp_obj), 7)
            return
        deref(self._struct_cpp_obj).map_field_ref().assign(_module_types._MyType__Map__i32_i32__make_instance(_fbthrift_value))

    cdef void _set_field_8(self, _fbthrift_value) except *:
        # for field struct_field
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cCustomTypedefFields](deref(self._struct_cpp_obj), 8)
            return
        if not isinstance(_fbthrift_value, _module_types.SimpleStruct):
            _fbthrift_value = _from_python_or_raise(_fbthrift_value, "struct_field", _module_types.SimpleStruct)
        deref(self._struct_cpp_obj).struct_field_ref().assign(deref((<_module_types.SimpleStruct?> _fbthrift_value)._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE))


@__cython.auto_pickle(False)
cdef class __AdaptedTypedefFields_FieldsSetter(__StructFieldsSetter):

    @staticmethod
    cdef __AdaptedTypedefFields_FieldsSetter _fbthrift_create(_module_cbindings.cAdaptedTypedefFields* struct_cpp_obj):
        cdef __AdaptedTypedefFields_FieldsSetter __fbthrift_inst = __AdaptedTypedefFields_FieldsSetter.__new__(__AdaptedTypedefFields_FieldsSetter)
        __fbthrift_inst._struct_cpp_obj = struct_cpp_obj
        __fbthrift_inst._setters[__cstring_view(<const char*>"bool_field")] = __AdaptedTypedefFields_FieldsSetter._set_field_0
        __fbthrift_inst._setters[__cstring_view(<const char*>"integer_field")] = __AdaptedTypedefFields_FieldsSetter._set_field_1
        __fbthrift_inst._setters[__cstring_view(<const char*>"double_field")] = __AdaptedTypedefFields_FieldsSetter._set_field_2
        __fbthrift_inst._setters[__cstring_view(<const char*>"string_field")] = __AdaptedTypedefFields_FieldsSetter._set_field_3
        __fbthrift_inst._setters[__cstring_view(<const char*>"binary_field")] = __AdaptedTypedefFields_FieldsSetter._set_field_4
        __fbthrift_inst._setters[__cstring_view(<const char*>"list_field")] = __AdaptedTypedefFields_FieldsSetter._set_field_5
        __fbthrift_inst._setters[__cstring_view(<const char*>"set_field")] = __AdaptedTypedefFields_FieldsSetter._set_field_6
        __fbthrift_inst._setters[__cstring_view(<const char*>"map_field")] = __AdaptedTypedefFields_FieldsSetter._set_field_7
        __fbthrift_inst._setters[__cstring_view(<const char*>"struct_field")] = __AdaptedTypedefFields_FieldsSetter._set_field_8
        return __fbthrift_inst

    cdef void set_field(__AdaptedTypedefFields_FieldsSetter self, const char* name, object value) except *:
        cdef __cstring_view cname = __cstring_view(name)
        cdef cumap[__cstring_view, __AdaptedTypedefFields_FieldsSetterFunc].iterator found = self._setters.find(cname)
        if found == self._setters.end():
            raise TypeError(f"invalid field name {name.decode('utf-8')}")
        deref(found).second(self, value)

    cdef void _set_field_0(self, _fbthrift_value) except *:
        # for field bool_field
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cAdaptedTypedefFields](deref(self._struct_cpp_obj), 0)
            return
        if not isinstance(_fbthrift_value, bool):
            raise TypeError(f'bool_field is not a { bool !r}.')
        deref(self._struct_cpp_obj).bool_field_ref().assign(_fbthrift_value)

    cdef void _set_field_1(self, _fbthrift_value) except *:
        # for field integer_field
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cAdaptedTypedefFields](deref(self._struct_cpp_obj), 1)
            return
        if not isinstance(_fbthrift_value, int):
            raise TypeError(f'integer_field is not a { int !r}.')
        _fbthrift_value = <cint64_t> _fbthrift_value
        deref(self._struct_cpp_obj).integer_field_ref().assign(_fbthrift_value)

    cdef void _set_field_2(self, _fbthrift_value) except *:
        # for field double_field
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cAdaptedTypedefFields](deref(self._struct_cpp_obj), 2)
            return
        if not isinstance(_fbthrift_value, (float, int)):
            raise TypeError(f'double_field is not a { float !r}.')
        deref(self._struct_cpp_obj).double_field_ref().assign(_fbthrift_value)

    cdef void _set_field_3(self, _fbthrift_value) except *:
        # for field string_field
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cAdaptedTypedefFields](deref(self._struct_cpp_obj), 3)
            return
        if not isinstance(_fbthrift_value, str):
            raise TypeError(f'string_field is not a { str !r}.')
        deref(self._struct_cpp_obj).string_field_ref().assign(cmove(bytes_to_string(_fbthrift_value.encode('utf-8'))))

    cdef void _set_field_4(self, _fbthrift_value) except *:
        # for field binary_field
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cAdaptedTypedefFields](deref(self._struct_cpp_obj), 4)
            return
        if not isinstance(_fbthrift_value, bytes):
            raise TypeError(f'binary_field is not a { bytes !r}.')
        deref(self._struct_cpp_obj).binary_field_ref().assign(_module_cbindings._py3_simple_AdaptedBinary(cmove(<string>_fbthrift_value)))

    cdef void _set_field_5(self, _fbthrift_value) except *:
        # for field list_field
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cAdaptedTypedefFields](deref(self._struct_cpp_obj), 5)
            return
        deref(self._struct_cpp_obj).list_field_ref().assign(_module_types._py3_simple_AdaptedList__List__i32__make_instance(_fbthrift_value))

    cdef void _set_field_6(self, _fbthrift_value) except *:
        # for field set_field
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cAdaptedTypedefFields](deref(self._struct_cpp_obj), 6)
            return
        deref(self._struct_cpp_obj).set_field_ref().assign(_module_types._py3_simple_AdaptedSet__Set__i32__make_instance(_fbthrift_value))

    cdef void _set_field_7(self, _fbthrift_value) except *:
        # for field map_field
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cAdaptedTypedefFields](deref(self._struct_cpp_obj), 7)
            return
        deref(self._struct_cpp_obj).map_field_ref().assign(_module_types._py3_simple_AdaptedMap__Map__i32_i32__make_instance(_fbthrift_value))

    cdef void _set_field_8(self, _fbthrift_value) except *:
        # for field struct_field
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cAdaptedTypedefFields](deref(self._struct_cpp_obj), 8)
            return
        if not isinstance(_fbthrift_value, _module_types.SimpleStruct):
            _fbthrift_value = _from_python_or_raise(_fbthrift_value, "struct_field", _module_types.SimpleStruct)
        deref(self._struct_cpp_obj).struct_field_ref().assign(deref((<_module_types.SimpleStruct?> _fbthrift_value)._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE))

