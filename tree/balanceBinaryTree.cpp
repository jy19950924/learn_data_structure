/**
 * 平衡二叉树
 * 1. 判断是否是平衡二叉树
 *
 *  思路:
 *      1) 左右树的深度  左右树的深度相差不大于1，则该书也为平衡二叉树
 *      2）左右树是否也是平衡二叉树
 **/
#include <iostream>
#include "tree.h"

struct Result
{
    bool isBalance;
    int depth;
    Result(bool isBalance, int depth) : isBalance(isBalance), depth(depth){};
};
Result process(TreeNode *root);
bool isBalanceBinaryTree_recursion(TreeNode *root)
{
    using namespace std;
    return process(root).isBalance;
}

Result process(TreeNode *root)
{
    if (root == nullptr)
        return Result(true, 1);
    Result left = process(root->left);
    Result right = process(root->right);
    int curDepth = left.depth > right.depth ? left.depth + 1 : right.depth + 1;

    int delta = left.depth > right.depth ? (left.depth - right.depth) : (right.depth - left.depth);
    if (!left.isBalance || !right.isBalance || delta > 1)
        return Result(false, curDepth);
    return Result(true, curDepth);
}

int main(int argc, char const *argv[])
{
    using namespace std;

    int data[] = {0, 1, 2, 3, 4, 5};
    int data2[] = {0, 1, 2, 3, 4, 5, -1, -1, -1, -1, 6};
    int len = sizeof(data) / sizeof(int);
    int len2 = sizeof(data2) / sizeof(int);

    Tree *ptree = new Tree(data, len);
    cout << "first tree : " << isBalanceBinaryTree_recursion(ptree->getRootNode()) << endl;
    Tree *ptree2 = new Tree(data2, len2);
    cout << "second tree : " << isBalanceBinaryTree_recursion(ptree2->getRootNode()) << endl;

    return 0;
}
