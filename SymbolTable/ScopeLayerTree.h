//
// Created by deliza on 05.04.2021.
//

#ifndef DEVANCOMPILER_SCOPELAYERTREE_H
#define DEVANCOMPILER_SCOPELAYERTREE_H

#include "ScopeLayer.h"

class ScopeLayerTree {
public:
    explicit ScopeLayerTree(ScopeLayer* root);
public:
    ScopeLayer* root_;
};


#endif //DEVANCOMPILER_SCOPELAYERTREE_H
