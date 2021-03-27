//
// Created by Sergey Vanurin on 02.03.2021.
//

#include "VarAssignment.h"

VarAssignment::VarAssignment(Expression* var_name, Expression *new_value, Scope *scope, yy::location loc)
        : var_name(var_name), new_value(new_value), Statement(scope, loc) {}

void VarAssignment::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

