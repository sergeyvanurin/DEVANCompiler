//
// Created by deliza on 27.03.2021.
//

#ifndef DEVANCOMPILER_LENGTHEXPRESSION_H
#define DEVANCOMPILER_LENGTHEXPRESSION_H


#include "Expression.h"
#include "FieldInvocExpression.h"

class LengthExpression : public Expression {
public:
    explicit LengthExpression(Expression* array_expr, yy::location loc);
    void Accept(Visitor* visitor) override;
    std::variant<int, std::string> eval() const override;

    Expression* array_expr;
};


#endif //DEVANCOMPILER_LENGTHEXPRESSION_H
