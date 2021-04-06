//
// Created by deliza on 19.03.2021.
//

#ifndef DEVANCOMPILER_STARGUMENT_H
#define DEVANCOMPILER_STARGUMENT_H


#include <Statements/Formal.h>
#include "BaseSymbol.h"

class STArgument : public BaseSymbol {
public:
    explicit STArgument(Formal* argument);
    Type *type;
};


#endif //DEVANCOMPILER_STARGUMENT_H
