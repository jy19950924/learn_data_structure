#include "tree.h"

static const int emptyFlag = -1;

Tree::Tree(T *arr, size_t n)
{
    using namespace std;
    TreeNode *nodes = new TreeNode[n];
    for (int i = 0; i < n; i++) {
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

void Tree::preorderTraversal()
{
    using namespace std;

    stack<TreeNode *> stk;
    stk.push(this->root);
    while (!stk.empty()) {
        TreeNode *top = stk.top();
        stk.pop();
        cout << top->val << ' ';
        if (top->right != nullptr) {
            stk.push(top->right);
        }
        if (top->left != nullptr) {
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

    while (!stk.empty() || cur != nullptr) {
        if (cur != nullptr) {
            stk.push(cur);
            cur = cur->left;
        } else {
            cur = stk.top();  // parent node
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

    while (!stk.empty() || cur != nullptr) {
        if (cur != nullptr) {
            stk.push(cur);
            cur = cur->left;
        } else {
            cur = stk.top();
            if (cur->right == nullptr || cur->right == prev) {
                cout << cur->val << ' ';
                stk.pop();
                cur = nullptr;
            } else {
                cur = cur->right;
            }
        }
    }
    cout << endl;
}

void Tree::draw()
{
    using namespace std;
}

Tree::~Tree()
{
    if (this->root != nullptr) {
        delete[] this->root;
    }
}
