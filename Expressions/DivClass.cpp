//
// Created by Sergey Vanurin on 01.03.2021.
//

#include "DivClass.h"


DivExpression::DivExpression(Expression *expr1, Expression *expr2): expr1(expr1), expr2(expr2) {}

int DivExpression::eval() const {
    return expr1->eval() * expr2->eval();
}

void DivExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);

}