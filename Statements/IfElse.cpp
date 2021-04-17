//
// Created by Sergey Vanurin on 02.03.2021.
//

#include "IfElse.h"

IfElse::IfElse(Expression *expression, Statement *If, Statement *Else, yy::location loc)
        : expr(expression), If(If), Else(Else), Statement(loc) {}

void IfElse::Accept(Visitor *visitor) {
    visitor->Visit(this);
}


