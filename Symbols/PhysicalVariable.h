//
// Created by arseny on 08.04.2021.
//

#ifndef DEVANCOMPILER_PHYSICALVARIABLE_H
#define DEVANCOMPILER_PHYSICALVARIABLE_H

#include <SymbolTable/ScopeLayer.h>
#include "Type.h"

class PhysicalVariable {
public:
    PhysicalVariable(Type type, ScopeLayer* scope);

private:
    char* raw_data;
};


#endif //DEVANCOMPILER_PHYSICALVARIABLE_H
