//
// Created by deliza on 11.03.2021.
//

#include "LogicalAndExpression.h"

LogicalAndExpression::LogicalAndExpression(Expression *expr1, Expression *expr2, yy::location loc): expr1(expr1), expr2(expr2), Expression(loc) {}

std::variant<int, std::string> LogicalAndExpression::eval() const {
    return std::get<int>(expr1->eval()) && std::get<int>(expr2->eval());
}

void LogicalAndExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}