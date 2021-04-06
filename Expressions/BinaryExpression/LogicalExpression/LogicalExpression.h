//
// Created by arseny on 06.04.2021.
//

#ifndef DEVANCOMPILER_LOGICALEXPRESSION_H
#define DEVANCOMPILER_LOGICALEXPRESSION_H

#include <Expressions/BinaryExpression/BinaryExpression.h>

class LogicalExpression : public BinaryExpression {
public:
    LogicalExpression(Expression *expr1, Expression *expr2, yy::location loc);

private:
    Type EvalType(ScopeLayer *scope) override;
};


#endif //DEVANCOMPILER_LOGICALEXPRESSION_H
