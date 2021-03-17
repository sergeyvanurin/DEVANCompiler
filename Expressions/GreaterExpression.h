//
// Created by deliza on 11.03.2021.
//

#ifndef DEVANCOMPILER_GREATEREXPRESSION_H
#define DEVANCOMPILER_GREATEREXPRESSION_H


class GreaterExpression : public Expression {
public:
    GreaterExpression(Expression* expr1, Expression* expr2, yy::location loc);
    int eval() const override;
    void Accept(Visitor* visitor) override;
private:
    Expression* expr1;
    Expression* expr2;
};


#endif //DEVANCOMPILER_GREATEREXPRESSION_H
