//
// Created by deliza on 20.03.2021.
//

#include "STClass.h"
#include "Statements/DeclarationList.h"

STClass::STClass(ClassDeclaration *class_) : base_class_name(class_->base_class_name), BaseSymbol(class_->class_name) {
    for (auto decl : class_->declaration_list->declarations) {
        if (decl.index() == 0) {
            VarDeclaration *var = std::get<VarDeclaration *>(decl);
            fields.emplace_back(var);
        } else {
            MethodDeclaration *method = std::get<MethodDeclaration *>(decl);
            methods.emplace_back(method);
        }
    }


}

STVariable *STClass::FindFieldByName(const std::string &name) {
    if (fields_.count(name)) {
        return fields_.at(name);
    }
    for (auto &field: fields) {
        if (field.GetName() == name) {
            fields_.at(name) = &field;
            return fields_.at(name);
        }
    }
    return nullptr;
}

STMethod *STClass::FindMethodByName(std::string name) {
    if (methods_.count(name)) {
        return methods_.at(name);
    }
    for (auto &method: methods) {
        if (method.GetName() == name) {
            methods_.at(name) = &method;
            return methods_.at(name);
        }
    }
    return nullptr;
}
