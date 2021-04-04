//
// Created by deliza on 04.04.2021.
//

#ifndef DEVANCOMPILER_SCOPE_H
#define DEVANCOMPILER_SCOPE_H

#include <vector>
#include "Variable.h"

class Scope {
public:
    Scope() = default;
    void AddVariable(Variable* var);
protected:
    std::vector<Variable* > variables_;
};


#endif //DEVANCOMPILER_SCOPE_H
