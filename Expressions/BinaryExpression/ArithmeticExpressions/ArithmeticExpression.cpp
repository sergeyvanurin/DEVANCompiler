//
// Created by arseny on 06.04.2021.
//

#include "ArithmeticExpression.h"

Type ArithmeticExpression::EvalType(ScopeLayer *scope) {
    if (expr1->GetType(scope) != Type("int") || expr2->GetType(scope) != Type("int")) {
        std::cerr << loc << std::endl;
        throw std::runtime_error("TypeError: Arithmetic operation only for int");
    }
    return Type("int");
}

ArithmeticExpression::ArithmeticExpression(Expression *expr1, Expression *expr2, yy::location loc) : BinaryExpression(
        expr1, expr2, loc) {}
