//
// Created by deliza on 27.03.2021.
//

#include <variant>
#include "MethodInvocation.h"
#include "ExpressionList.h"
#include <string>

void MethodInvocation::Accept(Visitor *visitor) {
    visitor->Visit(this);
}


MethodInvocation::MethodInvocation(Expression *expr, const std::string &name, ExpressionList *args, Scope *scope,
                                   yy::location loc) : class_expr(expr), method_name(name), arguments(args),
                                                       Statement(scope, loc), Expression(loc) {

}

std::variant<int, std::string> MethodInvocation::eval() const {
    return 0;
}

Type MethodInvocation::EvalType(ScopeLayer *scope) {
    auto class_name = class_expr->GetType(scope);
    if (class_name.is_array) {
        throw std::runtime_error("Array has only indexing and length methods");
    }
    auto class_ref = scope->GetClassByName(class_name.type_name);
    if (class_ref == nullptr) {
        throw std::runtime_error("No class '" + class_name.type_name + "' in scope");
    }
    auto method_ref = class_ref->FindMethodByName(method_name);
    if (method_ref == nullptr) {
        throw std::runtime_error("Class '" + class_name.type_name + "' doesn't have field '" + method_name + "'");
    }
    if (arguments->expressions.size() != method_ref->arguments.size()) {
        throw std::runtime_error("Method '" + method_name + "' of class '" + class_name.type_name + "' expect " +
                                 std::to_string(method_ref->arguments.size()) + " arguments but got " +
                                 std::to_string(arguments->expressions.size()));
    }
    for (size_t i = 0; i < method_ref->arguments.size(); ++i) {
        // TODO inheritance
        if (arguments->expressions[i]->GetType(scope) != *method_ref->arguments[i].type) {
            throw std::runtime_error("Method '" + method_name + "' of class '" + class_name.type_name + "' expect at " +
                                     std::to_string(i) + "-th argument type '" +
                                     method_ref->arguments[i].type->ToString() + "' but got '" +
                                     arguments->expressions[i]->GetType(scope).ToString() + "'");
        }
    }
    return *method_ref->return_type;
}
