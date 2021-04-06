//
// Created by arseny on 06.04.2021.
//

#include "LogicalExpression.h"

Type LogicalExpression::EvalType(ScopeLayer *scope) {
    if (expr1->GetType(nullptr) != Type("bool") || expr2->GetType(nullptr) != Type("bool")) {
        throw std::runtime_error("TypeError: Logical operation only for bool");
    }
    return Type("bool");
}

LogicalExpression::LogicalExpression(Expression *expr1, Expression *expr2, yy::location loc) : BinaryExpression(expr1,
                                                                                                                expr2,
                                                                                                                loc) {}
