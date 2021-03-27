//
// Created by Sergey Vanurin on 02.03.2021.
//

#include <variant>
#include "IdentExpression.h"

IdentExpression::IdentExpression(std::string& var_name, yy::location loc): var_name(var_name), Expression(loc) {}

void IdentExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);

}

std::variant<int, std::string> IdentExpression::eval() const {
    return var_name;
}


