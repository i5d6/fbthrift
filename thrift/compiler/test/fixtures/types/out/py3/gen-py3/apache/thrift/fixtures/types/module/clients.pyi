#
# Autogenerated by Thrift for thrift/compiler/test/fixtures/types/src/module.thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

import folly.iobuf as _fbthrift_iobuf
import thrift.py3.types
import thrift.py3.client
import thrift.py3.common
import typing as _typing
from types import TracebackType

import apache.thrift.fixtures.types.module.types as _apache_thrift_fixtures_types_module_types
import apache.thrift.fixtures.types.included.types as _apache_thrift_fixtures_types_included_types


_SomeServiceT = _typing.TypeVar('_SomeServiceT', bound='SomeService')


class SomeService(thrift.py3.client.Client):

    async def bounce_map(
        self,
        m: _typing.Mapping[int, str],
        *,
        rpc_options: _typing.Optional[thrift.py3.common.RpcOptions]=None
    ) -> _typing.Mapping[int, str]: ...

    async def binary_keyed_map(
        self,
        r: _typing.Sequence[int],
        *,
        rpc_options: _typing.Optional[thrift.py3.common.RpcOptions]=None
    ) -> _typing.Mapping[bytes, int]: ...

