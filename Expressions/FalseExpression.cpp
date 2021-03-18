//
// Created by deliza on 11.03.2021.
//

#include "FalseExpression.h"

FalseExpression::FalseExpression(yy::location loc): Expression(loc) {}

int FalseExpression::eval() const {
    return false;
}

void FalseExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}