/**
 * 二叉搜索树
 * 判断二叉树是否是二叉搜索树
 **/

#include <iostream>
#include "tree.h"
// 递归
int preMaxValue = 0;
bool isBinarySearchTree_recursion(TreeNode *head)
{
    if (head == nullptr)
    {
        return true;
    }

    bool left = isBinarySearchTree_recursion(head->left);
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
    return isBinarySearchTree_recursion(head->right);
}

bool isBinarySearchTree_non_recursion(TreeNode *root)
{
    using namespace std;
    stack<TreeNode *> stk;
    TreeNode *cur = root; //不能将root存放再stk中，否则会首次触发，此时，会将root节点设置为maxval,则无法继续判断左数是否为搜索树
    int maxval = 0;

    while (!stk.empty() || cur != nullptr)
    {
        if (cur != nullptr)
        {
            stk.push(cur);
            cur = cur->left;
        }
        else
        {
            cur = stk.top();
            if (cur->val > maxval)
                maxval = cur->val;
            else
                return false;
            stk.pop();
            cur = cur->right;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    using namespace std;
    int data[] = {0, 5, 4, 7, 1, 3, 6, 8};
    int len = sizeof(data) / sizeof(int);

    Tree *ptree = new Tree(data, len);

    cout << "the result of recursion method: " << isBinarySearchTree_recursion(ptree->root) << endl;
    cout << "the result of non-recursion method: " << isBinarySearchTree_non_recursion(ptree->root) << endl;
    return 0;
}
