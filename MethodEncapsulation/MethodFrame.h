//
// Created by Sergey Vanurin on 06.04.2021.
//

#ifndef DEVANCOMPILER_METHODFRAME_H
#define DEVANCOMPILER_METHODFRAME_H

#include <memory>
#include <stack>
#include <variant>
#include <unordered_map>
#include "Symbols/STMethod.h"
#include "Symbols/Type.h"

class MethodFrame {
    MethodFrame(std::shared_ptr<STMethod> function);
    void SetParametres(const std::vector<std::variant<int, bool, >>& values);
    size_t AllocVar();
    int Get(int index);

};


#endif //DEVANCOMPILER_METHODFRAME_H
