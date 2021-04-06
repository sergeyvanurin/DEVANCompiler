//
// Created by deliza on 19.03.2021.
//

#include "Formal.h"

Formal::Formal(Type* type, const std::string& name, Scope *scope, yy::location loc) : type(type), name(name), Statement(scope, loc) {

}

void Formal::Accept(Visitor *visitor) {
    visitor->Visit(this);
}
