//
// Created by deliza on 11.03.2021.
//

#ifndef DEVANCOMPILER_INDEXEXPRESSION_H
#define DEVANCOMPILER_INDEXEXPRESSION_H

#include "Expression.h"

class IndexExpression : public Expression {
public:
    IndexExpression(Expression *inner, Expression *outer, yy::location loc);
    std::variant<int, std::string> eval() const override;
    void Accept(Visitor* visitor) override;

private:
    std::string EvalType(ScopeLayer *scope) override;

public:
    Expression* inner;
    Expression* outer;
};


#endif //DEVANCOMPILER_INDEXEXPRESSION_H
