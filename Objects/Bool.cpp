//
// Created by deliza on 19.03.2021.
//

#include "Bool.h"

Bool::Bool(bool value) : value_(value){

}

int Bool::ToInt() {
    return static_cast<int>(value_);
}
