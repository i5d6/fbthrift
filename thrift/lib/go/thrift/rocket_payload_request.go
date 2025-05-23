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

package thrift

import (
	"errors"
	"fmt"
	"maps"

	"github.com/facebook/fbthrift/thrift/lib/go/thrift/types"
	"github.com/facebook/fbthrift/thrift/lib/thrift/rpcmetadata"
	"github.com/rsocket/rsocket-go/payload"
)

type requestPayload struct {
	metadata *rpcmetadata.RequestRpcMetadata
	data     []byte
	typeID   types.MessageType
	protoID  types.ProtocolID
}

func encodeRequestPayload(
	name string,
	protoID types.ProtocolID,
	rpcKind rpcmetadata.RpcKind,
	headers map[string]string,
	compression rpcmetadata.CompressionAlgorithm,
	dataBytes []byte,
) (payload.Payload, error) {
	rpcProtocolID, err := protocolIDToRPCProtocolID(protoID)
	if err != nil {
		return nil, err
	}
	headersCopy := make(map[string]string, len(headers))
	maps.Copy(headersCopy, headers)

	metadata := rpcmetadata.NewRequestRpcMetadata().
		SetName(&name).
		SetProtocol(&rpcProtocolID).
		SetKind(&rpcKind).
		SetCompression(&compression).
		SetOtherMetadata(headersCopy)

	metadataBytes, err := EncodeCompact(metadata)
	if err != nil {
		return nil, err
	}
	dataBytes, err = maybeCompress(dataBytes, compression)
	if err != nil {
		return nil, err
	}
	pay := payload.New(dataBytes, metadataBytes)
	return pay, nil
}

func decodeRequestPayload(msg payload.Payload) (*requestPayload, error) {
	msg = payload.Clone(msg)

	metadataBytes, ok := msg.Metadata()
	if !ok {
		return nil, fmt.Errorf("request payload is missing metadata")
	}

	metadata := &rpcmetadata.RequestRpcMetadata{}
	err := DecodeCompact(metadataBytes, metadata)
	if err != nil {
		return nil, err
	}

	typeID, err := rpcKindToMessageType(metadata.GetKind())
	if err != nil {
		return nil, err
	}

	protoID, err := rpcProtocolIDToProtocolID(metadata.GetProtocol())
	if err != nil {
		return nil, err
	}

	dataBytes, err := maybeDecompress(msg.Data(), metadata.GetCompression())
	if err != nil {
		return nil, fmt.Errorf("request payload decompression failed: %w", err)
	}

	res := &requestPayload{
		metadata: metadata,
		typeID:   typeID,
		protoID:  protoID,
		data:     dataBytes,
	}
	return res, nil
}

func (r *requestPayload) Data() []byte {
	return r.data
}

func (r *requestPayload) HasMetadata() bool {
	return r.metadata != nil
}

func (r *requestPayload) Name() string {
	if r.metadata == nil {
		return ""
	}
	return r.metadata.GetName()
}

func (r *requestPayload) TypeID() types.MessageType {
	return r.typeID
}

func (r *requestPayload) ProtoID() types.ProtocolID {
	return r.protoID
}

func (r *requestPayload) GetCompressionForResponse() rpcmetadata.CompressionAlgorithm {
	if r.metadata != nil {
		compressionConfig := r.metadata.GetCompressionConfig()
		return compressionAlgorithmFromCompressionConfig(compressionConfig)
	}
	return rpcmetadata.CompressionAlgorithm_NONE
}

func (r *requestPayload) Headers() map[string]string {
	if r.metadata == nil {
		return nil
	}

	headersMap := make(map[string]string)
	maps.Copy(headersMap, r.metadata.GetOtherMetadata())
	if r.metadata.IsSetClientId() {
		headersMap["client_id"] = r.metadata.GetClientId()
	}
	if r.metadata.IsSetLoadMetric() {
		headersMap["load"] = r.metadata.GetLoadMetric()
	}
	if r.metadata.IsSetClientTimeoutMs() {
		headersMap["client_timeout"] = fmt.Sprintf("%d", r.metadata.GetClientTimeoutMs())
	}
	return headersMap
}

func protocolIDToRPCProtocolID(protocolID types.ProtocolID) (rpcmetadata.ProtocolId, error) {
	switch protocolID {
	case types.ProtocolIDBinary:
		return rpcmetadata.ProtocolId_BINARY, nil
	case types.ProtocolIDCompact:
		return rpcmetadata.ProtocolId_COMPACT, nil
	}
	return 0, fmt.Errorf("unsupported ProtocolID %v", protocolID)
}

func rpcProtocolIDToProtocolID(protocolID rpcmetadata.ProtocolId) (types.ProtocolID, error) {
	switch protocolID {
	case rpcmetadata.ProtocolId_BINARY:
		return types.ProtocolIDBinary, nil
	case rpcmetadata.ProtocolId_COMPACT:
		return types.ProtocolIDCompact, nil
	}
	return 0, fmt.Errorf("unsupported ProtocolId %v", protocolID)
}

