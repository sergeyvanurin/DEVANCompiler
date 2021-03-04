//
// Created by deliza on 04.03.2021.
//

#include "Declarations.h"

Declarations::Declarations(Scope *Scope, yy::location loc) : Statement(Scope, loc) {}

void Declarations::Accept(Visitor *visitor) {
    visitor->Visit(this);
}
