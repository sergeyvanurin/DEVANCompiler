//
// Created by deliza on 11.03.2021.
//

#ifndef DEVANCOMPILER_LESSEXPRESSION_H
#define DEVANCOMPILER_LESSEXPRESSION_H


class LessExpression : Expression {
public:
    LessExpression(Expression* expr1, Expression* expr2, yy::location loc);
    int eval() const override;
    void Accept(Visitor* visitor) override;
private:
    Expression* expr1;
    Expression* expr2;
};


#endif //DEVANCOMPILER_LESSEXPRESSION_H
