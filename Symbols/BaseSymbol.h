//
// Created by deliza on 18.03.2021.
//

#ifndef DEVANCOMPILER_BASESYMBOL_H
#define DEVANCOMPILER_BASESYMBOL_H

#include <string>
#include <unordered_map>
#include <memory>

class BaseSymbol {
public:
    bool operator==(const BaseSymbol& other) const;
    bool operator!=(const BaseSymbol& other) const;
    std::string GetName() const;
    explicit BaseSymbol(const std::string& name);
    BaseSymbol(const BaseSymbol& other);

    BaseSymbol() = default;

private:
    std::string name_;
};

namespace std {
    template<>
    struct hash<BaseSymbol>
    {
        std::size_t operator()(const BaseSymbol& other) const {
            return hash<string>()(other.GetName());
        }
    };

}

#endif //DEVANCOMPILER_BASESYMBOL_H
