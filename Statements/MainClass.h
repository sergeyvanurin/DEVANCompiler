//
// Created by Sergey Vanurin on 01.03.2021.
//

#include "Statement.h"
#include "StatementList.h"
#include <queue>
#ifndef DEVANCOMPILER_MAINCLASS_H
#define DEVANCOMPILER_MAINCLASS_H


class MainClass: public Statement {
public:
    MainClass(StatementList* statements, yy::location loc);
    void Accept(Visitor* visitor) override;
    StatementList* statements;
};


#endif //DEVANCOMPILER_MAINCLASS_H
