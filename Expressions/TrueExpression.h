//
// Created by deliza on 11.03.2021.
//

#include "Expression.h"
#ifndef DEVANCOMPILER_TRUEEXPRESSION_H
#define DEVANCOMPILER_TRUEEXPRESSION_H


class TrueExpression : public Expression {
public:
    TrueExpression(yy::location loc);
    std::variant<int, std::string> eval() const override;
    void Accept(Visitor* visitor) override;
};


#endif //DEVANCOMPILER_TRUEEXPRESSION_H
