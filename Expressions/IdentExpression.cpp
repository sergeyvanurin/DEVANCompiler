//
// Created by Sergey Vanurin on 02.03.2021.
//

#include <variant>
#include "IdentExpression.h"

IdentExpression::IdentExpression(std::string& var_name, yy::location loc): var_name(var_name), Expression(loc) {}

void IdentExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);

}

std::variant<int, std::string> IdentExpression::eval() const {
    return var_name;
}

std::string IdentExpression::EvalType(ScopeLayer *scope) {
    auto var = scope->GetVariableByName(var_name);
    if (var == nullptr){
        throw std::runtime_error("No variable " + var_name + " at this scope");
    }
    return var->type.type_name;
}


