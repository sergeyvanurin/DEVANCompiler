//
// Created by deliza on 18.03.2021.
//

#include "Symbols/BaseSymbol.h"

bool BaseSymbol::operator==(const BaseSymbol &other) const {
    return name_ == other.GetName();
}

bool BaseSymbol::operator!=(const BaseSymbol &other) const {
    return name_ != other.GetName();
}

std::string BaseSymbol::GetName() const {
    return name_;
}

BaseSymbol::BaseSymbol(const std::string &name): name_(name) {
}
