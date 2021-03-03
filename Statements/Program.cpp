//
// Created by deliza on 03.03.2021.
//

#include "Program.h"


void Program::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

void Program::add_class_declaration(ClassDeclaration *class_declaration)  {
    class_declarations.push(class_declaration);
}

Program::Program(MainClass* main_class, std::queue<ClassDeclaration*>& class_declarations, Scope* scope): main_class(main_class), class_declarations(class_declarations), Statement(scope) {}
