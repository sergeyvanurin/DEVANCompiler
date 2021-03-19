//
// Created by deliza on 20.03.2021.
//

#ifndef DEVANCOMPILER_STCLASS_H
#define DEVANCOMPILER_STCLASS_H


#include <Statements/ClassDeclaration.h>
#include <vector>
#include "BaseSymbol.h"
#include "STMethod.h"
#include "STVariable.h"

class STClass : public BaseSymbol {
public:
    explicit STClass(ClassDeclaration* class_);
    std::string base_class_name = "";
    std::vector<STMethod> methods;
    std::vector<STVariable> fields;
};


#endif //DEVANCOMPILER_STCLASS_H
