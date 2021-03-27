//
// Created by Sergey Vanurin on 01.03.2021.
//

#include "Expression.h"
#ifndef DEVANCOMPILER_SUBEXPRESSION_H
#define DEVANCOMPILER_SUBEXPRESSION_H


class SubExpression: public Expression {
public:
    SubExpression(Expression* expr1, Expression* expr2, yy::location loc);
    int eval() const override;
    void Accept(Visitor* visitor) override;

    Expression* expr1;
    Expression* expr2;
};


#endif //DEVANCOMPILER_SUBEXPRESSION_H
