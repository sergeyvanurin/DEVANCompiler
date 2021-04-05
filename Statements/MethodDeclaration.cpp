//
// Created by deliza on 04.03.2021.
//

#include "MethodDeclaration.h"

MethodDeclaration::MethodDeclaration(const std::string& method_name, FormalsList* formals, StatementList* statements, Scope* scope, yy::location loc):
        method_name(method_name), formals(formals), statements(statements), Statement(scope, loc) {}

void MethodDeclaration::Accept(Visitor *visitor) {
    visitor->Visit(this);
}