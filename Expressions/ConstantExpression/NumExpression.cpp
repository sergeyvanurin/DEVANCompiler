//
// Created by Sergey Vanurin on 02.03.2021.
//

#include "NumExpression.h"

NumExpression::NumExpression(int value, yy::location loc): value_(value), Expression(loc) {}

void NumExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);

}

std::variant<int, std::string> NumExpression::eval() const {
    return value_;
}

Type NumExpression::EvalType(ScopeLayer *scope) {
    return Type("int");
}

int NumExpression::GetValue() const {
    return value_;
}
