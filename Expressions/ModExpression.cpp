//
// Created by deliza on 03.03.2021.
//

#include "ModExpression.h"

ModExpression::ModExpression(Expression *expr1, Expression *expr2, yy::location loc): expr1(expr1), expr2(expr2), Expression(loc) {}

int ModExpression::eval() const {
    return expr1->eval() + expr2->eval();
}

void ModExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);

}
