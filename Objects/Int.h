//
// Created by deliza on 19.03.2021.
//

#ifndef DEVANCOMPILER_INT_H
#define DEVANCOMPILER_INT_H

#include "Object.h"

class Int : public Object {
public:
    explicit Int(int value);
    int ToInt() override;
private:
    int value_;
};


#endif //DEVANCOMPILER_INT_H
