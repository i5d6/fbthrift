<?hh
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
 *
 */

// @oss-enable: use namespace FlibSL\{C, Math, Str, Vec};

/**
 * Base interface for Thrift clients
 */
<<Oncalls('thrift')>> // @oss-disable
interface IThriftClient {
  public function getEventHandler()[]: TClientEventHandler;
  public function setEventHandler(
    TClientEventHandler $handler,
  )[write_props]: this;
  public function getAsyncHandler()[]: TClientAsyncHandler;
  public function setAsyncHandler(
    TClientAsyncHandler $handler,
  )[write_props]: this;
  public function getHHFrameMetadata()[]: ?string;
  abstract const string THRIFT_SVC_NAME;
}
