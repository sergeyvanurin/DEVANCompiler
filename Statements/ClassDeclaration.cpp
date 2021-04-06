//
// Created by deliza on 03.03.2021.
//

#include "ClassDeclaration.h"


void ClassDeclaration::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

ClassDeclaration::ClassDeclaration(const std::string &class_name, const std::string &base_class_name, DeclarationList* decl_list, Scope *scope,
                                   yy::location loc) : class_name(class_name), base_class_name(base_class_name), declaration_list(decl_list), Statement(scope, loc){

}


