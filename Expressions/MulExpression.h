//
// Created by Sergey Vanurin on 01.03.2021.
//

#include "Expression.h"
#ifndef DEVANCOMPILER_MULEXPRESSION_H
#define DEVANCOMPILER_MULEXPRESSION_H


class MulExpression: public Expression {
public:
    MulExpression(Expression* expr1, Expression* expr2, yy::location loc);
    int eval() const override;
    void Accept(Visitor* visitor) override;

private:
    Expression* expr1;
    Expression* expr2;
    yy::location loc;
};

#endif //DEVANCOMPILER_MULEXPRESSION_H