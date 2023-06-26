#include "tree.h"

static const int emptyFlag = -1;

Tree::Tree(T arr[], size_t n)
{
    using namespace std;
    TreeNode *nodes = new TreeNode[n];
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
            stk.push(top->right);
        if (top->left != nullptr)
            stk.push(top->left);
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
                cur = cur->right;
        }
    }
    cout << endl;
}
void Tree::drawTree()
{
    using namespace std;
    cout << "Show The Binary Tree: " << endl;
    Floor *_out = this->_drawTree(this->root);
    for (auto i : _out->lines)
        cout << i << endl;
    cout << "successful!" << endl;
}

Floor *Tree::_drawTree(TreeNode *root)
{
    using namespace std;
    std::string s_val = to_string(root->val);
    int s_nval = s_val.size();
    if (root->left == nullptr && root->right == nullptr)
    {
        std::deque<std::string> lines = {s_val};
        int width = s_val.size();
        Floor *n_floor = new Floor(lines, width, 1, width / 2);
        return n_floor;
    }
    else if (root->left == nullptr)
    {
        Floor *right = this->_drawTree(root->right);

        std::string s_nodeFloor = s_val + std::string(right->dist, '_') + string(right->width - right->dist, '_');
        std::string s_flagFloor = string(s_nval + right->dist, ' ') + "\\" + string(right->width - right->dist - 1, ' ');
        for (int i = 0; i < right->lines.size(); i++)
        {
            right->lines[i] = string(s_val.size(), ' ') + right->lines[i];
        }
        right->width += s_nval;
        right->height += 2;
        right->dist = s_nval / 2;
        right->lines.push_front(s_flagFloor);
        right->lines.push_front(s_nodeFloor);
        return right;
    }
    else if (root->right == nullptr)
    {
        Floor *left = this->_drawTree(root->left);

        string s_nodeFloor = string(left->dist + 1, ' ') + string(left->width - left->dist - 1, '_') + s_val;
        string s_flagFloor = string(left->dist, ' ') + "/" + string(left->width - left->dist - 1 + s_nval, ' ');
        for (int i = 0; i < left->lines.size(); i++)
            left->lines[i] = left->lines[i] + string(s_nval, ' ');
        left->dist = left->width + s_nval / 2;
        left->width = left->width + s_nval;
        left->height += 2;

        left->lines.push_front(s_flagFloor);
        left->lines.push_front(s_nodeFloor);
        return left;
    }
    Floor *left = this->_drawTree(root->left);
    Floor *right = this->_drawTree(root->right);
    string s_nodeFloor = string(left->dist + 1, ' ') + string(left->width - left->dist - 1, '_') + s_val +
                         string(right->dist, '_') + string(right->width - right->dist, ' ');
    string s_flagFloor = string(left->dist, ' ') + "/" + string(left->width - left->dist - 1, ' ') +
                         string(s_nval, ' ') + string(right->dist, ' ') + "\\" +
                         string(right->width - right->dist - 1, ' ');
    int index = 0;
    while (index < left->lines.size())
    {
        if (index < right->lines.size())
            left->lines[index] = left->lines[index] + string(s_nval, ' ') + right->lines[index];
        else
            left->lines[index] += string(s_nval, ' ') + string(right->width, ' ');
        index++;
    }
    string s_spaceLeft = string(left->width, ' ');
    while (index < right->lines.size())
    {
        left->lines.push_back(s_spaceLeft + string(s_nval, ' ') + right->lines[index]);
        index++;
    }
    left->dist = left->width + (s_nval) / 2;
    left->width = left->width + s_nval + right->width;
    left->height = left->height > right->height ? (left->height + 2) : (right->height + 2);

    left->lines.push_front(s_flagFloor);
    left->lines.push_front(s_nodeFloor);
    return left;
}

void Tree::_inorderSuccessor(TreeNode *root, TreeNode *target, TreeNode **prev, TreeNode **cur)
{
    if (root == nullptr)
        return;
    this->_inorderSuccessor(root->left, target, prev, cur);
    if ((*prev) == target)
        (*cur) = root;
    (*prev) = root;
    this->_inorderSuccessor(root->right, target, prev, cur);
}

TreeNode *Tree::inorderSuccessor(TreeNode *target, bool recursion)
{
    if (recursion)
    {
        TreeNode *cur = nullptr, *prev = nullptr;
        this->_inorderSuccessor(this->root, target, &prev, &cur);
        return cur;
    }
    using namespace std;
    stack<TreeNode *> stk;
    TreeNode *root = this->root;
    TreeNode *prev = nullptr;
    while (root != nullptr || !stk.empty())
    {
        if (root != nullptr)
        {
            stk.push(root);
            root = root->left;
        }
        else
        {
            root = stk.top();
            stk.pop();
            if (prev == target)
                return root;
            prev = root;
            root = root->right;
        }
    }
    return nullptr;
}

Tree::~Tree()
{
    if (this->root != nullptr)
    {
        delete[] this->root;
    }
}
