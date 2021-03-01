//
// Created by Sergey Vanurin on 02.03.2021.
//

#include "Statement.h"
#include "Expressions/Expression.h"
#ifndef DEVANCOMPILER_IFELSE_H
#define DEVANCOMPILER_IFELSE_H


class IfElse: public Statement {
public:
    IfElse(Expression* expression, Statement* If, Statement* Else);
    void Accept(Visitor* visitor) override;

private:
    Expression* expr;
    Statement* If;
    Statement* Else;

};


#endif //DEVANCOMPILER_IFELSE_H
