//
// Created by Sergey Vanurin on 01.03.2021.
//

#include "Statement.h"
#include <string>
#ifndef DEVANCOMPILER_VARDECLARATION_H
#define DEVANCOMPILER_VARDECLARATION_H


class VarDeclaration: public Statement {
public:
    VarDeclaration(std::string& var_name);
    void Accept(Visitor* visitor) override;

private:
    std::string var_name;
};


#endif //DEVANCOMPILER_VARDECLARATION_H
