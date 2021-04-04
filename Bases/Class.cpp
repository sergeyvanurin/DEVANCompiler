//
// Created by deliza on 04.04.2021.
//

#include "Class.h"

Class::Class(const std::string &name, Class *base_class, const std::vector<Variable *> &fields,
             const std::vector<Method *> &methods): name_(name), base_class_(base_class), fields_(fields), methods_(methods) {

}

