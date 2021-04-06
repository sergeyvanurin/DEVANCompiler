//
// Created by deliza on 19.03.2021.
//

#ifndef DEVANCOMPILER_STVARIABLE_H
#define DEVANCOMPILER_STVARIABLE_H


#include <Statements/VarDeclaration.h>
#include "BaseSymbol.h"

class STVariable : public BaseSymbol {
public:
    explicit STVariable(const std::string& name, std::string type = "int");
    explicit STVariable(VarDeclaration* var_decl);
    std::string type;
};

namespace std {
    template<>
    struct hash<STVariable> {
        std::size_t operator()(const STVariable &other) const {
            return hash<string>()(other.GetName());
        }
    };
}

#endif //DEVANCOMPILER_STVARIABLE_H
