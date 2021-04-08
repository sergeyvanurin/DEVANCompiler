//
// Created by arseny on 08.04.2021.
//

#ifndef DEVANCOMPILER_FIELDDECLARATION_H
#define DEVANCOMPILER_FIELDDECLARATION_H

#include "VarDeclaration.h"

class FieldDeclaration : public VarDeclaration {
public:
    FieldDeclaration(Type type, std::string  field_name, yy::location loc);
    void Accept(Visitor* visitor) override;
};


#endif //DEVANCOMPILER_FIELDDECLARATION_H
