//
// Created by Sergey Vanurin on 04.03.2021.
//

#include "StatementList.h"

StatementList::StatementList(Scope *Scope, yy::location loc) : Statement(Scope, loc) {}

void StatementList::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

void StatementList::AddStatement(Statement *statement) {
    statements.push_back(statement);
}

