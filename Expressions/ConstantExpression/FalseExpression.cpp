//
// Created by deliza on 11.03.2021.
//

#include "FalseExpression.h"

FalseExpression::FalseExpression(yy::location loc): Expression(loc) {}

std::variant<int, std::string> FalseExpression::eval() const {
    return 0;
}

void FalseExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

std::string FalseExpression::EvalType(ScopeLayer *scope) {
    return "bool";
}
