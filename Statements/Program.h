//
// Created by deliza on 03.03.2021.
//

#include "Statement.h"
#include "ClassDeclaration.h"
#include <queue>
#ifndef DEVANCOMPILER_PROGRAM_H
#define DEVANCOMPILER_PROGRAM_H


class Program : public Statement {
public:
    explicit Program(MainClass* main_class, yy::location loc);
    void Accept(Visitor* visitor) override;
    MainClass* main_class;

};


#endif //DEVANCOMPILER_PROGRAM_H
