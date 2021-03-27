//
// Created by deliza on 11.03.2021.
//

#include "Expression.h"
#ifndef DEVANCOMPILER_LOGICALANDEXPRESSION_H
#define DEVANCOMPILER_LOGICALANDEXPRESSION_H



class LogicalAndExpression : public Expression {
public:
    LogicalAndExpression(Expression* expr1, Expression* expr2, yy::location loc);
    int eval() const override;
    void Accept(Visitor* visitor) override;
    Expression* expr1;
    Expression* expr2;
};


#endif //DEVANCOMPILER_LOGICALANDEXPRESSION_H
