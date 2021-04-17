//
// Created by deliza on 05.04.2021.
//

#include "ScopeLayer.h"

#include "Objects/Int.h"
#include <algorithm>
#include <Statements/MethodDeclaration.h>
#include "Symbols/STMethod.h"
#include "Statements/FormalsList.h"

const long long THIS_OFFSET = -1;

ScopeLayer::ScopeLayer(ScopeLayer *parent) : parent_(parent), offsets_(parent->GetCurrentOffset()) {
    if (parent_ != nullptr)
        parent_->AddChild(this);
}

ScopeLayer::ScopeLayer(ScopeLayer *parent, long long int new_offset) : parent_(parent), offsets_(new_offset) {
    if (parent_ != nullptr)
        parent->AddChild(this);
}

ScopeLayer::ScopeLayer() : parent_(nullptr) {}


ScopeLayer *ScopeLayer::GetChild(size_t index) {
    std::cout << "Children of scope: " << children_.size() << std::endl;
    return children_[index];
}

ScopeLayer *ScopeLayer::AddChild(ScopeLayer *child) {
    children_.push_back(child);
    return child;
}

ScopeLayer *ScopeLayer::GetParent() const {
    return parent_;
}

void ScopeLayer::DeclareClass(const STClass &class_decl) {
    if (classes_.count(class_decl.GetName())) {
        throw std::runtime_error("Class has been declared");
    }

    classes_.emplace(class_decl.GetName(), class_decl);
    EnterClass(&classes_.at(class_decl.GetName()));
}

bool ScopeLayer::HasVariableAtLayer(const std::string &var_name) const {
    return variables_.count(var_name);
}


void ScopeLayer::EnterClass(const STClass *cur_class) {
    current_class_ = cur_class;
}

const STClass *ScopeLayer::GetCurrentClass() const {
    if (current_class_ != nullptr) {
        return current_class_;
    }
    if (parent_ != nullptr) {
        return parent_->GetCurrentClass();
    }
    return nullptr;
}

STClass *ScopeLayer::GetClassByName(const std::string &class_name) {
    if (classes_.count(class_name))
        return &classes_.at(class_name);
    if (parent_ == nullptr)
        return nullptr;
    return parent_->GetClassByName(class_name);
}

STVariable *ScopeLayer::GetVariableByName(const std::string &var_name) {
    if (HasVariableAtLayer(var_name))
        return &variables_.at(var_name);
    if (parent_ == nullptr)
        return nullptr;
    return parent_->GetVariableByName(var_name);
}

long long ScopeLayer::GetCurrentOffset() const {
    return current_offset_;
}

void ScopeLayer::DeclareMethod(const std::string &method_name) {
    current_method_ = GetCurrentClass()->FindMethodByName(method_name);
    current_offset_ = THIS_OFFSET;
    current_offset_ -= current_method_->arguments.size();
}

void ScopeLayer::DeclareLocalVariable(const STVariable &var) {
    if (variables_.count(var.GetName())) {
        throw std::runtime_error("Variable '" + var.GetName() + "' has been declared in this scope");
    }
    if (current_offset_ == THIS_OFFSET)
        current_offset_ = 0;

    variables_.emplace(var.GetName(), var);
    std::cout << "Local variable '" << var.GetName() << "' in method '" << (current_method_ == nullptr ? "main" : current_method_->GetName()) << "' of type '"
              << var.type.ToString() << "' has offset: " << current_offset_ << std::endl;
    offsets_.emplace(var.GetName(), current_offset_);
    current_offset_ += 1;
}

const STMethod *ScopeLayer::GetCurrentMethod() const {
    if (current_method_ != nullptr) {
        return current_method_;
    }
    if (parent_ != nullptr) {
        return parent_->GetCurrentMethod();
    }
    return nullptr;
}

long long ScopeLayer::GetOffsetOfVariable(const std::string &var_name) const {
    if (offsets_.count(var_name)) {
        return offsets_.at(var_name);
    }
    if (parent_ != nullptr){
        return parent_->GetOffsetOfVariable(var_name);
    }
    throw std::runtime_error("Has no variable");
}
