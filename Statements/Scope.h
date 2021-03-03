//
// Created by Sergey Vanurin on 03.03.2021.
//
#pragma once
#include <map>
#include <string>
#include "Visitors/Visitor.h"
#include "location.hh"
#ifndef DEVANCOMPILER_CREATESCOPE_H
#define DEVANCOMPILER_CREATESCOPE_H


class Scope{
private:
    std::map<std::string, int> variables;
    int scope_num;
    Scope* upper_scope;
public:
    yy::location loc;
    explicit Scope(int scope_num, Scope* upper_scope, yy::location loc);
    void add_variable(std::string& var_name, int var_value);
    void modify_variable(std::string& var_name, int new_value);
    Scope* find_scope(std::string& var_name);
    void Accept(Visitor* visitor);
};


#endif //DEVANCOMPILER_CREATESCOPE_H
