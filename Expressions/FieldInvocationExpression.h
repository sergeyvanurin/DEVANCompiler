//
// Created by deliza on 11.03.2021.
//

#ifndef DEVANCOMPILER_FIELDINVOCATIONEXPRESSION_H
#define DEVANCOMPILER_FIELDINVOCATIONEXPRESSION_H


class FieldInvocationExpression : Expression {
public:
    FieldInvocationExpression(Expression* expr, yy::location loc);
    bool eval() const override;
    void Accept(Visitor* visitor) override;
private:
    Expression* expr;
};


#endif //DEVANCOMPILER_FIELDINVOCATIONEXPRESSION_H
