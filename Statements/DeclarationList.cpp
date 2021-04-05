//
// Created by deliza on 04.03.2021.
//

#include "DeclarationList.h"

DeclarationList::DeclarationList(Scope *Scope, yy::location loc) : Statement(Scope, loc) {}

void DeclarationList::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

void DeclarationList::AddDeclaration(DeclarationList::var_method_decl_t decl) {
    declarations.push_back(decl);
}

