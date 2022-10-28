#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <queue>
#include <stack>
typedef int T;

class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    T val;

    TreeNode() : left(nullptr), right(nullptr), parent(nullptr){};
    TreeNode(T val) : left(nullptr), right(nullptr), val(val), parent(nullptr){};
    TreeNode(T val, TreeNode *left, TreeNode *right) : left(left), right(right), val(val), parent(nullptr){};
    TreeNode(T val, TreeNode *left, TreeNode *right, TreeNode *parent) : left(left), right(right), parent(parent), val(val){};
};

struct Floor
{
    std::deque<std::string> lines;
    int width;
    int height;
    int dist; // 水平距离
    Floor() {}
    Floor(std::deque<std::string> v_lines, int i_width, int i_height, int i_dist)
        : lines(v_lines), width(i_width), height(i_height), dist(i_dist){};
};
class Tree
{
protected:
    TreeNode *root;

private:
    Floor *_drawTree(TreeNode *);

public:
    Tree() : root(nullptr){};
    Tree(T arr[], size_t n);

    TreeNode *getRootNode()
    {
        return this->root;
    }
    void drawTree();
    void preorderTraversal();
    void inorderTraversal();
    void postorderTraversal();

    void inorderSuccessor();

    ~Tree();
};

#endif
