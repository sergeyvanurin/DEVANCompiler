//
// Created by deliza on 27.03.2021.
//

#include "ExpressionList.h"

ExpressionList::ExpressionList(Scope *scope, yy::location loc) : Statement(scope, loc) {

}

void ExpressionList::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

void ExpressionList::AddExpression(Expression *expr) {
    expressions.push_back(expr);
}
