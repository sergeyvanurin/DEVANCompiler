//
// Created by Sergey Vanurin on 01.03.2021.
//

#include "MainClass.h"
#include "Visitors/Visitor.h"

void MainClass::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

MainClass::MainClass(StatementList *statements, yy::location loc): statements(statements), Statement(loc) {}