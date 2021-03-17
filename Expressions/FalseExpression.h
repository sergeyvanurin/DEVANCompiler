//
// Created by deliza on 11.03.2021.
//

#ifndef DEVANCOMPILER_FALSEEXPRESSION_H
#define DEVANCOMPILER_FALSEEXPRESSION_H


class FalseExpression : public Expression {
public:
    FalseExpression(yy::location loc);
    int eval() const override;
    void Accept(Visitor* visitor) override;
};


#endif //DEVANCOMPILER_FALSEEXPRESSION_H
