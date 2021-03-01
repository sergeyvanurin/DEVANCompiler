//
// Created by Sergey Vanurin on 01.03.2021.
//

#include "VarDeclaration.h"

VarDeclaration::VarDeclaration(std::string& var_name): var_name(var_name) {

}

void VarDeclaration::Accept(Visitor *visitor) {
    visitor->Visit(this);

}
