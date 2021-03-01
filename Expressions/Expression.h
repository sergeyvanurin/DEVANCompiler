//
// Created by Sergey Vanurin on 01.03.2021.
//

#include "Bases/BaseElement.h"
#ifndef DEVANCOMPILER_EXPRESSION_H
#define DEVANCOMPILER_EXPRESSION_H


class Expression: public BaseElement {
public:
    virtual int eval() const = 0;
};


#endif //DEVANCOMPILER_EXPRESSION_H
