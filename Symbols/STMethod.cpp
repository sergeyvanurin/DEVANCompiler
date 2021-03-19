//
// Created by deliza on 19.03.2021.
//

#include <Statements/MethodDeclaration.h>
#include "STMethod.h"

STMethod::STMethod(MethodDeclaration *method): BaseSymbol(method->method_name) {
    for (auto* argument : method->formals->formals) {
        arguments.emplace_back(argument);
    }
}
