#include <iostream>
#include <queue>
#include <string>
#include "./tree.h"

namespace practise_1
{
    // 题目要求：二叉树最大宽度。
    /**
     *        1
     *      /   \
     *     2     3
     *    / \   /
     *   4   5 6
     *  / \
     * 7   8
     *
     * result 3  第三层有三个元素
     **/
    int getTreeMaxWidth(TreeNode *root)
    {
        using namespace std;

        queue<TreeNode *> que;
        que.push(root);
        TreeNode *tail = root, *nextTail = nullptr;
        size_t count = 0;
        int max = 0;

        while (!que.empty())
        {
            TreeNode *cur = que.front();
            que.pop();

            count++;
            if (cur->left != nullptr)
            {
                que.push(cur->left);
                nextTail = cur->left;
            }
            if (cur->right != nullptr)
            {
                que.push(cur->right);
                nextTail = cur->right;
            }

            if (tail == cur)
            {
                max = count > max ? count : max;
                count = 0;
                tail = nextTail;
                nextTail = nullptr;
            }
        }
        return max;
    }
    void practise_1()
    {
        using namespace std;

        int data[] = {0, 1, 2, 3, 4, 5, 6, -1, 7, 8};
        int len = sizeof(data) / sizeof(int);

        Tree *ptree = new Tree(data, len);
        cout << "tree Max width: " << getTreeMaxWidth(ptree->getRootNode()) << endl;
    }
}

namespace practise_2
{
    using std::queue;
    using std::string;
    using std::vector;
    void _serialize(TreeNode *root, string &result)
    {
        if (root == nullptr)
        {
            result += "null,";
            return;
        }
        string res = std::to_string(root->val);
        result += res + ",";
        _serialize(root->left, result);
        _serialize(root->right, result);
    }
    string serialize(TreeNode *root)
    {
        string result = "";
        _serialize(root, result);
        return result;
    }
    TreeNode *_deserialize(std::deque<string> &nodes)
    {
        if (nodes.front() == "null")
        {
            nodes.pop_front();
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(nodes.front()));
        nodes.pop_front();
        root->left = _deserialize(nodes);
        root->right = _deserialize(nodes);
        return root;
    }

    TreeNode *deserialize(string data)
    {
        using namespace std;
        std::deque<string> nodes;
        string str;
        for (auto &ch : data)
        {
            if (ch == ',')
            {
                nodes.push_back(str);
                str.clear();
            }
            else
                str.push_back(ch);
        }
        return _deserialize(nodes);
    }
    void practise_2()
    {
        using namespace std;
        int data[] = {0, 1, 2, 3, 4, 5, 6, -1, 7, 8};
        int len = sizeof(data) / sizeof(int);

        Tree *ptree = new Tree(data, len);
        ptree->drawTree();
        serialize(ptree->getRootNode());
    }
}

int main()
{
    using namespace std;
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        practise_1::practise_1();
        break;
    case 2:
        practise_2::practise_2();
        break;
    default:
        break;
    }
}
