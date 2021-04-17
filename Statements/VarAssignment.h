//
// Created by Sergey Vanurin on 02.03.2021.
//

#include "Statement.h"
#include "Expressions/Expression.h"
#include <string>
#ifndef DEVANCOMPILER_VARASSIGNMENT_H
#define DEVANCOMPILER_VARASSIGNMENT_H


class VarAssignment: public Statement {
public:
    VarAssignment(Expression* var_name, Expression *new_value, yy::location loc);
    void Accept(Visitor* visitor) override;
    Expression* var_name;
    Expression* new_value;
};


#endif //DEVANCOMPILER_VARASSIGNMENT_H
