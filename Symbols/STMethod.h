//
// Created by deliza on 19.03.2021.
//

#ifndef DEVANCOMPILER_STMETHOD_H
#define DEVANCOMPILER_STMETHOD_H

#include "Visitors/Elements.h"
#include "BaseSymbol.h"
#include "STArgument.h"
#include <string>

class STMethod : public BaseSymbol {
public:
    explicit STMethod(MethodDeclaration* method);
    std::vector<STArgument> arguments;
    std::string return_type = "void";
};


#endif //DEVANCOMPILER_STMETHOD_H
