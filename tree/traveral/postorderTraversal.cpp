#include <iostream>
#include "../tree.h"
#include <stack>
using namespace std;
void postorderTraversal(TreeNode *root)
{
    stack<TreeNode *> helpStack;
    TreeNode *prev = nullptr, *cur = root;

    while (!helpStack.empty() || cur != nullptr)
    {
        if (cur != nullptr)
        {
            helpStack.push(cur);
            cur = cur->left;
        }
        else
        {
            TreeNode *parentNode = helpStack.top();
            if (parentNode->right == nullptr || parentNode->right == prev)
            {
                cout << parentNode->val << ' ';
                helpStack.pop();
                cur = nullptr;
            }
            else
                cur = parentNode->right;
            prev = parentNode;
        }
    }
}

int main()
{
    using namespace std;
    int data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int len = sizeof(data) / sizeof(int);

    Tree tree = Tree(data, len);
    cout << "postorder traversal: ";
    postorderTraversal(tree.root);

    return 0;
}
