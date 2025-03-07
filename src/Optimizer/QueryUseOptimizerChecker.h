/*
 * Copyright (2022) Bytedance Ltd. and/or its affiliates
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

#pragma once

#include <Core/QueryProcessingStage.h>
#include <DataStreams/BlockIO.h>
#include <Parsers/ASTVisitor.h>
#include <Parsers/IAST_fwd.h>

namespace DB
{
class Context;

void turnOffOptimizer(ContextMutablePtr context, ASTPtr & node);

class QueryUseOptimizerChecker
{
public:
    static bool check(ASTPtr node, ContextMutablePtr context, bool insert_select_from_table = false);
};

struct QueryUseOptimizerContext
{
    ContextMutablePtr context;
    NameSet ctes;
};

class QueryUseOptimizerVisitor : public ASTVisitor<bool, QueryUseOptimizerContext>
{
public:
    bool visitNode(ASTPtr & node, QueryUseOptimizerContext &) override;
    bool visitASTSelectQuery(ASTPtr & node, QueryUseOptimizerContext &) override;
    bool visitASTTableJoin(ASTPtr & node, QueryUseOptimizerContext &) override;
    bool visitASTIdentifier(ASTPtr & node, QueryUseOptimizerContext &) override;
    bool visitASTFunction(ASTPtr & node, QueryUseOptimizerContext &) override;
    bool visitASTQuantifiedComparison(ASTPtr & node, QueryUseOptimizerContext &) override;
    const String & getReason() const { return reason; }

private:
    static void collectWithTableNames(ASTSelectQuery & query, NameSet & with_tables);
    String reason;
};

}
