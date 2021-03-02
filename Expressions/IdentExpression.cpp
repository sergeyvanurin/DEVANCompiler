//
// Created by Sergey Vanurin on 02.03.2021.
//

#include "IdentExpression.h"

IdentExpression::IdentExpression(std::string& var_name): var_name(var_name) {}

void IdentExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);

}

int IdentExpression::eval() const {
    return 0;
}


