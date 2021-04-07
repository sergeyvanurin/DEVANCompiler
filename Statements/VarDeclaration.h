//
// Created by Sergey Vanurin on 01.03.2021.
//

#include "Statement.h"
#include <string>
#include <Symbols/Type.h>

#ifndef DEVANCOMPILER_VARDECLARATION_H
#define DEVANCOMPILER_VARDECLARATION_H


class VarDeclaration: public Statement {
public:
    VarDeclaration(Type* type, std::string  var_name, yy::location loc);
    void Accept(Visitor* visitor) override;
    std::string var_name;
    Type* type;
};


#endif //DEVANCOMPILER_VARDECLARATION_H
