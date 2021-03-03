//
// Created by Sergey Vanurin on 01.03.2021.
//

#include "SubExpression.h"

SubExpression::SubExpression(Expression *expr1, Expression *expr2, yy::location loc): expr1(expr1), expr2(expr2), loc(loc) {}

int SubExpression::eval() const {
    return expr1->eval() - expr2->eval();
}

void SubExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);

}

