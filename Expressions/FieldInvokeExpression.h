//
// Created by deliza on 11.03.2021.
//


#ifndef DEVANCOMPILER_FIELDINVOCATIONEXPRESSION_H
#define DEVANCOMPILER_FIELDINVOCATIONEXPRESSION_H

#include "Expression.h"
#include <string>

class FieldInvokeExpression : public Expression {
public:
    FieldInvokeExpression(const std::string& field_name, yy::location loc);
    std::variant<int, std::string> eval() const override;
    void Accept(Visitor* visitor) override;

    std::string field_name;

private:
    Type EvalType(ScopeLayer *scope) override;
};


#endif //DEVANCOMPILER_FIELDINVOCATIONEXPRESSION_H
