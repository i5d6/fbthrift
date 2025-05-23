#
# Autogenerated by Thrift for thrift/compiler/test/fixtures/exceptions/src/module.thrift
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
cdef class __Fiery_FieldsSetter(__StructFieldsSetter):

    @staticmethod
    cdef __Fiery_FieldsSetter _fbthrift_create(_module_cbindings.cFiery* struct_cpp_obj):
        cdef __Fiery_FieldsSetter __fbthrift_inst = __Fiery_FieldsSetter.__new__(__Fiery_FieldsSetter)
        __fbthrift_inst._struct_cpp_obj = struct_cpp_obj
        __fbthrift_inst._setters[__cstring_view(<const char*>"message")] = __Fiery_FieldsSetter._set_field_0
        return __fbthrift_inst

    cdef void set_field(__Fiery_FieldsSetter self, const char* name, object value) except *:
        cdef __cstring_view cname = __cstring_view(name)
        cdef cumap[__cstring_view, __Fiery_FieldsSetterFunc].iterator found = self._setters.find(cname)
        if found == self._setters.end():
            raise TypeError(f"invalid field name {name.decode('utf-8')}")
        deref(found).second(self, value)

    cdef void _set_field_0(self, _fbthrift_value) except *:
        # for field message
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cFiery](deref(self._struct_cpp_obj), 0)
            return
        if not isinstance(_fbthrift_value, str):
            raise TypeError(f'message is not a { str !r}.')
        deref(self._struct_cpp_obj).message_ref().assign(cmove(bytes_to_string(_fbthrift_value.encode('utf-8'))))


@__cython.auto_pickle(False)
cdef class __Serious_FieldsSetter(__StructFieldsSetter):

    @staticmethod
    cdef __Serious_FieldsSetter _fbthrift_create(_module_cbindings.cSerious* struct_cpp_obj):
        cdef __Serious_FieldsSetter __fbthrift_inst = __Serious_FieldsSetter.__new__(__Serious_FieldsSetter)
        __fbthrift_inst._struct_cpp_obj = struct_cpp_obj
        __fbthrift_inst._setters[__cstring_view(<const char*>"not_sonnet")] = __Serious_FieldsSetter._set_field_0
        return __fbthrift_inst

    cdef void set_field(__Serious_FieldsSetter self, const char* name, object value) except *:
        cdef __cstring_view cname = __cstring_view(name)
        cdef cumap[__cstring_view, __Serious_FieldsSetterFunc].iterator found = self._setters.find(cname)
        if found == self._setters.end():
            raise TypeError(f"invalid field name {name.decode('utf-8')}")
        deref(found).second(self, value)

    cdef void _set_field_0(self, _fbthrift_value) except *:
        # for field not_sonnet
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cSerious](deref(self._struct_cpp_obj), 0)
            return
        if not isinstance(_fbthrift_value, str):
            raise TypeError(f'not_sonnet is not a { str !r}.')
        deref(self._struct_cpp_obj).not_sonnet_ref().assign(cmove(bytes_to_string(_fbthrift_value.encode('utf-8'))))


@__cython.auto_pickle(False)
cdef class __ComplexFieldNames_FieldsSetter(__StructFieldsSetter):

    @staticmethod
    cdef __ComplexFieldNames_FieldsSetter _fbthrift_create(_module_cbindings.cComplexFieldNames* struct_cpp_obj):
        cdef __ComplexFieldNames_FieldsSetter __fbthrift_inst = __ComplexFieldNames_FieldsSetter.__new__(__ComplexFieldNames_FieldsSetter)
        __fbthrift_inst._struct_cpp_obj = struct_cpp_obj
        __fbthrift_inst._setters[__cstring_view(<const char*>"error_message")] = __ComplexFieldNames_FieldsSetter._set_field_0
        __fbthrift_inst._setters[__cstring_view(<const char*>"internal_error_message")] = __ComplexFieldNames_FieldsSetter._set_field_1
        return __fbthrift_inst

    cdef void set_field(__ComplexFieldNames_FieldsSetter self, const char* name, object value) except *:
        cdef __cstring_view cname = __cstring_view(name)
        cdef cumap[__cstring_view, __ComplexFieldNames_FieldsSetterFunc].iterator found = self._setters.find(cname)
        if found == self._setters.end():
            raise TypeError(f"invalid field name {name.decode('utf-8')}")
        deref(found).second(self, value)

    cdef void _set_field_0(self, _fbthrift_value) except *:
        # for field error_message
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cComplexFieldNames](deref(self._struct_cpp_obj), 0)
            return
        if not isinstance(_fbthrift_value, str):
            raise TypeError(f'error_message is not a { str !r}.')
        deref(self._struct_cpp_obj).error_message_ref().assign(cmove(bytes_to_string(_fbthrift_value.encode('utf-8'))))

    cdef void _set_field_1(self, _fbthrift_value) except *:
        # for field internal_error_message
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cComplexFieldNames](deref(self._struct_cpp_obj), 1)
            return
        if not isinstance(_fbthrift_value, str):
            raise TypeError(f'internal_error_message is not a { str !r}.')
        deref(self._struct_cpp_obj).internal_error_message_ref().assign(cmove(bytes_to_string(_fbthrift_value.encode('utf-8'))))


