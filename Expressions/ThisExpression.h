//
// Created by deliza on 27.03.2021.
//

#ifndef DEVANCOMPILER_THISEXPRESSION_H
#define DEVANCOMPILER_THISEXPRESSION_H


#include "Expression.h"

class ThisExpression : public Expression {
public:
    explicit ThisExpression(yy::location loc);
    void Accept(Visitor* visitor) override;
    std::variant<int, std::string> eval() const override;

private:
    std::string EvalType(ScopeLayer *scope) override;
};


#endif //DEVANCOMPILER_THISEXPRESSION_H
