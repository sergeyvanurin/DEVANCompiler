//
// Created by Sergey Vanurin on 06.04.2021.
//

#include "BinaryExpression.h"

BinaryExpression::BinaryExpression(Expression *expr1, Expression *expr2, yy::location loc) : expr1(expr1), expr2(expr2),
                                                                                             Expression(loc) {

}
