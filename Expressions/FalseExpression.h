//
// Created by deliza on 11.03.2021.
//

#ifndef DEVANCOMPILER_FALSEEXPRESSION_H
#define DEVANCOMPILER_FALSEEXPRESSION_H


class FalseExpression {
public:
    FalseExpression(yy::location loc);
    bool eval() const override;
    void Accept(Visitor* visitor) override;
};


#endif //DEVANCOMPILER_FALSEEXPRESSION_H
