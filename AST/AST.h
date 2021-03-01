//
// Created by Sergey Vanurin on 02.03.2021.
//

#include "Statements/MainClass.h"
#ifndef DEVANCOMPILER_AST_H
#define DEVANCOMPILER_AST_H


class AST {
public:
    explicit AST(MainClass* main_class);

private:
    MainClass* main_class;

};


#endif //DEVANCOMPILER_AST_H
