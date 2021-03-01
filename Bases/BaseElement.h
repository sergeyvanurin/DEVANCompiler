//
// Created by Sergey Vanurin on 01.03.2021.
//
#include "Visitors/Visitor.h"
#ifndef DEVANCOMPILER_BASEELEMENT_H
#define DEVANCOMPILER_BASEELEMENT_H


class BaseElement {
public:
    virtual void Accept(Visitor* visitor) = 0;
};


#endif //DEVANCOMPILER_BASEELEMENT_H
