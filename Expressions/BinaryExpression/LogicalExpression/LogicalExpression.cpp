//
// Created by arseny on 06.04.2021.
//

#include "LogicalExpression.h"

std::string LogicalExpression::EvalType(ScopeLayer *scope) {
    if (expr1->GetType(nullptr) != "bool" || expr2->GetType(nullptr) != "bool") {
        throw std::runtime_error("TypeError: Logical operation only for bool");
    }
    return "bool";
}

LogicalExpression::LogicalExpression(Expression *expr1, Expression *expr2, yy::location loc) : BinaryExpression(expr1,
                                                                                                                expr2,
                                                                                                                loc) {}
