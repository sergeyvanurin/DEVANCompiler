//
// Created by deliza on 03.03.2021.
//

#include "Statement.h"
#include "ClassDeclaration.h"
#include <queue>
#ifndef DEVANCOMPILER_PROGRAM_H
#define DEVANCOMPILER_PROGRAM_H


class Program : public Statement {
public:
    explicit Program(MainClass* main_class, std::queue<ClassDeclaration*>& class_declarations, Scope* scope);
    void Accept(Visitor* visitor) override;
    void add_class_declaration(ClassDeclaration* class_declaration);
private:
    MainClass* main_class;
    std::queue<ClassDeclaration*> class_declarations;
};


#endif //DEVANCOMPILER_PROGRAM_H
