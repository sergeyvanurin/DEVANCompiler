//
// Created by deliza on 07.04.2021.
//

#include "ScopeBlock.h"
#include "Visitors/Visitor.h"

ScopeBlock::ScopeBlock(StatementList *statements, yy::location loc): statements(statements), Statement(loc) {

}

void ScopeBlock::Accept(Visitor *visitor) {
    visitor->Visit(this);
}