@__cython.auto_pickle(False)
cdef class __CustomFieldNames_FieldsSetter(__StructFieldsSetter):

    @staticmethod
    cdef __CustomFieldNames_FieldsSetter _fbthrift_create(_module_cbindings.cCustomFieldNames* struct_cpp_obj):
        cdef __CustomFieldNames_FieldsSetter __fbthrift_inst = __CustomFieldNames_FieldsSetter.__new__(__CustomFieldNames_FieldsSetter)
        __fbthrift_inst._struct_cpp_obj = struct_cpp_obj
        __fbthrift_inst._setters[__cstring_view(<const char*>"error_message")] = __CustomFieldNames_FieldsSetter._set_field_0
        __fbthrift_inst._setters[__cstring_view(<const char*>"internal_error_message")] = __CustomFieldNames_FieldsSetter._set_field_1
        return __fbthrift_inst

    cdef void set_field(__CustomFieldNames_FieldsSetter self, const char* name, object value) except *:
        cdef __cstring_view cname = __cstring_view(name)
        cdef cumap[__cstring_view, __CustomFieldNames_FieldsSetterFunc].iterator found = self._setters.find(cname)
        if found == self._setters.end():
            raise TypeError(f"invalid field name {name.decode('utf-8')}")
        deref(found).second(self, value)

    cdef void _set_field_0(self, _fbthrift_value) except *:
        # for field error_message
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cCustomFieldNames](deref(self._struct_cpp_obj), 0)
            return
        if not isinstance(_fbthrift_value, str):
            raise TypeError(f'error_message is not a { str !r}.')
        deref(self._struct_cpp_obj).error_message_ref().assign(cmove(bytes_to_string(_fbthrift_value.encode('utf-8'))))

    cdef void _set_field_1(self, _fbthrift_value) except *:
        # for field internal_error_message
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cCustomFieldNames](deref(self._struct_cpp_obj), 1)
            return
        if not isinstance(_fbthrift_value, str):
            raise TypeError(f'internal_error_message is not a { str !r}.')
        deref(self._struct_cpp_obj).internal_error_message_ref().assign(cmove(bytes_to_string(_fbthrift_value.encode('utf-8'))))


@__cython.auto_pickle(False)
cdef class __ExceptionWithPrimitiveField_FieldsSetter(__StructFieldsSetter):

    @staticmethod
    cdef __ExceptionWithPrimitiveField_FieldsSetter _fbthrift_create(_module_cbindings.cExceptionWithPrimitiveField* struct_cpp_obj):
        cdef __ExceptionWithPrimitiveField_FieldsSetter __fbthrift_inst = __ExceptionWithPrimitiveField_FieldsSetter.__new__(__ExceptionWithPrimitiveField_FieldsSetter)
        __fbthrift_inst._struct_cpp_obj = struct_cpp_obj
        __fbthrift_inst._setters[__cstring_view(<const char*>"message")] = __ExceptionWithPrimitiveField_FieldsSetter._set_field_0
        __fbthrift_inst._setters[__cstring_view(<const char*>"error_code")] = __ExceptionWithPrimitiveField_FieldsSetter._set_field_1
        return __fbthrift_inst

    cdef void set_field(__ExceptionWithPrimitiveField_FieldsSetter self, const char* name, object value) except *:
        cdef __cstring_view cname = __cstring_view(name)
        cdef cumap[__cstring_view, __ExceptionWithPrimitiveField_FieldsSetterFunc].iterator found = self._setters.find(cname)
        if found == self._setters.end():
            raise TypeError(f"invalid field name {name.decode('utf-8')}")
        deref(found).second(self, value)

    cdef void _set_field_0(self, _fbthrift_value) except *:
        # for field message
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cExceptionWithPrimitiveField](deref(self._struct_cpp_obj), 0)
            return
        if not isinstance(_fbthrift_value, str):
            raise TypeError(f'message is not a { str !r}.')
        deref(self._struct_cpp_obj).message_ref().assign(cmove(bytes_to_string(_fbthrift_value.encode('utf-8'))))

    cdef void _set_field_1(self, _fbthrift_value) except *:
        # for field error_code
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cExceptionWithPrimitiveField](deref(self._struct_cpp_obj), 1)
            return
        if not isinstance(_fbthrift_value, int):
            raise TypeError(f'error_code is not a { int !r}.')
        _fbthrift_value = <cint32_t> _fbthrift_value
        deref(self._struct_cpp_obj).error_code_ref().assign(_fbthrift_value)


