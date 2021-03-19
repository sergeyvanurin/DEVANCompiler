//
// Created by deliza on 18.03.2021.
//

#include "SymbolTable.h"
#include <iostream>

SymbolTable::SymbolTable() {

}

void SymbolTable::Put(BaseSymbol symbol, std::shared_ptr<Object> value) {
    if (values_.find(symbol) == values_.end()) {
        //values_[symbol] = value;
    }
}

void SymbolTable::CreateVariable(BaseSymbol symbol) {
    if (values_.find(symbol) == values_.end()) {
        values_.insert({symbol, std::stack<std::shared_ptr<Object>>()});
    }
}

BaseSymbol SymbolTable::GetSymbol(const std::string &name) {
    //return BaseSymbol(name);
}

std::shared_ptr<Object> SymbolTable::Get(BaseSymbol key) {
    return nullptr;
}

void SymbolTable::BeginScope() {
    symbols_.push(BaseSymbol("{"));
}

void SymbolTable::EndScope() {
    while (symbols_.top() != BaseSymbol("{")) {
        BaseSymbol symbol = symbols_.top();

        std::cerr << "Popping " << symbol.GetName() << std::endl;

        values_[symbol].pop();
        if (values_[symbol].empty()) {
            values_.erase(symbol);
        }
        symbols_.pop();
        if (symbols_.empty())
            throw std::runtime_error("Expected { on the top of the stack, got" + symbol.GetName());
    }
    symbols_.pop();
}
