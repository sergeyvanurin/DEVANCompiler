//
// Created by Sergey Vanurin on 01.03.2021.
//

#ifndef DEVANCOMPILER_MULEXPRESSION_H
#define DEVANCOMPILER_MULEXPRESSION_H

#include <variant>
#include <Expressions/BinaryExpression/ArithmeticExpressions/ArithmeticExpression.h>

class MulExpression: public ArithmeticExpression {
public:
    MulExpression(Expression* expr1, Expression* expr2, yy::location loc);
    std::variant<int, std::string> eval() const override;
    void Accept(Visitor* visitor) override;
};

#endif //DEVANCOMPILER_MULEXPRESSION_H
