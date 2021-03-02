//
// Created by Sergey Vanurin on 02.03.2021.
//

#include "NumExpression.h"

NumExpression::NumExpression(int value): value(value) {}

void NumExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);

}

int NumExpression::eval() const {
    return value;
}
