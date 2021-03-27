//
// Created by Sergey Vanurin on 01.03.2021.
//
#include "location.hh"
#include "Visitors/Visitor.h"
#include <variant>
#ifndef DEVANCOMPILER_BASEELEMENT_H
#define DEVANCOMPILER_BASEELEMENT_H


class BaseElement {
public:
    yy::location loc;
    virtual void Accept(Visitor* visitor) = 0;
    explicit BaseElement(yy::location loc): loc(loc) {};
};


#endif //DEVANCOMPILER_BASEELEMENT_H
