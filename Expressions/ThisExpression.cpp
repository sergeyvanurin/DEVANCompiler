//
// Created by deliza on 27.03.2021.
//

#include <variant>
#include "ThisExpression.h"

ThisExpression::ThisExpression(yy::location loc) : Expression(loc) {

}

void ThisExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

std::variant<int, std::string> ThisExpression::eval() const {
    return 0;
}
