//
// Created by Sergey Vanurin on 01.03.2021.
//
#ifndef DEVANCOMPILER_BASEELEMENT_H
#define DEVANCOMPILER_BASEELEMENT_H

#include "location.hh"
#include "Visitors/Visitor.h"
#include <variant>

class BaseElement {
public:
    yy::location loc;
    virtual void Accept(Visitor* visitor) = 0;
    explicit BaseElement(yy::location loc): loc(loc) {};
};


#endif //DEVANCOMPILER_BASEELEMENT_H