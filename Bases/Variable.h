//
// Created by deliza on 04.04.2021.
//

#ifndef DEVANCOMPILER_VARIABLE_H
#define DEVANCOMPILER_VARIABLE_H


#include "Class.h"
#include <string>


class Variable {
public:
    Variable(const std::string& name, Class* class_);

protected:
    // type = int so far
    std::string name_;
    Class* class_;
};


#endif //DEVANCOMPILER_VARIABLE_H
