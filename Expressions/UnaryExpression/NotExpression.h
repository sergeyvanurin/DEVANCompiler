//
// Created by deliza on 11.03.2021.
//

#ifndef DEVANCOMPILER_NOTEXPRESSION_H
#define DEVANCOMPILER_NOTEXPRESSION_H

#include "Expressions/Expression.h"

class NotExpression : public Expression {
public:
    NotExpression(Expression* expr, yy::location loc);
    std::variant<int, std::string> eval() const override;
    void Accept(Visitor* visitor) override;
    Expression* expr;
private:
    std::string EvalType(ScopeLayer *scope) override;
};


#endif //DEVANCOMPILER_NOTEXPRESSION_H
