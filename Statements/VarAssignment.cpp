//
// Created by Sergey Vanurin on 02.03.2021.
//

#include "VarAssignment.h"

VarAssignment::VarAssignment(std::string &var_name, Expression *new_value, Scope *scope)
        : var_name(var_name), new_value(new_value), Statement(scope) {}

void VarAssignment::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

