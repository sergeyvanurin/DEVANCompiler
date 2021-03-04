//
// Created by deliza on 04.03.2021.
//

#include <queue>
#include "Statement.h"

#ifndef DEVANCOMPILER_DECLARATIONS_H
#define DEVANCOMPILER_DECLARATIONS_H


class Declarations : public Statement {
public:
    Declarations(Scope* Scope, yy::location loc);
    std::queue<Statement*> declarations;
    void Accept(Visitor* visitor) override;
};


#endif //DEVANCOMPILER_DECLARATIONS_H
