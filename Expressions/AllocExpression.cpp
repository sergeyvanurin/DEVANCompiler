//
// Created by Sergey Vanurin on 07.04.2021.
//

#include "AllocExpression.h"

#include <utility>

AllocExpression::AllocExpression(Type type, Expression *size_expr, yy::location loc) : type(std::move(type)),
                                                                                       size_expr(size_expr),
                                                                                       Expression(loc) {
    if (size_expr != nullptr){
        type.is_array = true;
    }
}

std::variant<int, std::string> AllocExpression::eval() const {
    return 0;
}

void AllocExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

Type AllocExpression::EvalType(ScopeLayer *scope) {
    if (size_expr != nullptr) {
        if (type.type_name == "void") {
            std::cerr << loc << std::endl;
            throw std::runtime_error("Array of 'void' not allowed");
        }
        if (size_expr->GetType(scope) != Type("int")) {
            std::cerr << loc << std::endl;
            throw std::runtime_error("Array size expect 'int' but got '" + size_expr->GetType(scope).ToString() + "'");
        }
    }
    return type;
}
