//
// Created by Sergey Vanurin on 02.03.2021.
//
#pragma once
#include "Statement.h"
#include "Expressions/Expression.h"
#ifndef DEVANCOMPILER_IFELSE_H
#define DEVANCOMPILER_IFELSE_H


class IfElse: public Statement {
public:
    IfElse(Expression *expression, Statement *If, Statement *Else, yy::location loc);
    void Accept(Visitor* visitor) override;

    Expression* expr;
    Statement* If;
    Statement* Else;
};


#endif //DEVANCOMPILER_IFELSE_H
