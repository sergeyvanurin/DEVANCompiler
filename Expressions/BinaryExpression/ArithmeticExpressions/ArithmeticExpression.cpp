//
// Created by arseny on 06.04.2021.
//

#include "ArithmeticExpression.h"

std::string ArithmeticExpression::EvalType(ScopeLayer *scope) {
    if (expr1->GetType(scope) != "int" || expr2->GetType(scope) != "int") {
        throw std::runtime_error("TypeError: Arithmetic operation only for int");
    }
    return "int";
}

ArithmeticExpression::ArithmeticExpression(Expression *expr1, Expression *expr2, yy::location loc) : BinaryExpression(
        expr1, expr2, loc) {}
