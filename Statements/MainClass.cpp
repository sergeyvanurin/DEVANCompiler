//
// Created by Sergey Vanurin on 01.03.2021.
//

#include "MainClass.h"

void MainClass::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

void MainClass::add_statement(Statement *statement) {
    statements.push(statement);
}
