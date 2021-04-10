//
// Created by Sergey Vanurin on 02.03.2021.
//

#ifndef DEVANCOMPILER_NUMEXPRESSION_H
#define DEVANCOMPILER_NUMEXPRESSION_H

#include <variant>
#include "Expressions/Expression.h"

class NumExpression: public Expression {
public:
    explicit NumExpression(int value, yy::location loc);
    void Accept(Visitor* visitor) override;
    std::variant<int, std::string> eval() const override;

private:
    int value;

    std::string EvalType(ScopeLayer *scope) override;
};


#endif //DEVANCOMPILER_NUMEXPRESSION_H
