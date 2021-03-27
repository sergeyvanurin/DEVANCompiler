//
// Created by Sergey Vanurin on 02.03.2021.
//

#include "NumExpression.h"

NumExpression::NumExpression(int value, yy::location loc): value(value), Expression(loc) {}

void NumExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);

}

std::variant<int, std::string> NumExpression::eval() const {
    return value;
}
