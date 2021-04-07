//
// Created by deliza on 05.04.2021.
//

#include "ScopeLayer.h"

#include "Objects/Int.h"
#include <algorithm>


ScopeLayer::ScopeLayer(ScopeLayer* parent): parent_(parent) {
    std::cout << "Constructor called" << std::endl;
    std::cout << "End contstructor called" << std::endl;

    parent_->AddChild(this);
}

ScopeLayer::ScopeLayer(): parent_(nullptr) {}

void ScopeLayer::DeclareVariable(const STVariable& var) {
    if (variables_.find(var.GetName()) != variables_.end()) {
        throw std::runtime_error("Variable '" + var.GetName() + "' has been declared in this scope");
    }

    variables_.emplace(var.GetName(), var);
    values_[var] = std::make_shared<Int>(0);
    //offsets_[var] = symbols_.size();
    //symbols_.push_back(var); // symbols_[offsets_[symbol]] === symbol
}


ScopeLayer* ScopeLayer::GetChild(size_t index) {
    std::cout << "Children of scope: " << children_.size() << std::endl;
    return children_[index];
}

ScopeLayer* ScopeLayer::AddChild(ScopeLayer* child) {
    children_.push_back(child);
    return child;
}

ScopeLayer* ScopeLayer::GetParent() const {
    return parent_;
}

void ScopeLayer::DeclareClass(const STClass& class_decl) {
    if (classes_.find(class_decl.GetName()) != classes_.end()) {
        throw std::runtime_error("Class has been declared");
    }

    classes_.emplace(class_decl.GetName(), class_decl);
    EnterClass(&classes_.at(class_decl.GetName()));
}

bool ScopeLayer::HasVariableAtLayer(const std::string& var_name) const {
    return variables_.count(var_name);
}


void ScopeLayer::EnterClass(const STClass *cur_class) {
    current_class_ = cur_class;
}

const STClass *ScopeLayer::GetCurrentClass() const {
    if (current_class_ != nullptr){
        return current_class_;
    }
    if (parent_ != nullptr){
        return parent_->GetCurrentClass();
    }
    return nullptr;
}

STClass *ScopeLayer::GetClassByName(const std::string& class_name) {
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

void ScopeLayer::EnterMethod(const STMethod *cur_method) {
    current_method_ = cur_method;
}

const STMethod *ScopeLayer::GetCurrentMethod() const {
    if (current_method_ != nullptr){
        return current_method_;
    }
    if (parent_ != nullptr){
        return parent_->GetCurrentMethod();
    }
    return nullptr;
}
