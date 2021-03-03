//
// Created by Sergey Vanurin on 01.03.2021.
//

#include "Bases/BaseElement.h"
#include "Scope.h"
#ifndef DEVANCOMPILER_KETWORD_H
#define DEVANCOMPILER_KETWORD_H

class Statement: public BaseElement
{
public:
    explicit Statement(Scope* scope);
    Scope* scope;
};

Statement::Statement(Scope *scope): scope(scope) {}
#endif //DEVANCOMPILER_KETWORD_H

