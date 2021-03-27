//
// Created by deliza on 27.03.2021.
//

#ifndef DEVANCOMPILER_PRINT_H
#define DEVANCOMPILER_PRINT_H


#include <Expressions/Expression.h>
#include "Statement.h"

class Print : public Statement {
public:
    explicit Print(Expression* expr, Scope* scope, yy::location loc);
    void Accept(Visitor* visitor) override;
    Expression* expr;
};


#endif //DEVANCOMPILER_PRINT_H
