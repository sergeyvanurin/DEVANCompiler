//
// Created by deliza on 11.03.2021.
//

#include "LogicalOrExpression.h"

LogicalOrExpression::LogicalOrExpression(Expression *expr1, Expression *expr2, yy::location loc): expr1(expr1), expr2(expr2), Expression(loc) {}

bool LogicalOrExpression::eval() const {
    return expr1->eval() || expr2->eval();
}

void LogicalOrExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}