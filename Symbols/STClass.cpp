//
// Created by deliza on 20.03.2021.
//

#include "STClass.h"
#include "Statements/DeclarationList.h"
#include "Statements/MethodDeclaration.h"
#include "Statements/FieldDeclaration.h"

STClass::STClass(ClassDeclaration *class_) : type(class_->class_name), base_class_name(class_->base_class_name),
                                             BaseSymbol(class_->class_name) {
    for (auto decl : class_->declaration_list->declarations) {
        if (decl.index() == 0) {
            FieldDeclaration *var = std::get<FieldDeclaration *>(decl);
            fields.emplace_back(var);
            fields_.emplace(var->var_name, &fields.back());
        } else {
            MethodDeclaration *method = std::get<MethodDeclaration *>(decl);
            methods.emplace_back(method);
            methods_.emplace(method->method_name, &methods.back());
        }
    }


}

STVariable *STClass::FindFieldByName(const std::string &name) const {
    if (fields_.count(name)) {
        return fields_.at(name);
    }
    return nullptr;
}

STMethod *STClass::FindMethodByName(const std::string &name) const {
    if (methods_.count(name)) {
        return methods_.at(name);
    }
    return nullptr;
}

Type STClass::GetType() const {
    return type;
}
