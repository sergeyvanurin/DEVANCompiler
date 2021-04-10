//
// Created by deliza on 11.03.2021.
//

#ifndef DEVANCOMPILER_GREATEREXPRESSION_H
#define DEVANCOMPILER_GREATEREXPRESSION_H

#include <Expressions/BinaryExpression/ComparisonExpressions/ComparisonExpression.h>

class GreaterExpression : public ComparisonExpression {
public:
    GreaterExpression(Expression* expr1, Expression* expr2, yy::location loc);
    std::variant<int, std::string> eval() const override;
    void Accept(Visitor* visitor) override;
};


#endif //DEVANCOMPILER_GREATEREXPRESSION_H
