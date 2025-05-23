#
# Autogenerated by Thrift
#
# DO NOT EDIT
#  @generated
#

from __future__ import annotations

import typing as _typing

import enum

import folly.iobuf as _fbthrift_iobuf
import test.fixtures.python_capi.serialized_dep.thrift_abstract_types as _fbthrift_python_abstract_types
import thrift.python.types as _fbthrift_python_types
import thrift.python.mutable_types as _fbthrift_python_mutable_types
import thrift.python.mutable_exceptions as _fbthrift_python_mutable_exceptions
import thrift.python.mutable_containers as _fbthrift_python_mutable_containers


class SerializedStruct(_fbthrift_python_mutable_types.MutableStruct, _fbthrift_python_abstract_types.SerializedStruct):
    @property
    def s(self) -> str: ...
    @s.setter
    def s(self, value: str) -> None: ...

    @property
    def i(self) -> int: ...
    @i.setter
    def i(self, value: int) -> None: ...

    @property
    def os(self) -> _typing.Optional[str]: ...
    @os.setter
    def os(self, value: _typing.Optional[str]) -> None: ...

    @property
    def rs(self) -> str: ...
    @rs.setter
    def rs(self, value: str) -> None: ...

    def __init__(
        self, *,
        s: _typing.Optional[str]=...,
        i: _typing.Optional[int]=...,
        os: _typing.Optional[str]=...,
        rs: _typing.Optional[str]=...
    ) -> None: ...

    def __call__(
        self, *,
        s: _typing.Optional[str]=...,
        i: _typing.Optional[int]=...,
        os: _typing.Optional[str]=...,
        rs: _typing.Optional[str]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[str, int, str, str]]]: ...
    def _to_python(self) -> "test.fixtures.python_capi.serialized_dep.thrift_types.SerializedStruct": ...  # type: ignore
    def _to_mutable_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "test.fixtures.python_capi.serialized_dep.types.SerializedStruct": ...  # type: ignore
    def _to_py_deprecated(self) -> "serialized_dep.ttypes.SerializedStruct": ...  # type: ignore
_fbthrift_SerializedStruct = SerializedStruct

class SerializedUnion(_fbthrift_python_mutable_types.MutableUnion, _fbthrift_python_abstract_types.SerializedUnion):
    @property
    def s(self) -> str: ...
    @s.setter
    def s(self, value: str) -> None: ...

    @property
    def i(self) -> int: ...
    @i.setter
    def i(self, value: int) -> None: ...

    def __init__(
        self, *,
        s: _typing.Optional[str]=...,
        i: _typing.Optional[int]=...
    ) -> None: ...



    class FbThriftUnionFieldEnum(enum.Enum):
        EMPTY: SerializedUnion.FbThriftUnionFieldEnum = ...
        s: SerializedUnion.FbThriftUnionFieldEnum = ...
        i: SerializedUnion.FbThriftUnionFieldEnum = ...

    fbthrift_current_value: _typing.Final[_typing.Union[None, str, int]]
    # pyre-ignore[15]: `fbthrift_current_field` overrides attribute defined in `_fbthrift_python_abstract_types.SerializedUnion` inconsistently. Type `SerializedUnion.FbThriftUnionFieldEnum` is not a subtype of the overridden attribute `_fbthrift_python_abstract_types.SerializedUnion.FbThriftUnionFieldEnum`
    fbthrift_current_field: _typing.Final[FbThriftUnionFieldEnum]
    def get_type(self) -> FbThriftUnionFieldEnum: ...
    def _to_python(self) -> "test.fixtures.python_capi.serialized_dep.thrift_types.SerializedUnion": ...  # type: ignore
    def _to_mutable_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "test.fixtures.python_capi.serialized_dep.types.SerializedUnion": ...  # type: ignore
    def _to_py_deprecated(self) -> "serialized_dep.ttypes.SerializedUnion": ...  # type: ignore
_fbthrift_SerializedUnion = SerializedUnion

class SerializedError(_fbthrift_python_mutable_exceptions.MutableGeneratedError, _fbthrift_python_abstract_types.SerializedError):
    @property
    def msg(self) -> str: ...
    @msg.setter
    def msg(self, value: str) -> None: ...

    @property
    def os(self) -> _typing.Optional[str]: ...
    @os.setter
    def os(self, value: _typing.Optional[str]) -> None: ...

    @property
    def rs(self) -> str: ...
    @rs.setter
    def rs(self, value: str) -> None: ...

    def __init__(
        self, *,
        msg: _typing.Optional[str]=...,
        os: _typing.Optional[str]=...,
        rs: _typing.Optional[str]=...
    ) -> None: ...

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[str, str, str]]]: ...
    def _to_python(self) -> "test.fixtures.python_capi.serialized_dep.thrift_types.SerializedError": ...  # type: ignore
    def _to_mutable_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "test.fixtures.python_capi.serialized_dep.types.SerializedError": ...  # type: ignore
    def _to_py_deprecated(self) -> "serialized_dep.ttypes.SerializedError": ...  # type: ignore
