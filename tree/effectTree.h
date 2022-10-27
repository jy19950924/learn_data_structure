#ifndef EFFECT_TREE_H
#define EFFECT_TREE_H

#include "tree.h"

template <typename T>
class EffectTree : public Tree
{
public:
    EffectTree() : Tree<T>(){};
    EffectTree(T arr[], size_t n);

    TreeNode<T> *root()
    {
        return this->root;
    }
};
#endif
