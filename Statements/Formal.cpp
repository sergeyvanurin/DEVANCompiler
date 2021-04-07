//
// Created by deliza on 19.03.2021.
//

#include "Formal.h"

#include <utility>

Formal::Formal(Type* type, std::string name, yy::location loc) : type(type), name(std::move(name)), Statement(loc) {

}

void Formal::Accept(Visitor *visitor) {
    visitor->Visit(this);
}
