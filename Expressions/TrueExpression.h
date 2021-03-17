//
// Created by deliza on 11.03.2021.
//

#ifndef DEVANCOMPILER_TRUEEXPRESSION_H
#define DEVANCOMPILER_TRUEEXPRESSION_H


class TrueExpression : public Expression {
public:
    TrueExpression(yy::location loc);
    int eval() const override;
    void Accept(Visitor* visitor) override;
};


#endif //DEVANCOMPILER_TRUEEXPRESSION_H