func rpcKindToMessageType(kind rpcmetadata.RpcKind) (types.MessageType, error) {
	switch kind {
	case rpcmetadata.RpcKind_SINGLE_REQUEST_SINGLE_RESPONSE:
		return types.CALL, nil
	case rpcmetadata.RpcKind_SINGLE_REQUEST_NO_RESPONSE:
		return types.ONEWAY, nil
	}
	return 0, fmt.Errorf("unsupported RpcKind %v", kind)
}

func compressionAlgorithmFromCompressionConfig(compressionConfig *rpcmetadata.CompressionConfig) rpcmetadata.CompressionAlgorithm {
	if compressionConfig == nil {
		return rpcmetadata.CompressionAlgorithm_NONE
	}

	compression := rpcmetadata.CompressionAlgorithm_NONE
	codecConfig := compressionConfig.GetCodecConfig()
	if zlibConfig := codecConfig.GetZlibConfig(); zlibConfig != nil {
		switch zlibConfig.GetLevelPreset() {
		case rpcmetadata.ZlibCompressionLevelPreset_DEFAULT:
			compression = rpcmetadata.CompressionAlgorithm_ZLIB
		case rpcmetadata.ZlibCompressionLevelPreset_LESS:
			compression = rpcmetadata.CompressionAlgorithm_ZLIB_LESS
		case rpcmetadata.ZlibCompressionLevelPreset_MORE:
			compression = rpcmetadata.CompressionAlgorithm_ZLIB_MORE
		default:
			compression = rpcmetadata.CompressionAlgorithm_ZLIB
		}
	} else if zstdConfig := codecConfig.GetZstdConfig(); zstdConfig != nil {
		switch zstdConfig.GetLevelPreset() {
		case rpcmetadata.ZstdCompressionLevelPreset_DEFAULT:
			compression = rpcmetadata.CompressionAlgorithm_ZSTD
		case rpcmetadata.ZstdCompressionLevelPreset_LESS:
			compression = rpcmetadata.CompressionAlgorithm_ZSTD_LESS
		case rpcmetadata.ZstdCompressionLevelPreset_MORE:
			compression = rpcmetadata.CompressionAlgorithm_ZSTD_MORE
		default:
			compression = rpcmetadata.CompressionAlgorithm_ZSTD
		}
	} else if lz4Config := codecConfig.GetLz4Config(); lz4Config != nil {
		switch lz4Config.GetLevelPreset() {
		case rpcmetadata.Lz4CompressionLevelPreset_DEFAULT:
			compression = rpcmetadata.CompressionAlgorithm_LZ4
		case rpcmetadata.Lz4CompressionLevelPreset_LESS:
			compression = rpcmetadata.CompressionAlgorithm_LZ4_LESS
		case rpcmetadata.Lz4CompressionLevelPreset_MORE:
			compression = rpcmetadata.CompressionAlgorithm_LZ4_MORE
		default:
			compression = rpcmetadata.CompressionAlgorithm_LZ4
		}
	} else if customConfig := codecConfig.GetCustomConfig(); customConfig != nil {
		compression = rpcmetadata.CompressionAlgorithm_CUSTOM
	}
	return compression
}

func maybeCompress(data []byte, compression rpcmetadata.CompressionAlgorithm) ([]byte, error) {
	switch compression {
	case rpcmetadata.CompressionAlgorithm_NONE:
		return data, nil
	case rpcmetadata.CompressionAlgorithm_ZSTD:
		return compressZstd(data)
	case rpcmetadata.CompressionAlgorithm_ZSTD_LESS:
		return compressZstdLess(data)
	case rpcmetadata.CompressionAlgorithm_ZSTD_MORE:
		return compressZstdMore(data)
	case rpcmetadata.CompressionAlgorithm_ZLIB:
		return compressZlib(data)
	case rpcmetadata.CompressionAlgorithm_ZLIB_LESS:
		return compressZlibLess(data)
	case rpcmetadata.CompressionAlgorithm_ZLIB_MORE:
		return compressZlibMore(data)
	default:
		return nil, errors.New("unknown or unsupported compression algorithm")
	}
}

func maybeDecompress(data []byte, compression rpcmetadata.CompressionAlgorithm) ([]byte, error) {
	switch compression {
	case rpcmetadata.CompressionAlgorithm_NONE:
		return data, nil
	case rpcmetadata.CompressionAlgorithm_ZSTD,
		rpcmetadata.CompressionAlgorithm_ZSTD_LESS,
		rpcmetadata.CompressionAlgorithm_ZSTD_MORE:
		return decompressZstd(data)
	case rpcmetadata.CompressionAlgorithm_ZLIB,
		rpcmetadata.CompressionAlgorithm_ZLIB_LESS,
		rpcmetadata.CompressionAlgorithm_ZLIB_MORE:
		return decompressZlib(data)
	default:
		return nil, errors.New("unknown or unsupported compression algorithm")
	}
}
