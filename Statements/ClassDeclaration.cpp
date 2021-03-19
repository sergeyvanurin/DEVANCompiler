//
// Created by deliza on 03.03.2021.
//

#include "ClassDeclaration.h"


void ClassDeclaration::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

ClassDeclaration::ClassDeclaration(const std::string &class_name, const std::string &base_class_name, Scope *scope,
                                   yy::location loc) : class_name(class_name), base_class_name(base_class_name), Statement(scope, loc){

}

void ClassDeclaration::AddVarDeclaration(VarDeclaration *var_decl) {
    var_declarations.push_back(var_decl);
}

void ClassDeclaration::AddMethodDeclaration(MethodDeclaration *method_decl) {
    method_declarations.push_back(method_decl);
}

