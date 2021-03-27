//
// Created by deliza on 27.03.2021.
//

#include "MethodInvocation.h"

void MethodInvocation::Accept(Visitor *visitor) {
    visitor->Visit(this);
}



MethodInvocation::MethodInvocation(Expression *expr, const std::string &name, ExpressionList *args, Scope *scope,
                                   yy::location loc): class_expr(expr), method_name(name), arguments(args), Statement(scope, loc), Expression(loc) {

}

int MethodInvocation::eval() const {
    return 0;
}
