//
// Created by deliza on 27.03.2021.
//

#include "Return.h"

void Return::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

Return::Return(Expression *expr, yy::location loc): expr(expr), Statement(loc) {

}
