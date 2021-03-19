//
// Created by deliza on 04.03.2021.
//

#include <vector>
#include "Statement.h"

#ifndef DEVANCOMPILER_METHODDECLARATION_H
#define DEVANCOMPILER_METHODDECLARATION_H


class MethodDeclaration : public Statement {
public:
    MethodDeclaration(const std::string& method_name, FormalsList* formals, StatementList* statements, Scope* scope, yy::location loc);
    void Accept(Visitor* visitor) override;

    std::string method_name;
    FormalsList* formals;
    StatementList* statements;
};


#endif //DEVANCOMPILER_METHODDECLARATION_H
