//
// Created by deliza on 19.03.2021.
//

#ifndef DEVANCOMPILER_STVARIABLE_H
#define DEVANCOMPILER_STVARIABLE_H


#include <Statements/VarDeclaration.h>
#include "BaseSymbol.h"

class STVariable : public BaseSymbol {
public:
    explicit STVariable(const std::string& name);
    explicit STVariable(VarDeclaration* var_decl);
    std::string type = "int";
};


#endif //DEVANCOMPILER_STVARIABLE_H
