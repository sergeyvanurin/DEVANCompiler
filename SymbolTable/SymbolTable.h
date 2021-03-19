//
// Created by deliza on 18.03.2021.
//

#ifndef DEVANCOMPILER_SYMBOLTABLE_H
#define DEVANCOMPILER_SYMBOLTABLE_H

#include "Symbol.h"
#include "Objects/Object.h"

#include <unordered_map>
#include <stack>

class SymbolTable {
public:
    SymbolTable();
    void Put(Symbol symbol, std::shared_ptr<Object> value);

    void CreateVariable(Symbol symbol);
    void CreateMethod();
    

    Symbol GetSymbol(const std::string& name);

    std::shared_ptr<Object> Get(Symbol key);

    void BeginScope();
    void EndScope();
private:
    std::unordered_map<Symbol, std::stack<std::shared_ptr<Object>>> values_;
    std::unordered_map<std::string, Symbol> symbols_map_;

    std::stack<Symbol> symbols_;

};


#endif //DEVANCOMPILER_SYMBOLTABLE_H
