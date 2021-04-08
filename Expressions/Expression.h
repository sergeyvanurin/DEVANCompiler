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

    Type GetType(ScopeLayer *scope) {
        if (expr_type_.type_name.empty()){
            SetScope(scope);
            expr_type_ = EvalType(scope);
        }
        return expr_type_;
    }

    Type GetType() const {
        if (expr_type_.type_name.empty()){
            throw std::runtime_error("Type not evaluated");
        }
        return expr_type_;
    }

    void SetScope(ScopeLayer *scope){
        scope_ = scope;
    }

    ScopeLayer* GetScope() const {
        return scope_;
    }

private:
    ScopeLayer *scope_;
    virtual Type EvalType(ScopeLayer *scope) = 0;
    Type expr_type_;
};


#endif //DEVANCOMPILER_EXPRESSION_H
