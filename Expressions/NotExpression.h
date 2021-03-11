//
// Created by deliza on 11.03.2021.
//

#ifndef DEVANCOMPILER_NOTEXPRESSION_H
#define DEVANCOMPILER_NOTEXPRESSION_H


class NotExpression : Expression {
public:
    NotExpression(Expression* expr, yy::location loc);
    bool eval() const override;
    void Accept(Visitor* visitor) override;
private:
    Expression* expr;
};


#endif //DEVANCOMPILER_NOTEXPRESSION_H
