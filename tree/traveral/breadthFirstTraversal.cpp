#include <iostream>
#include <queue>
#include "../tree.h"

void breadthFirstTraversal(TreeNode *root)
{
    using namespace std;

    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty())
    {
        TreeNode *cur = que.front();
        que.pop();
        cout << cur->val << ' ';
        if (cur->left != nullptr)
        {
            que.push(cur->left);
        }
        if (cur->right != nullptr)
        {
            que.push(cur->right);
        }
    }
    cout << endl;
}

int main()
{
    using namespace std;

    int data[] = {0, 1, 2, 3, 4, 5, 6, -1, 7, 8};
    int len = sizeof(data) / sizeof(int);

    Tree *ptree = new Tree(data, len);
    ptree->inorderTraversal();

    cout << "breath first traversal: ";
    breadthFirstTraversal(ptree->root);
}