//
// Created by deliza on 19.03.2021.
//

#include <Statements/MethodDeclaration.h>
#include "STMethod.h"
#include "Statements/FormalsList.h"

STMethod::STMethod(MethodDeclaration *method): BaseSymbol(method->method_name), return_type(method->return_type) {
    for (Formal* argument : method->formals->formals) {
        arguments.emplace_back(argument);
    }
}

const std::vector<STArgument> &STMethod::GetArguments() const {
    return arguments;
}
