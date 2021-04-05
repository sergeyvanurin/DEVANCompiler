//
// Created by Sergey Vanurin on 02.03.2021.
//

#include <variant>
#include "Expression.h"
#ifndef DEVANCOMPILER_NUMEXPRESSION_H
#define DEVANCOMPILER_NUMEXPRESSION_H


class NumExpression: public Expression {
public:
    explicit NumExpression(int value, yy::location loc);
    void Accept(Visitor* visitor) override;
    std::variant<int, std::string> eval() const override;

private:
    int value;
};


#endif //DEVANCOMPILER_NUMEXPRESSION_H
