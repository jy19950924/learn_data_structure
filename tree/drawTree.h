#ifndef DRAW_TREE_H
#define DRAW_TREE_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <deque>
#include "./tree.h"

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

Floor *drawBinaryTree(TreeNode *root);

#endif