_fbthrift_SerializedError = SerializedError

class MarshalStruct(_fbthrift_python_mutable_types.MutableStruct, _fbthrift_python_abstract_types.MarshalStruct):
    @property
    def s(self) -> str: ...
    @s.setter
    def s(self, value: str) -> None: ...

    @property
    def i(self) -> int: ...
    @i.setter
    def i(self, value: int) -> None: ...

    @property
    def os(self) -> _typing.Optional[str]: ...
    @os.setter
    def os(self, value: _typing.Optional[str]) -> None: ...

    @property
    def rs(self) -> str: ...
    @rs.setter
    def rs(self, value: str) -> None: ...

    def __init__(
        self, *,
        s: _typing.Optional[str]=...,
        i: _typing.Optional[int]=...,
        os: _typing.Optional[str]=...,
        rs: _typing.Optional[str]=...
    ) -> None: ...

    def __call__(
        self, *,
        s: _typing.Optional[str]=...,
        i: _typing.Optional[int]=...,
        os: _typing.Optional[str]=...,
        rs: _typing.Optional[str]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[str, int, str, str]]]: ...
    def _to_python(self) -> "test.fixtures.python_capi.serialized_dep.thrift_types.MarshalStruct": ...  # type: ignore
    def _to_mutable_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "test.fixtures.python_capi.serialized_dep.types.MarshalStruct": ...  # type: ignore
    def _to_py_deprecated(self) -> "serialized_dep.ttypes.MarshalStruct": ...  # type: ignore
_fbthrift_MarshalStruct = MarshalStruct

class MarshalUnion(_fbthrift_python_mutable_types.MutableUnion, _fbthrift_python_abstract_types.MarshalUnion):
    @property
    def s(self) -> str: ...
    @s.setter
    def s(self, value: str) -> None: ...

    @property
    def i(self) -> int: ...
    @i.setter
    def i(self, value: int) -> None: ...

    def __init__(
        self, *,
        s: _typing.Optional[str]=...,
        i: _typing.Optional[int]=...
    ) -> None: ...



    class FbThriftUnionFieldEnum(enum.Enum):
        EMPTY: MarshalUnion.FbThriftUnionFieldEnum = ...
        s: MarshalUnion.FbThriftUnionFieldEnum = ...
        i: MarshalUnion.FbThriftUnionFieldEnum = ...

    fbthrift_current_value: _typing.Final[_typing.Union[None, str, int]]
    # pyre-ignore[15]: `fbthrift_current_field` overrides attribute defined in `_fbthrift_python_abstract_types.MarshalUnion` inconsistently. Type `MarshalUnion.FbThriftUnionFieldEnum` is not a subtype of the overridden attribute `_fbthrift_python_abstract_types.MarshalUnion.FbThriftUnionFieldEnum`
    fbthrift_current_field: _typing.Final[FbThriftUnionFieldEnum]
    def get_type(self) -> FbThriftUnionFieldEnum: ...
    def _to_python(self) -> "test.fixtures.python_capi.serialized_dep.thrift_types.MarshalUnion": ...  # type: ignore
    def _to_mutable_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "test.fixtures.python_capi.serialized_dep.types.MarshalUnion": ...  # type: ignore
    def _to_py_deprecated(self) -> "serialized_dep.ttypes.MarshalUnion": ...  # type: ignore
_fbthrift_MarshalUnion = MarshalUnion

class MarshalError(_fbthrift_python_mutable_exceptions.MutableGeneratedError, _fbthrift_python_abstract_types.MarshalError):
    @property
    def msg(self) -> str: ...
    @msg.setter
    def msg(self, value: str) -> None: ...

    @property
    def os(self) -> _typing.Optional[str]: ...
    @os.setter
    def os(self, value: _typing.Optional[str]) -> None: ...

    @property
    def rs(self) -> str: ...
    @rs.setter
    def rs(self, value: str) -> None: ...

    def __init__(
        self, *,
        msg: _typing.Optional[str]=...,
        os: _typing.Optional[str]=...,
        rs: _typing.Optional[str]=...
    ) -> None: ...

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[str, str, str]]]: ...
    def _to_python(self) -> "test.fixtures.python_capi.serialized_dep.thrift_types.MarshalError": ...  # type: ignore
    def _to_mutable_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "test.fixtures.python_capi.serialized_dep.types.MarshalError": ...  # type: ignore
    def _to_py_deprecated(self) -> "serialized_dep.ttypes.MarshalError": ...  # type: ignore
_fbthrift_MarshalError = MarshalError
