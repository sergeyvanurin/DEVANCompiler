//
// Created by deliza on 03.03.2021.
//

#include <Visitors/Visitor.h>
#include <vector>
#include "Statement.h"

#ifndef DEVANCOMPILER_CLASSDECLARATION_H
#define DEVANCOMPILER_CLASSDECLARATION_H


class ClassDeclaration : public Statement {
public:
    ClassDeclaration(const std::string& class_name, const std::string& base_class_name, Scope* scope, yy::location loc);
    void Accept(Visitor* visitor) override;
    void AddVarDeclaration(VarDeclaration* var_decl);
    void AddMethodDeclaration(MethodDeclaration* method_decl);

    std::string class_name;
    std::string base_class_name = "";

    std::vector<VarDeclaration*> var_declarations;
    std::vector<MethodDeclaration*> method_declarations;
};


#endif //DEVANCOMPILER_CLASSDECLARATION_H
