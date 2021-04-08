//
// Created by deliza on 19.03.2021.
//

#include "FormalsList.h"
#include "Visitors/Visitor.h"

FormalsList::FormalsList(yy::location loc) : Statement(loc) {

}

void FormalsList::AddFormal(Formal *formal) {
    formals.push_back(formal);
}

void FormalsList::Accept(Visitor *visitor) {
    visitor->Visit(this);
}