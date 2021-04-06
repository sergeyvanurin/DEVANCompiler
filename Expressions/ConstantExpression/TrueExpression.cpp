//
// Created by deliza on 11.03.2021.
//

#include <variant>
#include "TrueExpression.h"

TrueExpression::TrueExpression(yy::location loc): Expression(loc) {}

std::variant<int, std::string> TrueExpression::eval() const {
    return true;
}

void TrueExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

std::string TrueExpression::EvalType(ScopeLayer *scope) {
    return "bool";
}
