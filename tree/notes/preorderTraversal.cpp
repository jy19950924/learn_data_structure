
//
// Created by dell on 9/20/2022.
//
#include "../tree.h"
#include <stack>
#include <vector>
#include <iostream>

// 先序遍历。主要是非递归版本
void inorderTraversal(TreeNode *root)
{
    using namespace std;
    stack<TreeNode *> stk;
    vector<int> res;
    if (root == nullptr)
        return;
    stk.push(root);
    while (!stk.empty())
    {
        TreeNode *cur = stk.top();
        stk.pop();
        cout << cur->val << ' ';
        if (cur->right != nullptr)
        {
            stk.push(cur->right);
        }
        if (cur->left != nullptr)
        {
            stk.push(cur->left);
        }
    }
}

int main()
{
    int data[] = {0, 2, 4, 6, 3, 5, 77, 8, 8, 9};
    int len = sizeof(data) / sizeof(int);

    Tree tree1 = Tree(data, len);
    inorderTraversal(tree1.root); //2 4 3 8 9 5 6 77 8
}
