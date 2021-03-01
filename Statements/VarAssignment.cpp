//
// Created by Sergey Vanurin on 02.03.2021.
//

#include "VarAssignment.h"

VarAssignment::VarAssignment(std::string &var_name, Expression *new_value): var_name(var_name), new_value(new_value) {}

void VarAssignment::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

