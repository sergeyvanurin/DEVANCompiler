//
// Created by deliza on 27.03.2021.
//

#include "ThisExpression.h"

ThisExpression::ThisExpression(yy::location loc) : Expression(loc) {

}

void ThisExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

int ThisExpression::eval() const {
    return 0;
}
