//
// Created by deliza on 19.03.2021.
//

#ifndef DEVANCOMPILER_FORMALSLIST_H
#define DEVANCOMPILER_FORMALSLIST_H


#include <vector>
#include "Statement.h"
#include "Formal.h"

class FormalsList : public Statement {
public:
    FormalsList(Scope* Scope, yy::location loc);
    void AddFormal(Formal* formal);
    void Accept(Visitor* visitor) override;

    std::vector<Formal*> formals;
};


#endif //DEVANCOMPILER_FORMALSLIST_H