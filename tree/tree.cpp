#include "tree.h"

static const int emptyFlag = -1;

template <typename T>
Tree<T>::Tree(T arr[], size_t n)
{
    using namespace std;
    TreeNode<T> *nodes = new TreeNode<T>[n];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == emptyFlag)
            continue;
        int leftIndex = 2 * i + 1;
        int rightIndex = 2 * i + 2;
        nodes[i].val = arr[i];
        nodes[i].left = leftIndex < n && arr[leftIndex] != emptyFlag ? (nodes + leftIndex) : nullptr;
        nodes[i].right = rightIndex < n && arr[rightIndex] != emptyFlag ? (nodes + rightIndex) : nullptr;
    }
    this->root = nodes;
}

template <typename T>
void Tree<T>::preorderTraversal()
{
    using namespace std;

    stack<TreeNode<T> *> stk;
    stk.push(this->root);
    while (!stk.empty())
    {
        TreeNode<T> *top = stk.top();
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

template <typename T>
void Tree<T>::inorderTraversal()
{
    using namespace std;
    stack<TreeNode<T> *> stk;
    TreeNode<T> *cur = root;

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

template <typename T>
void Tree<T>::postorderTraversal()
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
template <typename T>
void Tree<T>::drawTree()
{
    using namespace std;
    cout << "Show The Binary Tree: " << endl;
    Floor *_out = draw(this->root);
    for (auto i : _out->lines)
        cout << i << endl;
    cout << "successful!" << endl;
}

template <typename T>
Tree<T>::~Tree()
{
    if (this->root != nullptr)
    {
        delete[] this->root;
    }
}
