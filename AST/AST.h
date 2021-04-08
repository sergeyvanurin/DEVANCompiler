//
// Created by Sergey Vanurin on 02.03.2021.
//

#ifndef DEVANCOMPILER_AST_H
#define DEVANCOMPILER_AST_H

#include "Statements/MainClass.h"
#include "Statements/Program.h"

class AST {
public:
    explicit AST(Program* program);

private:
    Program* program;

};


#endif //DEVANCOMPILER_AST_H