@__cython.auto_pickle(False)
cdef class __ExceptionWithStructuredAnnotation_FieldsSetter(__StructFieldsSetter):

    @staticmethod
    cdef __ExceptionWithStructuredAnnotation_FieldsSetter _fbthrift_create(_module_cbindings.cExceptionWithStructuredAnnotation* struct_cpp_obj):
        cdef __ExceptionWithStructuredAnnotation_FieldsSetter __fbthrift_inst = __ExceptionWithStructuredAnnotation_FieldsSetter.__new__(__ExceptionWithStructuredAnnotation_FieldsSetter)
        __fbthrift_inst._struct_cpp_obj = struct_cpp_obj
        __fbthrift_inst._setters[__cstring_view(<const char*>"message_field")] = __ExceptionWithStructuredAnnotation_FieldsSetter._set_field_0
        __fbthrift_inst._setters[__cstring_view(<const char*>"error_code")] = __ExceptionWithStructuredAnnotation_FieldsSetter._set_field_1
        return __fbthrift_inst

    cdef void set_field(__ExceptionWithStructuredAnnotation_FieldsSetter self, const char* name, object value) except *:
        cdef __cstring_view cname = __cstring_view(name)
        cdef cumap[__cstring_view, __ExceptionWithStructuredAnnotation_FieldsSetterFunc].iterator found = self._setters.find(cname)
        if found == self._setters.end():
            raise TypeError(f"invalid field name {name.decode('utf-8')}")
        deref(found).second(self, value)

    cdef void _set_field_0(self, _fbthrift_value) except *:
        # for field message_field
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cExceptionWithStructuredAnnotation](deref(self._struct_cpp_obj), 0)
            return
        if not isinstance(_fbthrift_value, str):
            raise TypeError(f'message_field is not a { str !r}.')
        deref(self._struct_cpp_obj).message_field_ref().assign(cmove(bytes_to_string(_fbthrift_value.encode('utf-8'))))

    cdef void _set_field_1(self, _fbthrift_value) except *:
        # for field error_code
        if _fbthrift_value is None:
            __reset_field[_module_cbindings.cExceptionWithStructuredAnnotation](deref(self._struct_cpp_obj), 1)
            return
        if not isinstance(_fbthrift_value, int):
            raise TypeError(f'error_code is not a { int !r}.')
        _fbthrift_value = <cint32_t> _fbthrift_value
        deref(self._struct_cpp_obj).error_code_ref().assign(_fbthrift_value)


@__cython.auto_pickle(False)
cdef class __Banal_FieldsSetter(__StructFieldsSetter):

    @staticmethod
    cdef __Banal_FieldsSetter _fbthrift_create(_module_cbindings.cBanal* struct_cpp_obj):
        cdef __Banal_FieldsSetter __fbthrift_inst = __Banal_FieldsSetter.__new__(__Banal_FieldsSetter)
        __fbthrift_inst._struct_cpp_obj = struct_cpp_obj
        return __fbthrift_inst

    cdef void set_field(__Banal_FieldsSetter self, const char* name, object value) except *:
        cdef __cstring_view cname = __cstring_view(name)
        cdef cumap[__cstring_view, __Banal_FieldsSetterFunc].iterator found = self._setters.find(cname)
        if found == self._setters.end():
            raise TypeError(f"invalid field name {name.decode('utf-8')}")
        deref(found).second(self, value)

