//
// Created by deliza on 03.03.2021.
//

#ifndef DEVANCOMPILER_MODEXPRESSION_H
#define DEVANCOMPILER_MODEXPRESSION_H

#include <Expressions/BinaryExpression/ArithmeticExpressions/ArithmeticExpression.h>

class ModExpression: public ArithmeticExpression {
public:
    ModExpression(Expression* expr1, Expression* expr2, yy::location loc);
    std::variant<int, std::string> eval() const override;
    void Accept(Visitor* visitor) override;
};


#endif //DEVANCOMPILER_MODEXPRESSION_H
