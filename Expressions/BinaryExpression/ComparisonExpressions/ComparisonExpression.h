//
// Created by arseny on 06.04.2021.
//

#ifndef DEVANCOMPILER_COMPARISONEXPRESSION_H
#define DEVANCOMPILER_COMPARISONEXPRESSION_H

#include <Expressions/BinaryExpression/BinaryExpression.h>

class ComparisonExpression: public BinaryExpression {
public:
    ComparisonExpression(Expression *expr1, Expression *expr2, yy::location loc);
private:
    Type EvalType(ScopeLayer *scope) override;
};


#endif //DEVANCOMPILER_COMPARISONEXPRESSION_H
