//
// Created by deliza on 07.04.2021.
//



#ifndef DEVANCOMPILER_SCOPEBLOCK_H
#define DEVANCOMPILER_SCOPEBLOCK_H

#include "Statement.h"
#include <Statements/StatementList.h>


class ScopeBlock : public Statement {
public:
    explicit ScopeBlock(StatementList* statements, yy::location loc);
    void Accept(Visitor* visitor) override;
    StatementList* statements;
};


#endif //DEVANCOMPILER_SCOPEBLOCK_H
