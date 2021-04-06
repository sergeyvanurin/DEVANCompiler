//
// Created by Sergey Vanurin on 02.03.2021.
//

#include <variant>
#include <algorithm>
#include "IdentExpression.h"

IdentExpression::IdentExpression(std::string& var_name, yy::location loc): var_name(var_name), Expression(loc) {
    std::vector<std::string> reserved = {"System", "out", "println", "main", "length"};
    if (std::find(reserved.begin(), reserved.end(), var_name) != reserved.end()) {
        throw std::runtime_error("Name " + var_name + " is reserved");
    }
}

void IdentExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);

}

std::variant<int, std::string> IdentExpression::eval() const {
    return var_name;
}

Type IdentExpression::EvalType(ScopeLayer *scope) {
    auto var = scope->GetVariableByName(var_name);
    if (var == nullptr){
        throw std::runtime_error("No variable " + var_name + " at this scope");
    }
    return var->type;
}


