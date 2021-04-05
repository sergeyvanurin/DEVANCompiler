//
// Created by deliza on 03.03.2021.
//
#include "Expression.h"
#ifndef DEVANCOMPILER_MODEXPRESSION_H
#define DEVANCOMPILER_MODEXPRESSION_H

class ModExpression: public Expression {
public:
    ModExpression(Expression* expr1, Expression* expr2, yy::location loc);
    std::variant<int, std::string> eval() const override;
    void Accept(Visitor* visitor) override;

    Expression* expr1;
    Expression* expr2;
};


#endif //DEVANCOMPILER_MODEXPRESSION_H
