// newCode_zuochengyun.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <typeinfo>
#include <cmath>
#include <array>

using std::array;
using std::cin;
using std::cout;
using std::endl;
using std::for_each;
using std::pow;
using std::sort;
using std::string;
using std::swap;
using std::vector;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
