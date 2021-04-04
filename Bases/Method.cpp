//
// Created by deliza on 04.04.2021.
//

#include "Method.h"

Method::Method(const std::string &name, const std::vector<Variable *> &arguments, Variable *return_var, Scope *scope):
                        name_(name), arguments_(arguments), return_var_(return_var), scope_(scope) {

}
