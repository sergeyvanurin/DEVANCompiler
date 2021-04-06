//
// Created by deliza on 11.03.2021.
//

#include <variant>
#include "FieldInvokeExpression.h"

FieldInvokeExpression::FieldInvokeExpression(const std::string &field_name, yy::location loc): field_name(field_name), Expression(loc) {

}

std::variant<int, std::string> FieldInvokeExpression::eval() const {
    return 0;
}

void FieldInvokeExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}
