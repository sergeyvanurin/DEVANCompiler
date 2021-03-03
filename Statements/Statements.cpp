//
// Created by Sergey Vanurin on 04.03.2021.
//

#include "Statements.h"

Statements::Statements(Scope *Scope, yy::location loc) : Statement(Scope, loc) {}

void Statements::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

