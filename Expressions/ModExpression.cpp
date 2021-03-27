//
// Created by deliza on 03.03.2021.
//

#include <variant>
#include "ModExpression.h"

ModExpression::ModExpression(Expression *expr1, Expression *expr2, yy::location loc): expr1(expr1), expr2(expr2), Expression(loc) {}

std::variant<int, std::string> ModExpression::eval() const {
    return std::get<int>(expr1->eval()) % std::get<int>(expr2->eval());
}

void ModExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);

}
