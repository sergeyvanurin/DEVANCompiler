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

Type NotExpression::EvalType(ScopeLayer *scope) {
    if (expr->GetType(scope) != Type("bool")){
        throw std::runtime_error("TypeError: Only bool can be negated");
    }
    return Type("bool");
}
