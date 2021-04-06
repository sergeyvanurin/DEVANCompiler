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

    STVariable *FindFieldByName(const std::string &name);

    STMethod *FindMethodByName(std::string name);

    explicit STClass(ClassDeclaration *class_);

    std::string base_class_name = "";
    std::vector<STMethod> methods;
    std::vector<STVariable> fields;
private:
    std::unordered_map<std::string, STMethod *> methods_;
    std::unordered_map<std::string, STVariable *> fields_;
};


#endif //DEVANCOMPILER_STCLASS_H
