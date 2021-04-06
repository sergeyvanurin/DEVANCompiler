//
// Created by arseny on 06.04.2021.
//

#ifndef DEVANCOMPILER_ARITHMETICEXPRESSION_H
#define DEVANCOMPILER_ARITHMETICEXPRESSION_H

#include <Expressions/BinaryExpression/BinaryExpression.h>

class ArithmeticExpression : public BinaryExpression {
public:
    ArithmeticExpression(Expression *expr1, Expression *expr2, yy::location loc);

    Type EvalType(ScopeLayer *scope) override;
};


#endif //DEVANCOMPILER_ARITHMETICEXPRESSION_H
