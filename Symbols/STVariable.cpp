//
// Created by deliza on 19.03.2021.
//

#include "STVariable.h"

#include <utility>

STVariable::STVariable(const std::string &name, std::string  type) : BaseSymbol(name), type(std::move(type)) {

}

STVariable::STVariable(VarDeclaration *var_decl) : BaseSymbol(var_decl->var_name) {

}

