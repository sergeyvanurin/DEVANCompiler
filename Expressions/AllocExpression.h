//
// Created by Sergey Vanurin on 07.04.2021.
//

#ifndef DEVANCOMPILER_ALLOCEXPRESSION_H
#define DEVANCOMPILER_ALLOCEXPRESSION_H

#include "Expression.h"
#include "Symbols/Type.h"

class AllocExpression : public Expression {
public:
    AllocExpression(Type type, yy::location loc);

    std::variant<int, std::string> eval() const override;

    Type type;

    void Accept(Visitor *visitor) override;

private:
    Type EvalType(ScopeLayer *scope) override;
};


#endif //DEVANCOMPILER_ALLOCEXPRESSION_H
