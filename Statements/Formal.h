//
// Created by deliza on 19.03.2021.
//

#ifndef DEVANCOMPILER_FORMAL_H
#define DEVANCOMPILER_FORMAL_H


#include "Statement.h"

class Formal : public Statement {
public:
    explicit Formal(const std::string& name, Scope* scope, yy::location loc);
    void Accept(Visitor* visitor) override;
    std::string name;
};


#endif //DEVANCOMPILER_FORMAL_H