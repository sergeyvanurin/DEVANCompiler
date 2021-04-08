//
// Created by deliza on 04.03.2021.
//


#ifndef DEVANCOMPILER_METHODDECLARATION_H
#define DEVANCOMPILER_METHODDECLARATION_H

#include <vector>
#include <Symbols/Type.h>
#include "Statement.h"
#include "FormalsList.h"
#include "StatementList.h"

class MethodDeclaration : public Statement {
public:
    MethodDeclaration(std::string method_name, Type return_type, FormalsList *formals, StatementList *statements,
                      yy::location loc);

    void Accept(Visitor *visitor) override;

    std::string method_name;
    Type return_type;
    FormalsList *formals;
    StatementList *statements;
};


#endif //DEVANCOMPILER_METHODDECLARATION_H