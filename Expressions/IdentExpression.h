//
// Created by Sergey Vanurin on 02.03.2021.
//

#include "Expressions/Expression.h"
#include <string>
#ifndef DEVANCOMPILER_IDENTEXPRESSION_H
#define DEVANCOMPILER_IDENTEXPRESSION_H


class IdentExpression: public Expression {
public:
    explicit IdentExpression(std::string& var_name, yy::location loc);
    void Accept(Visitor* visitor) override;
    int eval() const override;
    std::string var_name;
};


#endif //DEVANCOMPILER_IDENTEXPRESSION_H
