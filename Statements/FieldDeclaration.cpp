//
// Created by Sergey Vanurin on 08.04.2021.
//

#include "FieldDeclaration.h"
#include "Visitors/Visitor.h"
#include <utility>


void FieldDeclaration::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

FieldDeclaration::FieldDeclaration(Type type, std::string field_name, yy::location loc) : VarDeclaration(
        std::move(type),
        std::move(field_name),
        loc) {

}
