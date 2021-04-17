//
// Created by deliza on 27.03.2021.
//

#include <variant>
#include "LengthExpression.h"

void LengthExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

LengthExpression::LengthExpression(Expression *array_expr, yy::location loc): array_expr(array_expr), Expression(loc) {

}

std::variant<int, std::string> LengthExpression::eval() const {
    return 0;
}

Type LengthExpression::EvalType(ScopeLayer *scope) {
    auto type = array_expr->GetType(scope);
    if (!type.is_array){
        std::cerr << loc << std::endl;
        throw std::runtime_error("Only array have length");
    }
    return Type("int");
}
