//
// Created by deliza on 11.03.2021.
//

#ifndef DEVANCOMPILER_LOGICALOREXPRESSION_H
#define DEVANCOMPILER_LOGICALOREXPRESSION_H

#include <variant>
#include <Expressions/BinaryExpression/LogicalExpression/LogicalExpression.h>

class LogicalOrExpression : public LogicalExpression {
public:
    LogicalOrExpression(Expression* expr1, Expression* expr2, yy::location loc);
    std::variant<int, std::string> eval() const override;
    void Accept(Visitor* visitor) override;
};


#endif //DEVANCOMPILER_LOGICALOREXPRESSION_H
