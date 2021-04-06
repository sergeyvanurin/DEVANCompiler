//
// Created by deliza on 11.03.2021.
//

#include <variant>
#include "FieldInvokeExpression.h"

FieldInvokeExpression::FieldInvokeExpression(const std::string &field_name, yy::location loc): field_name(field_name), Expression(loc) {

}

std::variant<int, std::string> FieldInvokeExpression::eval() const {
    return 0;
}

void FieldInvokeExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

std::string FieldInvokeExpression::EvalType(ScopeLayer *scope) {
    STVariable* var = scope->GetCurrentClass()->FindFieldByName(field_name);
    if (var == nullptr){
        throw std::runtime_error("Class " + scope->GetCurrentClass()->GetName() +  " doesn't contain field " + field_name);
    }
    return var->type.type_name;
}