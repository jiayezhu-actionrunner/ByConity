/*
 * Copyright 2016-2023 ClickHouse, Inc.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


/*
 * This file may have been modified by Bytedance Ltd. and/or its affiliates (“ Bytedance's Modifications”).
 * All Bytedance's Modifications are Copyright (2023) Bytedance Ltd. and/or its affiliates.
 */

#include <Storages/registerStorages.h>
#include <Storages/StorageFactory.h>

#if !defined(ARCADIA_BUILD)
#    include <Common/config.h>
#    include "config_core.h"
#endif

namespace DB
{

void registerStorageLog(StorageFactory & factory);
void registerStorageTinyLog(StorageFactory & factory);
void registerStorageStripeLog(StorageFactory & factory);
void registerStorageMergeTree(StorageFactory & factory);
void registerStorageNull(StorageFactory & factory);
void registerStorageMerge(StorageFactory & factory);
void registerStorageBuffer(StorageFactory & factory);
void registerStorageDistributed(StorageFactory & factory);
void registerStorageMemory(StorageFactory & factory);
void registerStorageFile(StorageFactory & factory);
void registerStorageURL(StorageFactory & factory);
void registerStorageDictionary(StorageFactory & factory);
void registerStorageSet(StorageFactory & factory);
void registerStorageJoin(StorageFactory & factory);
void registerStorageView(StorageFactory & factory);
void registerStorageMaterializedView(StorageFactory & factory);
void registerStorageLiveView(StorageFactory & factory);
void registerStorageGenerateRandom(StorageFactory & factory);

#if USE_AWS_S3
void registerStorageS3(StorageFactory & factory);
void registerStorageCOS(StorageFactory & factory);
void registerStorageCnchS3(StorageFactory & factory);
void registerStorageCloudS3(StorageFactory & factory);
#endif

#if USE_HDFS
void registerStorageHDFS(StorageFactory & factory);
void registerStorageCnchHDFS(StorageFactory & factory);
void registerStorageCloudHDFS(StorageFactory & factory);
#endif

void registerStorageODBC(StorageFactory & factory);
void registerStorageJDBC(StorageFactory & factory);

#if USE_MYSQL
void registerStorageMySQL(StorageFactory & factory);
#endif

void registerStorageMongoDB(StorageFactory & factory);

#if USE_RDKAFKA
/// void registerStorageKafka(StorageFactory & factory);
void registerStorageCnchKafka(StorageFactory & factory);
#endif

#if USE_AMQPCPP
void registerStorageRabbitMQ(StorageFactory & factory);
#endif

#if USE_ROCKSDB
void registerStorageEmbeddedRocksDB(StorageFactory & factory);
#endif

#if USE_LIBPQXX
void registerStoragePostgreSQL(StorageFactory & factory);
void registerStorageMaterializedPostgreSQL(StorageFactory & factory);
#endif

#if USE_MYSQL || USE_LIBPQXX
void registerStorageExternalDistributed(StorageFactory & factory);
#endif

void registerStorageCnchHive(StorageFactory & factory);
void registerStorageCloudHive(StorageFactory & factory);

#if USE_JAVA_EXTENSIONS
void registerStorageHudi(StorageFactory & factory);
#endif

void registerStorages()
{
    auto & factory = StorageFactory::instance();

    registerStorageLog(factory);
    registerStorageTinyLog(factory);
    registerStorageStripeLog(factory);
    registerStorageMergeTree(factory);
    registerStorageNull(factory);
    registerStorageMerge(factory);
    registerStorageBuffer(factory);
    registerStorageDistributed(factory);
    registerStorageMemory(factory);
    registerStorageFile(factory);
    registerStorageURL(factory);
    registerStorageDictionary(factory);
    registerStorageSet(factory);
    registerStorageJoin(factory);
    registerStorageView(factory);
    registerStorageMaterializedView(factory);
    registerStorageLiveView(factory);
    registerStorageGenerateRandom(factory);

    #if USE_AWS_S3
    registerStorageS3(factory);
    registerStorageCOS(factory);
    registerStorageCnchS3(factory);
    registerStorageCloudS3(factory);
    #endif

    #if USE_HDFS
    registerStorageHDFS(factory);
    registerStorageCnchHDFS(factory);
    registerStorageCloudHDFS(factory);
    #endif

    registerStorageODBC(factory);
    registerStorageJDBC(factory);

    #if USE_MYSQL
    registerStorageMySQL(factory);
    #endif

    registerStorageMongoDB(factory);

    #if USE_RDKAFKA
    /// registerStorageKafka(factory);
    registerStorageCnchKafka(factory);
    #endif

    registerStorageCnchHive(factory);
    registerStorageCloudHive(factory);

    #if USE_AMQPCPP
    registerStorageRabbitMQ(factory);
    #endif

    #if USE_ROCKSDB
    registerStorageEmbeddedRocksDB(factory);
    #endif

    #if USE_LIBPQXX
    registerStoragePostgreSQL(factory);
    registerStorageMaterializedPostgreSQL(factory);
    #endif

    #if USE_MYSQL || USE_LIBPQXX
    registerStorageExternalDistributed(factory);
    #endif

    #if USE_JAVA_EXTENSIONS
    registerStorageHudi(factory);
    #endif
}

}
