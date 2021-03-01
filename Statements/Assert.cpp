//
// Created by Sergey Vanurin on 01.03.2021.
//

#include "Assert.h"

Assert::Assert(Expression *expr): expr(expr) {}

void Assert::Accept(Visitor *visitor) {
    visitor->Visit(this);

}
