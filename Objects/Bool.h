//
// Created by deliza on 19.03.2021.
//

#ifndef DEVANCOMPILER_BOOL_H
#define DEVANCOMPILER_BOOL_H

#include "Object.h"

class Bool : public Object {
public:
    explicit Bool(bool value);
    int ToInt() override;
private:
    bool value_;
};


#endif //DEVANCOMPILER_BOOL_H
