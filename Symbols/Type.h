//
// Created by arseny on 06.04.2021.
//

#ifndef DEVANCOMPILER_TYPE_H
#define DEVANCOMPILER_TYPE_H


#include <string>

class Type {
public:
    Type(std::string type_name = "", bool is_array = false);

    bool operator ==(const Type& other) const;

    bool operator !=(const Type& other) const;

    std::string type_name;
    bool is_array;
};


#endif //DEVANCOMPILER_TYPE_H
