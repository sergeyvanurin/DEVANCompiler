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

    const STVariable *FindFieldByName(const std::string &name) const;

    const STMethod *FindMethodByName(const std::string& name) const;

    explicit STClass(ClassDeclaration *class_);

    Type GetType() const;

    std::unordered_map<std::string, STVariable> fields;

    std::string base_class_name = "";
private:
    Type type;
    std::unordered_map<std::string, STMethod> methods_;
};


#endif //DEVANCOMPILER_STCLASS_H
