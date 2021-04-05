//
// Created by deliza on 20.03.2021.
//

#include "STClass.h"

STClass::STClass(ClassDeclaration *class_) : base_class_name(class_->base_class_name), BaseSymbol(class_->class_name) {
    for (auto decl : class_->declaration_list->declarations) {
        if (decl.index() == 0) {
            VarDeclaration* var = std::get<VarDeclaration*>(decl);
            fields.emplace_back(var);
        } else {
            MethodDeclaration* method = std::get<MethodDeclaration*>(decl);
            methods.emplace_back(method);
        }
    }


}
