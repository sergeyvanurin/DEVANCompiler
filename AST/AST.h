//
// Created by Sergey Vanurin on 02.03.2021.
//

#include "Statements/MainClass.h"
#ifndef DEVANCOMPILER_AST_H
#define DEVANCOMPILER_AST_H


class AST {
public:
    explicit AST(Program* program);

private:
    Program* program;

};


#endif //DEVANCOMPILER_AST_H
