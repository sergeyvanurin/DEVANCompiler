//
// Created by Sergey Vanurin on 02.03.2021.
//

#include "Expression.h"
#ifndef DEVANCOMPILER_NUMEXPRESSION_H
#define DEVANCOMPILER_NUMEXPRESSION_H


class NumExpression: public Expression {
public:
    explicit NumExpression(int value);
    void Accept(Visitor* visitor) override;
    int eval() const override;

private:
    int value;

};


#endif //DEVANCOMPILER_NUMEXPRESSION_H
