//
// Created by deliza on 11.03.2021.
//

#ifndef DEVANCOMPILER_TRUEEXPRESSION_H
#define DEVANCOMPILER_TRUEEXPRESSION_H


class TrueExpression : Expression {
public:
    TrueExpression(yy::location loc);
    bool eval() const override;
    void Accept(Visitor* visitor) override;
};


#endif //DEVANCOMPILER_TRUEEXPRESSION_H
