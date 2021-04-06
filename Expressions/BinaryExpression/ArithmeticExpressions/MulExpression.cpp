//
// Created by Sergey Vanurin on 01.03.2021.
//

#include "MulExpression.h"

MulExpression::MulExpression(Expression *expr1, Expression *expr2, yy::location loc) : ArithmeticExpression(expr1,
                                                                                                            expr2,
                                                                                                            loc) {}

std::variant<int, std::string> MulExpression::eval() const {
    return std::get<int>(expr1->eval()) * std::get<int>(expr2->eval());
}

void MulExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}