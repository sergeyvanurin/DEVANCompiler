//
// Created by Sergey Vanurin on 01.03.2021.
//

#include <variant>
#include "AddExpression.h"

AddExpression::AddExpression(Expression *expr1, Expression *expr2, yy::location loc): expr1(expr1), expr2(expr2), Expression(loc) {}

std::variant<int, std::string> AddExpression::eval() const {
    return std::get<int>(expr1->eval()) + std::get<int>(expr2->eval());
}

void AddExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}
