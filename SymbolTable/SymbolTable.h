//
// Created by deliza on 18.03.2021.
//

#ifndef DEVANCOMPILER_SYMBOLTABLE_H
#define DEVANCOMPILER_SYMBOLTABLE_H

#include "Symbols/BaseSymbol.h"
#include "Objects/Object.h"

#include <unordered_map>
#include <stack>
#include <Symbols/STVariable.h>

class SymbolTable {
public:
    SymbolTable();
    void Put(BaseSymbol symbol, std::shared_ptr<Object> value);

    void CreateVariable(BaseSymbol symbol);

    BaseSymbol GetSymbol(const std::string& name);

    std::shared_ptr<Object> GetValue(BaseSymbol key);

    void BeginScope();
    void EndScope();
private:
    std::unordered_map<BaseSymbol, std::stack<std::shared_ptr<Object>>> values_;
    std::unordered_map<std::string, BaseSymbol> symbols_map_;

    std::stack<BaseSymbol> symbols_;

};


#endif //DEVANCOMPILER_SYMBOLTABLE_H
