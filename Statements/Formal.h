//
// Created by deliza on 19.03.2021.
//

#ifndef DEVANCOMPILER_FORMAL_H
#define DEVANCOMPILER_FORMAL_H


#include <Symbols/Type.h>
#include "Statement.h"

class Formal : public Statement {
public:
    explicit Formal(Type* type, std::string name, yy::location loc);
    void Accept(Visitor* visitor) override;
    std::string name;
    Type* type;
};


#endif //DEVANCOMPILER_FORMAL_H
