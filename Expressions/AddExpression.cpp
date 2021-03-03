//
// Created by Sergey Vanurin on 01.03.2021.
//

#include "AddExpression.h"

AddExpression::AddExpression(Expression *expr1, Expression *expr2, yy::location loc): expr1(expr1), expr2(expr2), loc(loc) {}

int AddExpression::eval() const {
    return expr1->eval() + expr2->eval();
}

void AddExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);

}
