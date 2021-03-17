//
// Created by deliza on 11.03.2021.
//

#include "TrueExpression.h"

TrueExpression::TrueExpression(yy::location loc): Expression(loc) {}

int TrueExpression::eval() const {
    return true;
}

void TrueExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}