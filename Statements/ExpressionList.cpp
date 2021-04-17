//
// Created by deliza on 27.03.2021.
//

#include "ExpressionList.h"

ExpressionList::ExpressionList(yy::location loc) : Statement(loc) {

}

void ExpressionList::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

void ExpressionList::AddExpression(Expression *expr) {
    expressions.push_back(expr);
}
