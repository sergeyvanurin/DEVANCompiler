//
// Created by deliza on 11.03.2021.
//

#ifndef DEVANCOMPILER_INDEXEXPRESSION_H
#define DEVANCOMPILER_INDEXEXPRESSION_H


class IndexExpression : public Expression {
public:
    IndexExpression(Expression *inner, Expression *outer, yy::location loc);
    int eval() const override;
    void Accept(Visitor* visitor) override;
private:
    Expression* inner;
    Expression* outer;
};


#endif //DEVANCOMPILER_INDEXEXPRESSION_H