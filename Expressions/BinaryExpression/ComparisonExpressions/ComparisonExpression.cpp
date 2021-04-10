//
// Created by arseny on 06.04.2021.
//

#include "ComparisonExpression.h"

std::string ComparisonExpression::EvalType(ScopeLayer *scope) {
    if (expr1->GetType(scope) != "int" || expr2->GetType(scope) != "int") {
        throw std::runtime_error("TypeError: Cant compare non-int types");
    }
    return "bool";
}

ComparisonExpression::ComparisonExpression(Expression *expr1, Expression *expr2, yy::location loc) : BinaryExpression(
        expr1, expr2, loc) {

}
