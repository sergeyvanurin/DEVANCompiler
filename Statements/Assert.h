//
// Created by Sergey Vanurin on 01.03.2021.
//

#include "Statement.h"
#include "Expressions/Expression.h"
#ifndef DEVANCOMPILER_ASSERT_H
#define DEVANCOMPILER_ASSERT_H


class Assert: public Statement {
public:
    Assert(Expression* expr);
    void Accept(Visitor* visitor) override;

private:
    Expression* expr;
};


#endif //DEVANCOMPILER_ASSERT_H
