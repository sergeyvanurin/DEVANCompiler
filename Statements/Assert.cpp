//
// Created by Sergey Vanurin on 01.03.2021.
//

#include "Assert.h"

Assert::Assert(Expression *expr, Scope* scope): expr(expr), Statement(scope) {}

void Assert::Accept(Visitor *visitor) {
    visitor->Visit(this);

}
