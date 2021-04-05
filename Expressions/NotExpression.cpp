//
// Created by deliza on 11.03.2021.
//

#include <variant>
#include "NotExpression.h"

NotExpression::NotExpression(Expression *expr, yy::location loc): expr(expr), Expression(loc) {}

std::variant<int, std::string> NotExpression::eval() const {
    return !std::get<int>(expr->eval());
}

void NotExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}