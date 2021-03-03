//
// Created by Sergey Vanurin on 04.03.2021.
//

#include "Statements.h"

Statements::Statements(Scope *Scope) : Statement(Scope) {}

void Statements::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

