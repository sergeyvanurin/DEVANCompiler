//
// Created by Sergey Vanurin on 06.04.2021.
//

#ifndef DEVANCOMPILER_METHODTABLE_H
#define DEVANCOMPILER_METHODTABLE_H

#include "../Symbols/BaseSymbol.h"
#include <unordered_map>
#include <stack>


class MethodTable {
    void Put(BaseSymbol& symbol, int index);
    int Get(BaseSymbol& key);
    void CreateVariable(BaseSymbol& new_var);
    void BeginScope();
    void EndScope();

private:
    std::unordered_map<BaseSymbol, std::stack<int>> variables_;
    std::stack<BaseSymbol> symbols_;

};


#endif //DEVANCOMPILER_METHODTABLE_H
