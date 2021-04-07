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
    explicit MethodInvocation(Expression* expr, const std::string& name, ExpressionList* args, yy::location loc);
    void Accept(Visitor* visitor) override;
    std::variant<int, std::string> eval() const override;
    Expression* class_expr;
    std::string method_name;
    ExpressionList* arguments;
private:
    Type EvalType(ScopeLayer *scope) override;

};


#endif //DEVANCOMPILER_METHODINVOCATION_H
