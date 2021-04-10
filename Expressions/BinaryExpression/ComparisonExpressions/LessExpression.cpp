//
// Created by deliza on 11.03.2021.
//

#include "LessExpression.h"

LessExpression::LessExpression(Expression *expr1, Expression *expr2, yy::location loc) : ComparisonExpression(expr1,
                                                                                                              expr2,
                                                                                                              loc) {}

std::variant<int, std::string> LessExpression::eval() const {
    return expr1->eval() < expr2->eval();
}

void LessExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}