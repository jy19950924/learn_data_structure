/**
 * 完全二叉树
 * 判断一棵树是否是完全二叉树（递归和非递归）
 *
 * 基本思路：
 *  1）左右树中有存在一个为nullptr时，之后所有节点均为叶子节点
 *  2）利用宽度遍历相对来比较容易
 **/

#include <iostream>
#include "./tree.h"
#include <queue>

bool isCompleteBinaryTree_non_recursion(TreeNode *root)
{
    using namespace std;
    bool leaf = false;

    queue<TreeNode *> que;
    que.push(root);
    TreeNode *cur = nullptr;
    while (!que.empty())
    {
        cur = que.front();
        que.pop();

        if (!leaf && (cur->left == nullptr || cur->right == nullptr))
        {
            leaf = true;
        }
        else if (leaf && (cur->left != nullptr || cur->right != nullptr))
        {
            return false;
        }
        if (cur->left != nullptr)
        {
            que.push(cur->left);
        }
        if (cur->right != nullptr)
        {
            que.push(cur->right);
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    using namespace std;

    int data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int data1[] = {0, 1, 2, 3, 4, 5, -1, -1, 8, 9};
    int len = sizeof(data) / sizeof(int);
    int len1 = sizeof(data) / sizeof(int);

    Tree *ptree = new Tree(data, len);
    Tree *ptree1 = new Tree(data1, len1);
    cout << isCompleteBinaryTree_non_recursion(ptree->getRootNode()) << endl;
    cout << isCompleteBinaryTree_non_recursion(ptree1->getRootNode()) << endl;
    return 0;
}
