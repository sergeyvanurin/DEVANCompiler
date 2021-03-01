//
// Created by Sergey Vanurin on 01.03.2021.
//

#include "Statement.h"
#include <queue>
#ifndef DEVANCOMPILER_MAINCLASS_H
#define DEVANCOMPILER_MAINCLASS_H


class MainClass: public Statement {
public:
    void Accept(Visitor* visitor) override;
    void add_statement(Statement* statement);

private:
    std::queue<Statement*> statements;
};


#endif //DEVANCOMPILER_MAINCLASS_H
