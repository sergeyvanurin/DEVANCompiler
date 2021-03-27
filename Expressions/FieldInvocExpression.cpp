//
// Created by deliza on 11.03.2021.
//

#include <variant>
#include "FieldInvocExpression.h"

FieldInvocExpression::FieldInvocExpression(const std::string &field_name, yy::location loc): field_name(field_name), Expression(loc) {

}

std::variant<int, std::string> FieldInvocExpression::eval() const {
    return 0;
}

void FieldInvocExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}
