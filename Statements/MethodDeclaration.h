//
// Created by deliza on 04.03.2021.
//

#include <vector>
#include "Statement.h"

#ifndef DEVANCOMPILER_METHODDECLARATION_H
#define DEVANCOMPILER_METHODDECLARATION_H


class MethodDeclaration : public Statement {
public:
    MethodDeclaration(const std::string& method_name, std::vector<int>& formals, StatementList* statements, Scope* scope, yy::location loc);
    void Accept(Visitor* visitor) override;
private:
    std::string method_name;
    std::vector<int> formals;
    StatementList* statements;
};


#endif //DEVANCOMPILER_METHODDECLARATION_H
