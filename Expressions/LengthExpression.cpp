//
// Created by deliza on 27.03.2021.
//

#include "LengthExpression.h"

void LengthExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

LengthExpression::LengthExpression(Expression *array_expr, yy::location loc): array_expr(array_expr), Expression(loc) {

}

int LengthExpression::eval() const {
    return 0;
}
