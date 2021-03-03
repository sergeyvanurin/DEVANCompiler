//
// Created by Sergey Vanurin on 02.03.2021.
//

#include "While.h"

While::While(Expression *expr, Statement *statement, Scope *scope) : expr(expr), statement(statement), Statement(scope) {}

void While::Accept(Visitor *visitor) {
    visitor->Visit(this);
}