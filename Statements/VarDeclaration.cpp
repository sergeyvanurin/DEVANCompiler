//
// Created by Sergey Vanurin on 01.03.2021.
//

#include "VarDeclaration.h"

VarDeclaration::VarDeclaration(Type* type, const std::string& var_name, Scope* scope, yy::location loc): var_name(var_name), Statement(scope, loc) {}

void VarDeclaration::Accept(Visitor *visitor) {
    visitor->Visit(this);
}
