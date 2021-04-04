//
// Created by deliza on 04.04.2021.
//

#ifndef DEVANCOMPILER_METHOD_H
#define DEVANCOMPILER_METHOD_H


#include <string>
#include <vector>
#include "Variable.h"
#include "Scope.h"

class Method {
public:
    Method(const std::string& name, const std::vector<Variable* >& arguments, Variable* return_var, Scope* scope);

protected:
    std::string name_;
    std::vector<Variable* > arguments_;
    Variable* return_var_;
    Scope* scope_;
};


#endif //DEVANCOMPILER_METHOD_H
