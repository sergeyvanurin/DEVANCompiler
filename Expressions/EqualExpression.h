//
// Created by deliza on 11.03.2021.
//

#ifndef DEVANCOMPILER_EQUALEXPRESSION_H
#define DEVANCOMPILER_EQUALEXPRESSION_H


class EqualExpression : public Expression {
public:
    EqualExpression(Expression* expr1, Expression* expr2, yy::location loc);
    int eval() const override;
    void Accept(Visitor* visitor) override;
private:
    Expression* expr1;
    Expression* expr2;
};


#endif //DEVANCOMPILER_EQUALEXPRESSION_H
