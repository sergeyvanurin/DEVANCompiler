//
// Created by deliza on 27.03.2021.
//

#ifndef DEVANCOMPILER_RETURN_H
#define DEVANCOMPILER_RETURN_H


#include <Expressions/Expression.h>
#include "Statement.h"

class Return : public Statement {
public:
    explicit Return(Expression* expr, Scope* scope, yy::location loc);
    void Accept(Visitor* visitor) override;
    Expression* expr;
};


#endif //DEVANCOMPILER_RETURN_H
