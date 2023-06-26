#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#include <queue>

enum NodeColor { RED = 0, BLACK };
enum NodeDirection { LEFT = 0, RIGHT };
const int  MaxTreeDepth = 100;

struct Node {
  Node* L = nullptr; // left leaf
  Node* R = nullptr; // right leaf
  int V;             // value

  // display properties
  int LCount = 0; // Record for the length of the left leaf.
  int RCount = 0;

private:
  NodeColor _color = RED;

public:
  Node() = default;
  Node(int val) : V(val) {}
  // 节点颜色
  NodeColor Color() { return _color; }
  void SetColor(NodeColor color) { _color = color; }
};

//  展示树
void displayTree(Node* R) {
  updateDisplayDetail(R);
  std::vector<std::string> stree(100, "");

  // Level traveral
  buildDisplayTree(R, 0, stree);
}
// 构建展示树
void buildDisplayTree(Node* N, int level, std::vector<std::string>& stree, NodeDirection direct) {
  if (N == nullptr) {
    return;
  }
  buildDisplayTree(N->L, level + 1, stree);
  // build son tree
  stree[level] = std::to_string(N->L->LCount, ' ') + std::to_string(N->L->RCount + 1, '-') + std::to_string(N->V) + std::to_string();
  if (direct == RIGHT) {
    // node 应当插入到level行 right
    stree[level] = stree[level] + std::to_string(N->R->GetWidth(LEFT), '-') + std::to_string(N->R->GetWidth(RIGHT), ' ');
  } else {
    // node 应当插入到level行 left
    stree[level] = std::to_string() + stree[level]
  }

  buildDisplayTree(N->R, level + 1, stree);
}

// 更新展示树的相关信息
void updateDisplayDetail(Node* R) {
  Node* P = nullptr;
  Node* C = R;
  std::stack<Node*> stk;

  while (!stk.empty() || C != nullptr) {
    if (C != nullptr) {
      stk.push(C);
      C = C->L;
    } else {
      Node* T = stk.top(); // 临时记录节点
      if (T->R == nullptr || P == T->R) {
        // Third Visited
        if (T->R != nullptr) {
          T->RCount = (T->R->LCount) + (T->R->RCount) + 1;
        }

        stk.pop();
        C = nullptr;
      } else {
        // Second Visited
        if (T->L != nullptr) {
          T->LCount = (T->L->LCount) + (T->L->RCount) + 1;
        }
        C = T->R;
      }
      P = T;
    }
  }
}

/*!SECTION Test Code*/
int main() {
  // Build Tree
  Node* root = new Node(0);

  Node* node1 = new Node(1), * node2 = new Node(2);
  root->L = node1;
  root->R = node2;

  Node* node3 = new Node(3), * node4 = new Node(4);
  node1->L = node3;
  node1->R = node4;

  Node* node5 = new Node(5), * node6 = new Node(6);
  node2->L = node5;
  node2->R = node6;

  std::vector<int> visited = (root);
  std::for_each(visited.begin(), visited.end(),
    [=](int e) { std::cout << e << " "; });
  std::cout << std::endl;
  return 0;
}
