//
// Created by Sergey Vanurin on 01.03.2021.
//
#include "Expression.h"
#ifndef DEVANCOMPILER_ADDEXPRESSION_H
#define DEVANCOMPILER_ADDEXPRESSION_H


class AddExpression: public Expression {
public:
    AddExpression(Expression* expr1, Expression* expr2, yy::location loc);
    int eval() const override;
    void Accept(Visitor* visitor) override;

private:
    Expression* expr1;
    Expression* expr2;
};


#endif //DEVANCOMPILER_ADDEXPRESSION_H
