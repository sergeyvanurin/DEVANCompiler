//
// Created by deliza on 11.03.2021.
//

#include "Expression.h"
#ifndef DEVANCOMPILER_NOTEXPRESSION_H
#define DEVANCOMPILER_NOTEXPRESSION_H


class NotExpression : public Expression {
public:
    NotExpression(Expression* expr, yy::location loc);
    int eval() const override;
    void Accept(Visitor* visitor) override;
private:
    Expression* expr;
};


#endif //DEVANCOMPILER_NOTEXPRESSION_H
