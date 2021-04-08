//
// Created by Sergey Vanurin on 04.03.2021.
//

#include "StatementList.h"
#include "Visitors/Visitor.h"

StatementList::StatementList(yy::location loc) : Statement(loc) {}

void StatementList::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

void StatementList::AddStatement(Statement *statement) {
    statements.push_back(statement);
}

