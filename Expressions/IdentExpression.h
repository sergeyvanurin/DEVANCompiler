//
// Created by Sergey Vanurin on 02.03.2021.
//

#ifndef DEVANCOMPILER_IDENTEXPRESSION_H
#define DEVANCOMPILER_IDENTEXPRESSION_H

#include "Expressions/Expression.h"
#include <string>

class IdentExpression: public Expression {
public:
    explicit IdentExpression(std::string& var_name, yy::location loc);
    void Accept(Visitor* visitor) override;
    std::variant<int, std::string> eval() const override;
    std::string var_name;
private:
    std::string EvalType(ScopeLayer *scope) override;
};


#endif //DEVANCOMPILER_IDENTEXPRESSION_H
