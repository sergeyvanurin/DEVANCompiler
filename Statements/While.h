//
// Created by Sergey Vanurin on 02.03.2021.
//

#include "Statement.h"
#include "Expressions/Expression.h"
#ifndef DEVANCOMPILER_WHILE_H
#define DEVANCOMPILER_WHILE_H


class While: public Statement {
public:
    While(Expression *expr, Statement *statement, Scope *scope, yy::location loc);
    void Accept(Visitor* visitor) override;

private:
    Expression* expr;
    Statement* statement;
};


#endif //DEVANCOMPILER_WHILE_H
