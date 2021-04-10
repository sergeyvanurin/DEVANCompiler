//
// Created by deliza on 11.03.2021.
//

#include <variant>
#include "IndexExpression.h"

IndexExpression::IndexExpression(Expression *inner, Expression *outer, yy::location loc): inner(inner), outer(outer), Expression(loc) {}

std::variant<int, std::string> IndexExpression::eval() const {
    return inner->eval();
}

void IndexExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);

}

std::string IndexExpression::EvalType(ScopeLayer *scope) {
    // TODO check if array
    return std::string();
}
