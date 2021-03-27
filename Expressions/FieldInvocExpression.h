//
// Created by deliza on 11.03.2021.
//


#ifndef DEVANCOMPILER_FIELDINVOCATIONEXPRESSION_H
#define DEVANCOMPILER_FIELDINVOCATIONEXPRESSION_H

#include "Expression.h"
#include <string>

class FieldInvocExpression : public Expression {
public:
    FieldInvocExpression(const std::string& field_name, yy::location loc);
    int eval() const override;
    void Accept(Visitor* visitor) override;

    std::string field_name;
};


#endif //DEVANCOMPILER_FIELDINVOCATIONEXPRESSION_H