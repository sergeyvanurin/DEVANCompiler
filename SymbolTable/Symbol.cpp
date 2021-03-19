//
// Created by deliza on 18.03.2021.
//

#include "Symbol.h"

bool Symbol::operator==(const Symbol &other) const {
    return name_ == other.GetName();
}

bool Symbol::operator!=(const Symbol &other) const {
    return name_ != other.GetName();
}

std::string Symbol::GetName() const {
    return name_;
}

Symbol::Symbol(const std::string &name): name_(name) {
}

Symbol::Symbol(const Symbol &other): name_(other.name_) {

}
