//
// Created by deliza on 11.03.2021.
//

#include "ClassDeclarationList.h"

ClassDeclarationList::ClassDeclarationList(Scope *Scope, yy::location loc) : Statement(Scope, loc) {}

void ClassDeclarationList::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

void ClassDeclarationList::AddClassDeclaration(ClassDeclaration *class_declaration) {} {
    class_declarations.push_back(class_declaration);
};
