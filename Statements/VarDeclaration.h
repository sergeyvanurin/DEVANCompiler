//
// Created by Sergey Vanurin on 01.03.2021.
//

#include "Statement.h"
#include <string>
#ifndef DEVANCOMPILER_VARDECLARATION_H
#define DEVANCOMPILER_VARDECLARATION_H


class VarDeclaration: public Statement {
public:
    VarDeclaration(const std::string& var_name, Scope* scope, yy::location loc);
    void Accept(Visitor* visitor) override;
    std::string var_name;
};


#endif //DEVANCOMPILER_VARDECLARATION_H
