//
// Created by deliza on 03.03.2021.
//

#include <Visitors/Visitor.h>
#include "Statement.h"

#ifndef DEVANCOMPILER_CLASSDECLARATION_H
#define DEVANCOMPILER_CLASSDECLARATION_H


class ClassDeclaration : public Statement {
public:
    ClassDeclaration(const std::string& class_name, const std::string& base_class_name, Scope* scope, yy::location loc);
    void Accept(Visitor* visitor) override;
    void AddDeclarations(DeclarationList* declaration_list);

    std::string class_name;
    std::string base_class_name = "";
    DeclarationList* declaration_list;
};


#endif //DEVANCOMPILER_CLASSDECLARATION_H
