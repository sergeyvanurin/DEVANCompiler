//
// Created by deliza on 11.03.2021.
//

#ifndef DEVANCOMPILER_TRUEEXPRESSION_H
#define DEVANCOMPILER_TRUEEXPRESSION_H

#include "Expressions/Expression.h"

class TrueExpression : public Expression {
public:
    TrueExpression(yy::location loc);
    std::variant<int, std::string> eval() const override;
    void Accept(Visitor* visitor) override;

private:
    Type EvalType(ScopeLayer *scope) override;
};


#endif //DEVANCOMPILER_TRUEEXPRESSION_H
