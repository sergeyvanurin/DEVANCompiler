//
// Created by Sergey Vanurin on 02.03.2021.
//

#include "IfElse.h"

IfElse::IfElse(Expression *expression, Statement *If, Statement *Else, Scope *scope, yy::location loc)
        : expr(expression), If(If), Else(Else), Statement(scope, loc) {}

void IfElse::Accept(Visitor *visitor) {
    visitor->Visit(this);
}


