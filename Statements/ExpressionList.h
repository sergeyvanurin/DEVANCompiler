//
// Created by deliza on 27.03.2021.
//

#ifndef DEVANCOMPILER_EXPRESSIONLIST_H
#define DEVANCOMPILER_EXPRESSIONLIST_H


#include <Expressions/Expression.h>
#include <vector>
#include "Statement.h"

class ExpressionList : Statement {
public:
    explicit ExpressionList(Scope* scope, yy::location loc);
    void Accept(Visitor* visitor) override;
    void AddExpression(Expression* expr);
    std::vector<Expression*> expressions;
};


#endif //DEVANCOMPILER_EXPRESSIONLIST_H
