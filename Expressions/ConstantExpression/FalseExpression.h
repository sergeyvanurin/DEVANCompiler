//
// Created by deliza on 11.03.2021.
//

#include <variant>
#include "Expressions/Expression.h"
#ifndef DEVANCOMPILER_FALSEEXPRESSION_H
#define DEVANCOMPILER_FALSEEXPRESSION_H


class FalseExpression : public Expression {
public:
    FalseExpression(yy::location loc);
    std::variant<int, std::string> eval() const override;
    void Accept(Visitor* visitor) override;

private:
    std::string EvalType(ScopeLayer *scope) override;
};


#endif //DEVANCOMPILER_FALSEEXPRESSION_H
