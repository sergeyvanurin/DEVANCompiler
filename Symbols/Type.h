//
// Created by deliza on 06.04.2021.
//

#ifndef DEVANCOMPILER_TYPE_H
#define DEVANCOMPILER_TYPE_H


#include <string>

#ifdef BITS32
const int POINTER_SIZE = 4;
#else
const int POINTER_SIZE = 8;
#endif

class Type {
public:
    explicit Type(std::string type_name = "", bool is_array = false);

    bool operator ==(const Type& other) const;

    bool operator !=(const Type& other) const;

    int GetSize() const;

    std::string ToString() const;

    std::string type_name;
    bool is_array;
};


#endif //DEVANCOMPILER_TYPE_H
