//
// Created by deliza on 11.03.2021.
//

#include "Expression.h"
#ifndef DEVANCOMPILER_NOTEXPRESSION_H
#define DEVANCOMPILER_NOTEXPRESSION_H


class NotExpression : public Expression {
public:
    NotExpression(Expression* expr, yy::location loc);
    std::variant<int, std::string> eval() const override;
    void Accept(Visitor* visitor) override;
    Expression* expr;
};


#endif //DEVANCOMPILER_NOTEXPRESSION_H
