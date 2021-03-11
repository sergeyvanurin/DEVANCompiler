//
// Created by deliza on 11.03.2021.
//

#include "LogicalAndExpression.h"

LogicalAndExpression::LogicalAndExpression(Expression *expr1, Expression *expr2, yy::location loc): expr1(expr1), expr2(expr2), Expression(loc) {}

bool LogicalAndExpression::eval() const {
    return expr1->eval() && expr2->eval();
}

void LogicalAndExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}