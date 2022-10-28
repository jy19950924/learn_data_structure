#include <iostream>
#include <queue>
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
    string serialize(TreeNode *root)
    {
        vector<string> nodes;
        queue<TreeNode *> que;
        que.push(root);

        TreeNode *tail = root;
        TreeNode *nextTail = nullptr;
        int nextEmptyCount = 0;

        while (!que.empty())
        {
            root = que.front();
            que.pop();
            if (root != nullptr)
            {
                if (root->left != nullptr)
                {
                    nextTail = root->left;
                    while (nextEmptyCount > 0)
                    {
                        que.push(nullptr);
                        nextEmptyCount--;
                    }
                    que.push(root->left);
                    nextEmptyCount = 0;
                }
                else
                    nextEmptyCount++;

                if (root->right != nullptr)
                {
                    nextTail = root->right;
                    while (nextEmptyCount > 0)
                    {
                        que.push(nullptr);
                        nextEmptyCount--;
                    }
                    que.push(root->right);
                    nextEmptyCount = 0;
                }
                else
                    nextEmptyCount++;
            }
            else
            {
                nextEmptyCount += 2;
            }

            if (root == tail)
            {
                tail = nextTail;
            }
        }
    }
    void practise_2()
    {
        using namespace std;
        int data[] = {0, 1, 2, 3, 4, 5, 6, -1, 7, 8};
        int len = sizeof(data) / sizeof(int);

        Tree *ptree = new Tree(data, len);
        ptree->drawTree();
        cout << serialize(ptree->getRootNode()) << endl;
    }
}

int main()
{
    return 0;
}