//
// Created by deliza on 11.03.2021.
//

#include "Statement.h"
#include <vector>
#ifndef DEVANCOMPILER_CLASSDECLARATIONLIST_H
#define DEVANCOMPILER_CLASSDECLARATIONLIST_H


class ClassDeclarationList : public Statement {
public:
    ClassDeclarationList(yy::location loc);
    void Accept(Visitor* visitor) override;
    void AddClassDeclaration(ClassDeclaration* class_declaration);

    std::vector<ClassDeclaration*> class_declarations;
};


#endif //DEVANCOMPILER_CLASSDECLARATIONLIST_H
