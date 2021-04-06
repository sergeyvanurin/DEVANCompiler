//
// Created by Sergey Vanurin on 01.03.2021.
//

#ifndef DEVANCOMPILER_ADDEXPRESSION_H
#define DEVANCOMPILER_ADDEXPRESSION_H

#include <Expressions/BinaryExpression/ArithmeticExpressions/ArithmeticExpression.h>

class AddExpression: public ArithmeticExpression {
public:
    AddExpression(Expression* expr1, Expression* expr2, yy::location loc);
    std::variant<int, std::string> eval() const override;
    void Accept(Visitor* visitor) override;
};


#endif //DEVANCOMPILER_ADDEXPRESSION_H
