//
// Created by Sergey Vanurin on 01.03.2021.
//

#include <variant>
#include "Expression.h"
#ifndef DEVANCOMPILER_MULEXPRESSION_H
#define DEVANCOMPILER_MULEXPRESSION_H


class MulExpression: public Expression {
public:
    MulExpression(Expression* expr1, Expression* expr2, yy::location loc);
    std::variant<int, std::string> eval() const override;
    void Accept(Visitor* visitor) override;

    Expression* expr1;
    Expression* expr2;
};

#endif //DEVANCOMPILER_MULEXPRESSION_H
