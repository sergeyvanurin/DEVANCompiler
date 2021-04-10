//
// Created by deliza on 11.03.2021.
//

#ifndef DEVANCOMPILER_LESSEXPRESSION_H
#define DEVANCOMPILER_LESSEXPRESSION_H

#include <Expressions/BinaryExpression/ComparisonExpressions/ComparisonExpression.h>

class LessExpression : public ComparisonExpression {
public:
    LessExpression(Expression* expr1, Expression* expr2, yy::location loc);
    std::variant<int, std::string> eval() const override;
    void Accept(Visitor* visitor) override;
};


#endif //DEVANCOMPILER_LESSEXPRESSION_H
