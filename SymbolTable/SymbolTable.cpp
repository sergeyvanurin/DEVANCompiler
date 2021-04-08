//
// Created by deliza on 18.03.2021.
//

#include "SymbolTable.h"
#include <iostream>
#include <Objects/Int.h>

SymbolTable::SymbolTable() {

}

void SymbolTable::Put(BaseSymbol symbol, std::shared_ptr<Object> value) {
    if (values_.find(symbol) == values_.end()) {
        throw std::runtime_error(symbol.GetName() +  ": variable not declared");
    }
    values_[symbol].pop();
    values_[symbol].push(value);
    symbols_.push(symbol);
}

void SymbolTable::CreateVariable(BaseSymbol symbol) {
    if (values_.find(symbol) == values_.end()) {
        values_.insert({symbol, std::stack<std::shared_ptr<Object>>()});
    }
    values_[symbol].push(std::make_shared<Int>(0));
}

BaseSymbol SymbolTable::GetSymbol(const std::string &name) {
    auto it = symbols_map_.find(name);

    if (it == symbols_map_.end()) {
        BaseSymbol symbol (name);
        symbols_map_.insert({name, symbol});
        return symbol;
    } else {
        return it->second;
    }
}

std::shared_ptr<Object> SymbolTable::GetValue(BaseSymbol key) {
    if (values_.find(key) == values_.end()) {
        throw std::runtime_error(key.GetName() + ": variable not declared");
    }
    return values_[key].top();
}

void SymbolTable::BeginScope() {
    symbols_.push(BaseSymbol("{"));
}

void SymbolTable::EndScope() {
    while (symbols_.top() != BaseSymbol("{")) {
        BaseSymbol symbol = symbols_.top();
        values_[symbol].pop();
        if (values_[symbol].empty()) {
            values_.erase(symbol);
        }
        symbols_.pop();
        if (symbols_.empty())
            throw std::runtime_error("Expected { on the top of the stack_, got" + symbol.GetName());
    }
    symbols_.pop();
}
