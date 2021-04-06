//
// Created by Sergey Vanurin on 01.03.2021.
//
#pragma once
#include "Bases/BaseElement.h"
#include "Scope.h"
#ifndef DEVANCOMPILER_KETWORD_H
#define DEVANCOMPILER_KETWORD_H

class Statement: public BaseElement
{
public:
    explicit Statement(Scope* scope, yy::location loc);

    Scope* scope;
};
#endif //DEVANCOMPILER_KETWORD_H

