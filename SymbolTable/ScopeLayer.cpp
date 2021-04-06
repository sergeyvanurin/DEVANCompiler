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

void ScopeLayer::AttachParent() {

}

ScopeLayer::ScopeLayer(): parent_(nullptr) {}

void ScopeLayer::DeclareVariable(const STVariable& var) {
    if (variables_.find(var.GetName()) != variables_.end()) {
        throw std::runtime_error("Variable has been declared");
    }

    variables_.emplace(var.GetName(), var);
    values_[var] = std::make_shared<Int>(0);
    offsets_[var] = symbols_.size();
    symbols_.push_back(var); // symbols_[offsets_[symbol]] === symbol
}

void ScopeLayer::Put(STVariable symbol, std::shared_ptr<Object> value) {
    ScopeLayer* current_layer = this;

    while (!current_layer->Has(symbol) && current_layer->parent_ != nullptr) {
        current_layer = current_layer->parent_;
    }
    if (current_layer->Has(symbol)) {
        current_layer->values_.find(symbol)->second = value;
    } else {
        throw std::runtime_error("Variable not declared");
    }
}

bool ScopeLayer::Has(BaseSymbol symbol) {
    return std::find(symbols_.begin(), symbols_.end(), symbol) != symbols_.end();
}


std::shared_ptr<Object> ScopeLayer::Get(STVariable symbol) {
    ScopeLayer* current_layer = this;

    while (!current_layer->Has(symbol) && current_layer->parent_ != nullptr) {
        current_layer = current_layer->parent_;
    }
    if (current_layer->Has(symbol)) {
        return current_layer->values_.find(symbol)->second;
    } else {
        throw std::runtime_error("Variable not declared");
    }
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
}

void ScopeLayer::DeclareMethod(const STMethod& method) {
    if (classes_.find(method.GetName()) != classes_.end()) {
        throw std::runtime_error("Method has been declared");
    }

    methods_.emplace(method.GetName(), method);
}
