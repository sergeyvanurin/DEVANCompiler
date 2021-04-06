//
// Created by deliza on 11.03.2021.
//

#include <variant>
#include "IndexExpression.h"

IndexExpression::IndexExpression(Expression *inner, Expression *outer, yy::location loc): inner(inner), outer(outer), Expression(loc) {}

std::variant<int, std::string> IndexExpression::eval() const {
    return inner->eval();
}

void IndexExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);

}

Type IndexExpression::EvalType(ScopeLayer *scope) {
    auto type = outer->GetType(scope);
    if (!type.is_array){
        throw std::runtime_error("You cant indexing of non-array object");
    }
    if (inner->GetType(scope) != Type("int")){
        throw std::runtime_error("Index must be int");
    }
    return Type(type.type_name);
}
