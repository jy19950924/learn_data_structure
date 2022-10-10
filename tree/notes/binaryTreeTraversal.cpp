//
// Created by dell on 9/20/2022.
//
#include "../../public.h"
#include <stack>

using std::stack;

// 先序遍历。主要是非递归版本
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        stack < TreeNode * > stk;
        vector<int> res;
        if (root == nullptr) return res;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode *cur = stk.top();
            stk.pop();
            res.push_back(cur->val);
            if (cur->right != nullptr) {
                stk.push(cur->right);
            }
            if (cur->left != nullptr) {
                stk.push(cur->left);
            }
        }
        return res;
    }
};

/**
 * 1
 * 2 3
 * 4 -1 5 -1
 * -1 6
 * @return
 */
int main() {
    TreeNode *head = TreeNode(1);
    TreeNode *tail = head;
//    first floor
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    head->left = node2;
    head->right = node3;
//    second floor
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    node2->left = node4;
    node2->right = nullptr;
    node3->left = node5;
    node3->right = nullptr;
//    third floor
    TreeNode *node6 = new TreeNode(6);
    node4->left = nullptr;
    node4->right = node6;


}