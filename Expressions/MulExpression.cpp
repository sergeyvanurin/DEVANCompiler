//
// Created by Sergey Vanurin on 01.03.2021.
//

#include "MulExpression.h"

MulExpression::MulExpression(Expression *expr1, Expression *expr2): expr1(expr1), expr2(expr2) {}

int MulExpression::eval() const {
    return expr1->eval() * expr2->eval();
}

void MulExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}