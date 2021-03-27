//
// Created by deliza on 27.03.2021.
//

#ifndef DEVANCOMPILER_METHODINVOCATION_H
#define DEVANCOMPILER_METHODINVOCATION_H

#include <string>
#include "Expressions/Expression.h"
#include "Statement.h"

class MethodInvocation : public Statement, public Expression {
public:
    explicit MethodInvocation(Expression* expr, const std::string& name, ExpressionList* args, Scope* scope, yy::location loc);
    void Accept(Visitor* visitor) override;
    int eval() const override;
    Expression* class_expr;
    std::string method_name;
    ExpressionList* arguments;

};


#endif //DEVANCOMPILER_METHODINVOCATION_H
