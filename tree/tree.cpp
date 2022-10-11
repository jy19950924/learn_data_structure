#include "tree.h"

static const int emptyFlag = -1;

Tree::Tree(T *arr, size_t n)
{
    using namespace std;

    TreeNode *nodes = new TreeNode[n];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == emptyFlag)
            continue;

        nodes[i].val = arr[i];
        nodes[i].left = 2 * i < n && arr[2 * i] != emptyFlag ? (nodes + 2 * i) : nullptr;
        nodes[i].right = (2 * i + 1) < n && arr[2 * i + 1] != emptyFlag ? (nodes + 2 * i + 1) : nullptr;
    }
    this->root = &nodes[1];
    this->_mhead = nodes;
}

void Tree::preorderTraversal()
{
    using namespace std;

    stack<TreeNode *> stk;
    stk.push(this->root);
    while (!stk.empty())
    {
        TreeNode *top = stk.top();
        stk.pop();
        cout << top->val << ' ';
        if (top->right != nullptr)
        {
            stk.push(top->right);
        }
        if (top->left != nullptr)
        {
            stk.push(top->left);
        }
    }
    cout << endl;
}

void Tree::inorderTraversal()
{
    using namespace std;
    stack<TreeNode *> stk;
    TreeNode *cur = root;

    while (!stk.empty() || cur != nullptr)
    {
        if (cur != nullptr)
        {
            stk.push(cur);
            cur = cur->left;
        }
        else
        {
            cur = stk.top(); // parent node
            stk.pop();
            cout << cur->val << ' ';
            cur = cur->right;
        }
    }
}

void Tree::postorderTraversal()
{
    using namespace std;

    stack<TreeNode *> stk;
    TreeNode *prev = nullptr, *cur = root;

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
            if (cur->right == nullptr || cur->right == prev)
            {
                cout << cur->val << ' ';
                stk.pop();
                cur = nullptr;
            }
            else
            {
                cur = cur->right;
            }
        }
    }
    cout << endl;
}

void Tree::drawTree()
{
    using namespace std;
}

Tree::~Tree()
{
    if (this->_mhead != nullptr)
    {
        delete[] this->_mhead;
    }
}
