//
// Created by Sergey Vanurin on 04.03.2021.
//

#include "Statement.h"
#include <vector>
#ifndef DEVANCOMPILER_STATEMENTS_H
#define DEVANCOMPILER_STATEMENTS_H


class StatementList: public Statement {
public:
    StatementList(Scope* Scope, yy::location loc);
    void AddStatement(Statement* statement);
    void Accept(Visitor* visitor) override;

    std::vector<Statement*> statements;
};


#endif //DEVANCOMPILER_STATEMENTS_H
