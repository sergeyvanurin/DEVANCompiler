//
// Created by deliza on 11.03.2021.
//

#include "IndexExpression.h"

IndexExpression::IndexExpression(Expression *inner, Expression *outer, yy::location loc): inner(inner), outer(outer), Expression(loc) {}

int IndexExpression::eval() const {
    return inner->eval();
}

void IndexExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);

}
