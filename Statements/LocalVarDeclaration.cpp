//
// Created by arseny on 08.04.2021.
//

#include "LocalVarDeclaration.h"

#include <utility>

LocalVarDeclaration::LocalVarDeclaration(Type type, std::string var_name, yy::location loc) : VarDeclaration(
        std::move(type),
        std::move(var_name),
        loc) {

}

void LocalVarDeclaration::Accept(Visitor *visitor) {
    visitor->Visit(this);
}
