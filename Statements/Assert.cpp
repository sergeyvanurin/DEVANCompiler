//
// Created by Sergey Vanurin on 01.03.2021.
//

#include "Assert.h"

Assert::Assert(Expression *expr, Scope* scope, yy::location loc): expr(expr), Statement(scope, loc) {}

void Assert::Accept(Visitor *visitor) {
    visitor->Visit(this);

}