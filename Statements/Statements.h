//
// Created by Sergey Vanurin on 04.03.2021.
//

#include "Statement.h"
#include <queue>
#ifndef DEVANCOMPILER_STATEMENTS_H
#define DEVANCOMPILER_STATEMENTS_H


class Statements: public Statement {
public:
    Statements(Scope* Scope);
    std::queue<Statement*> statements;
    void Accept(Visitor* visitor) override;
};


#endif //DEVANCOMPILER_STATEMENTS_H
