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

Scope *Scope::find_scope(std::string& var_name) {
    if (this->variables.count(var_name) == 0){
        if (upper_scope == nullptr) return nullptr;
        else return this->upper_scope->find_scope(var_name);
    }
    else{
        return this;
    }
}

void Scope::modify_variable(std::string &var_name, int new_value) {
    Scope* found_scope = find_scope(var_name);
    if (found_scope == nullptr){
        add_variable(var_name, new_value);
    } else{
        found_scope->add_variable(var_name, new_value);
    }

}

Scope::Scope(int scope_num, Scope* upper_scope, yy::location loc): scope_num(scope_num), upper_scope(upper_scope), loc(loc) {
}
