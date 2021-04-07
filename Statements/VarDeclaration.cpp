//
// Created by Sergey Vanurin on 01.03.2021.
//

#include "VarDeclaration.h"

#include <utility>

VarDeclaration::VarDeclaration(Type* type, std::string  var_name, yy::location loc): type(type), var_name(std::move(var_name)), Statement(loc) {}

void VarDeclaration::Accept(Visitor *visitor) {
    visitor->Visit(this);
}
