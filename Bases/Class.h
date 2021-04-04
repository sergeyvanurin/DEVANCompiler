//
// Created by deliza on 04.04.2021.
//

#ifndef DEVANCOMPILER_CLASS_H
#define DEVANCOMPILER_CLASS_H


#include <string>
#include <vector>
#include "Variable.h"
#include "Method.h"

class Class {
public:
    Class(const std::string& name, Class* base_class,
          const std::vector<Variable* >& fields, const std::vector<Method* >& methods);
protected:
    std::string name_;
    Class* base_class_;
    std::vector<Variable*> fields_;
    std::vector<Method*> methods_;
};


#endif //DEVANCOMPILER_CLASS_H
