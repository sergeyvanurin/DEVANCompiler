//
// Created by deliza on 20.03.2021.
//

#include "STClass.h"

STClass::STClass(ClassDeclaration *class_) : base_class_name(class_->base_class_name), BaseSymbol(class_->class_name) {
    for (auto var_decl : class_->var_declarations) {
        fields.emplace_back(var_decl);
    }
    for (auto method_decl : class_->method_declarations) {
        methods.emplace_back(method_decl);
    }

}
