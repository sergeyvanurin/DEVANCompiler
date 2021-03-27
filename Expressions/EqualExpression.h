//
// Created by deliza on 11.03.2021.
//

#include "Expression.h"
#ifndef DEVANCOMPILER_EQUALEXPRESSION_H
#define DEVANCOMPILER_EQUALEXPRESSION_H


class EqualExpression : public Expression {
public:
    EqualExpression(Expression* expr1, Expression* expr2, yy::location loc);
    std::variant<int, std::string> eval() const override;
    void Accept(Visitor* visitor) override;

    Expression* expr1;
    Expression* expr2;
};


#endif //DEVANCOMPILER_EQUALEXPRESSION_H
