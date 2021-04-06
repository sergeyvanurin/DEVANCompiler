//
// Created by Sergey Vanurin on 01.03.2021.
//

#ifndef DEVANCOMPILER_EXPRESSION_H
#define DEVANCOMPILER_EXPRESSION_H

#include "Bases/BaseElement.h"

#include "SymbolTable/ScopeLayer.h"

class Expression: public BaseElement {
public:
    explicit Expression(yy::location loc): BaseElement(loc) {}
    virtual std::variant<int, std::string> eval() const = 0;

    std::string GetType(ScopeLayer *scope) {
        if (expr_type_.empty()){
            expr_type_ = EvalType(scope);
        }
        return expr_type_;
    }

private:
    virtual std::string EvalType(ScopeLayer *scope) = 0;
    std::string expr_type_;
};


#endif //DEVANCOMPILER_EXPRESSION_H
