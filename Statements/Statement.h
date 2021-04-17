//
// Created by Sergey Vanurin on 01.03.2021.
//

#ifndef DEVANCOMPILER_KETWORD_H
#define DEVANCOMPILER_KETWORD_H

#include "Bases/BaseElement.h"

class Statement: public BaseElement
{
public:
    explicit Statement(yy::location loc);
};
#endif //DEVANCOMPILER_KETWORD_H

