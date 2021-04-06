//
// Created by arseny on 06.04.2021.
//

#ifndef DEVANCOMPILER_BINARYEXPRESSION_H
#define DEVANCOMPILER_BINARYEXPRESSION_H


#include <Expressions/Expression.h>

class BinaryExpression : public Expression {
public:
    BinaryExpression (Expression *expr1, Expression *expr2, yy::location loc);
    Expression* expr1;
    Expression* expr2;
};


#endif //DEVANCOMPILER_BINARYEXPRESSION_H
