//
// Created by deliza on 11.03.2021.
//

#include <variant>
#include "EqualExpression.h"

EqualExpression::EqualExpression(Expression *expr1, Expression *expr2, yy::location loc) : BinaryExpression(expr1,
                                                                                                            expr2,
                                                                                                            loc) {}

std::variant<int, std::string> EqualExpression::eval() const {
    return expr1->eval() == expr2->eval();
}

void EqualExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

std::string EqualExpression::EvalType(ScopeLayer *scope) {
    if (expr1->GetType(nullptr) != expr2->GetType(nullptr)) {
        throw std::runtime_error("TypeError: types must be equal");
    }
    return "bool";
}
