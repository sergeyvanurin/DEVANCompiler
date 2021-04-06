//
// Created by arseny on 06.04.2021.
//

#include "Type.h"

#include <utility>

Type::Type(std::string type_name, bool is_array) : type_name(std::move(type_name)), is_array(is_array) {

}

bool Type::operator==(const Type& other) const {
    return other.is_array == is_array && other.type_name == type_name;
}

bool Type::operator!=(const Type &other) const {
    return !operator==(other);
}

std::string Type::ToString() const {
    return type_name + (is_array ? "[]" : "");
}
