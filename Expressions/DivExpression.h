//
// Created by Sergey Vanurin on 01.03.2021.
//

#include "Expression.h"
#ifndef DEVANCOMPILER_DIVCLASS_H
#define DEVANCOMPILER_DIVCLASS_H

class DivExpression: public Expression {
public:
    DivExpression(Expression* expr1, Expression* expr2, yy::location loc);
    std::variant<int, std::string> eval() const override;
    void Accept(Visitor* visitor) override;

    Expression* expr1;
    Expression* expr2;
};



#endif //DEVANCOMPILER_DIVCLASS_H
