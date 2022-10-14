/**
 * 二叉搜索树
 * 判断二叉树是否是二叉搜索树
 **/

#include <iostream>
#include "tree.h"
// 递归
int preMaxValue = 0;
bool isBinarySearchTree(TreeNode *head)
{
    if (head == nullptr)
    {
        return true;
    }

    bool left = isBinarySearchTree(head->left);
    if (!left)
        return false;

    if (head->val > preMaxValue)
    {
        preMaxValue = head->val;
    }
    else
    {
        return false;
    }
    return isBinarySearchTree(head->right);
}

int main(int argc, char const *argv[])
{
    using namespace std;
    int data[] = {0, 5, 2, 7, 1, 3, 6, 8};
    int len = sizeof(data) / sizeof(int);

    Tree *ptree = new Tree(data, len);

    cout << isBinarySearchTree(ptree->root) << endl;

    return 0;
}
