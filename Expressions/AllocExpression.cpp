//
// Created by arseny on 07.04.2021.
//

#include "AllocExpression.h"

#include <utility>

AllocExpression::AllocExpression(Type type, yy::location loc) : type(std::move(type)), Expression(loc) {

}

std::variant<int, std::string> AllocExpression::eval() const {
    return 0;
}

void AllocExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

Type AllocExpression::EvalType(ScopeLayer *scope) {
    return type;
}
