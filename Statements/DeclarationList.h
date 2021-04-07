//
// Created by deliza on 04.03.2021.
//


#ifndef DEVANCOMPILER_DECLARATIONS_H
#define DEVANCOMPILER_DECLARATIONS_H

#include <vector>
#include <variant>
#include "Statement.h"

class DeclarationList : public Statement {
public:
    using var_method_decl_t = std::variant<VarDeclaration*, MethodDeclaration*>;
    DeclarationList(yy::location loc);
    void AddDeclaration(var_method_decl_t decl);

    std::vector<var_method_decl_t> declarations;

    void Accept(Visitor* visitor) override;
};


#endif //DEVANCOMPILER_DECLARATIONS_H
