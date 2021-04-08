//
// Created by arseny on 08.04.2021.
//

#ifndef DEVANCOMPILER_LOCALVARDECLARATION_H
#define DEVANCOMPILER_LOCALVARDECLARATION_H

#include "VarDeclaration.h"

class LocalVarDeclaration : public VarDeclaration{
public:
    LocalVarDeclaration(Type type, std::string  var_name, yy::location loc);
    void Accept(Visitor *visitor) override;
};


#endif //DEVANCOMPILER_LOCALVARDECLARATION_H
