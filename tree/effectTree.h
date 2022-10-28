#ifndef EFFECT_TREE_H
#define EFFECT_TREE_H

#include "tree.h"

typedef int T;
const int emptyFlag = -1;

class EffectTree : public Tree
{
public:
    EffectTree() : Tree(){};
    EffectTree(T arr[], size_t n);

    TreeNode *inorderSuccessor(TreeNode *target);
};

#endif
