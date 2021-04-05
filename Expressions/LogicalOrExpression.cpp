//
// Created by deliza on 11.03.2021.
//

#include "LogicalOrExpression.h"

LogicalOrExpression::LogicalOrExpression(Expression *expr1, Expression *expr2, yy::location loc): expr1(expr1), expr2(expr2), Expression(loc) {}

std::variant<int, std::string> LogicalOrExpression::eval() const {
    return std::get<int>(expr1->eval()) || std::get<int>(expr2->eval());
}

void LogicalOrExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}