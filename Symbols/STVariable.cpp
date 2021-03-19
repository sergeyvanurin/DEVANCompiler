//
// Created by deliza on 19.03.2021.
//

#include "STVariable.h"

STVariable::STVariable(const std::string &name) : BaseSymbol(name) {

}

STVariable::STVariable(VarDeclaration *var_decl) : BaseSymbol(var_decl->var_name) {

}
