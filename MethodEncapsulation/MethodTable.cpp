//
// Created by Sergey Vanurin on 06.04.2021.
//

#include "MethodTable.h"

void MethodTable::Put(BaseSymbol &symbol, int index) {
    variables_[symbol].pop();
    variables_[symbol].push(index);
    symbols_.push(symbol);
}

int MethodTable::Get(BaseSymbol& key) {
    return variables_[key].top();
}

void MethodTable::CreateVariable(BaseSymbol& new_var) {
    variables_[new_var] = std::stack<int>();
    variables_[new_var].push(0);
}

void MethodTable::BeginScope() {
    symbols_.push(BaseSymbol("{"));
}

void MethodTable::EndScope() {
    while (symbols_.top() != BaseSymbol("{")){
        BaseSymbol current_symbol = symbols_.top();
        variables_[current_symbol].pop();
        if (variables_[current_symbol].empty()){
            variables_.erase(current_symbol);
        }
        symbols_.pop();
    }
    symbols_.pop();
}


