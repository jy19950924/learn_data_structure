#include "./effectTree.h"

template <typename T>
EffectTree<T>::EffectTree(T arr[], size_t n)
{
    this->root = new TreeNode<T>[n];
}
