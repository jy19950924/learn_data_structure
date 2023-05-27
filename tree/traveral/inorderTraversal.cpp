#include <iostream>
#include "../tree.h"

// 中序遍历
// left !=null ->push;
// left ==null, cout, right!= nullptr -> push
void inorderTraversal(TreeNode *root)
{
    using namespace std;

    stack<TreeNode *> helpStack;
    TreeNode *cur = root;

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
            helpStack.pop();
            cout << parentNode->val << ' ';
            cur = parentNode->right;
            // 如果右树也为空，则说明父亲节点左右子树均遍历完成，且左树为null
            // 此时应当打印父亲节点
        }
    }
    cout << endl;
}

int main()
{
    using namespace std;
    int data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int len = sizeof(data) / sizeof(int);

    Tree tree = Tree(data, len);
    cout << "inorder traversal: ";
    inorderTraversal(tree.root);
    cout << "done!" << endl;
}
