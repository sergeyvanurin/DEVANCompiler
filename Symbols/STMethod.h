//
// Created by deliza on 19.03.2021.
//

#ifndef DEVANCOMPILER_STMETHOD_H
#define DEVANCOMPILER_STMETHOD_H

#include "BaseSymbol.h"
#include "STArgument.h"
#include <string>
#include <vector>
#include "Type.h"

class STMethod : public BaseSymbol {
public:
    explicit STMethod(MethodDeclaration* method);
    Type return_type;

    std::vector<STArgument> arguments;
};


#endif //DEVANCOMPILER_STMETHOD_H
