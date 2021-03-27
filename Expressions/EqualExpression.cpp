//
// Created by deliza on 11.03.2021.
//

#include <variant>
#include "EqualExpression.h"

EqualExpression::EqualExpression(Expression *expr1, Expression *expr2, yy::location loc): expr1(expr1), expr2(expr2), Expression(loc) {}

std::variant<int, std::string> EqualExpression::eval() const {
    return expr1->eval() == expr2->eval();
}

void EqualExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}