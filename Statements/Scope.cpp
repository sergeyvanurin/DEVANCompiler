//
// Created by Sergey Vanurin on 03.03.2021.
//

#include "Scope.h"

void Scope::add_variable(std::string& var_name, int var_value) {
    variables[var_name] = var_value;
}

void Scope::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

Scope *Scope::find_scope(std::string *var_name) {

}
