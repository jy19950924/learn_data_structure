#include <iostream>
#include <stack>
#include <string>
#include <vector>

namespace TreeSpace {
using std::stack;
using std::vector;

class Node {
public:
  Node *left;
  Node *right;
  int value;

  Node() : left(nullptr), right(nullptr) {}
};

enum nodeColor { RED = 0, BLOCK };

class rbNode : public Node {
  nodeColor color = RED;

public:
  rbNode() : Node() {}
};

class RBTree {
  rbNode *root = nullptr;

public:
  RBTree() = default;
  RBTree(const vector<int> &data) {}

  void Insert(int val);
  void Display() {
    // 需要后续遍历,第二次经历时记录left 
    vector<std::string> stree;
    stack<rbNode *> stk;
    rbNode *P = root;
    while (!stk.empty() && P != nullptr) {
        
      if (P->left != nullptr) {
      }
    }
  }
  void Delete(int val);
};

} // namespace TreeSpace
