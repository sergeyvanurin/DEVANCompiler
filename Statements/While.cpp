//
// Created by Sergey Vanurin on 02.03.2021.
//

#include "While.h"

While::While(Expression *expr, Statement *statement): expr(expr), statement(statement) {}

void While::Accept(Visitor *visitor) {
    visitor->Visit(this);
}
