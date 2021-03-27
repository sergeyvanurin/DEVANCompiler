//
// Created by deliza on 11.03.2021.
//

#include <variant>
#include "Expression.h"
#ifndef DEVANCOMPILER_LOGICALOREXPRESSION_H
#define DEVANCOMPILER_LOGICALOREXPRESSION_H


class LogicalOrExpression : public Expression {
public:
    LogicalOrExpression(Expression* expr1, Expression* expr2, yy::location loc);
    std::variant<int, std::string> eval() const override;
    void Accept(Visitor* visitor) override;
    Expression* expr1;
    Expression* expr2;
};


#endif //DEVANCOMPILER_LOGICALOREXPRESSION_H
