//
// Created by deliza on 11.03.2021.
//

#include "NotExpression.h"

NotExpression::NotExpression(Expression *expr, yy::location loc): expr(expr), Expression(loc) {}

int NotExpression::eval() const {
    return !expr->eval();
}

void NotExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}