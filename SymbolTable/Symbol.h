//
// Created by deliza on 18.03.2021.
//

#ifndef DEVANCOMPILER_SYMBOL_H
#define DEVANCOMPILER_SYMBOL_H

#include <string>
#include <unordered_map>
#include <memory>

class Symbol {
public:
    bool operator==(const Symbol& other) const;
    bool operator!=(const Symbol& other) const;
    std::string GetName() const;
    explicit Symbol(const std::string& name);
    Symbol(const Symbol& other);
private:
    std::string name_;
};

namespace std {
    template<>
    struct hash<Symbol>
    {
        std::size_t operator()(const Symbol& other) const {
            return hash<string>()(other.GetName());
        }
    };

}

#endif //DEVANCOMPILER_SYMBOL_H
