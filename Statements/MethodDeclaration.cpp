//
// Created by deliza on 04.03.2021.
//

#include "MethodDeclaration.h"
#include "FormalsList.h"

#include <utility>

MethodDeclaration::MethodDeclaration(std::string method_name, Type* return_type, FormalsList *formals,
                                     StatementList *statements, Scope *scope, yy::location loc) :
        method_name(std::move(method_name)), formals(formals), statements(statements), Statement(scope, loc),
        return_type(return_type) {
    for (auto &formal: formals->formals){
        if (*formal->type == Type("void")){
            throw std::runtime_error("Argument cannot be void");
        }
    }
}

void MethodDeclaration::Accept(Visitor *visitor) {
    visitor->Visit(this);
}