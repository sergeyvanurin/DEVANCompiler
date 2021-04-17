//
// Created by deliza on 11.03.2021.
//

#include "Expressions/Expression.h"
#ifndef DEVANCOMPILER_EQUALEXPRESSION_H
#define DEVANCOMPILER_EQUALEXPRESSION_H

#include "BinaryExpression.h"

class EqualExpression : public BinaryExpression {
public:
    EqualExpression(Expression* expr1, Expression* expr2, yy::location loc);
    std::variant<int, std::string> eval() const override;
    void Accept(Visitor* visitor) override;

private:
    Type EvalType(ScopeLayer *scope) override;
};


#endif //DEVANCOMPILER_EQUALEXPRESSION_H
