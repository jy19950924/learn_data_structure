#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

enum NodeColor { RED = 0, BLACK };
enum NodeDirection { LEFT = 0, RIGHT };

struct Node {
  Node *L = nullptr; // left leaf
  Node *R = nullptr; // right leaf
  int V;             // value
  int H = 1;         // height

private:
  // display properties
  NodeColor _color = RED;
  int _leftWidth = 0; // Record for the length of the left leaf.
  int _rightWidth = 0;

public:
  Node() = default;
  Node(int val) : V(val) {}
  // 节点颜色
  NodeColor Color() { return _color; }
  void SetColor(NodeColor color) { _color = color; }

  int GetWidth(NodeDirection direction) {
    return (direction == LEFT) ? (_leftWidth) : (_rightWidth);
  }
  void SetWidth(int width, NodeDirection direction) {
    if (direction == LEFT) {
      _leftWidth = width;
      return;
    }
    _rightWidth = width;
  }
};
//  展示树
void displayTree(Node *root) {}

void updateDisplayDetail(Node *R) {
  Node *P = nullptr;
  Node *C = R;
  std::stack<Node *> stk;

  while (!stk.empty() || C != nullptr) {
    if (C != nullptr) {
      stk.push(C);
      C = C->L;

    } else {
      Node *T = stk.top(); // 临时记录节点
      if (T->R == nullptr || P == T->R) {
        // Third Visited
        if (T->R != nullptr) {
          T->SetWidth(T->R->GetWidth(RIGHT) + 1, RIGHT);
        }

        stk.pop();
        C = nullptr;
      } else {
        // Second Visited
        if (T->L != nullptr) {
          T->SetWidth(T->L->GetWidth(LEFT) + 1, LEFT);
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
  Node *root = new Node(0);

  Node *node1 = new Node(1), *node2 = new Node(2);
  root->L = node1;
  root->R = node2;

  Node *node3 = new Node(3), *node4 = new Node(4);
  node1->L = node3;
  node1->R = node4;

  Node *node5 = new Node(5), *node6 = new Node(6);
  node2->L = node5;
  node2->R = node6;

  std::vector<int> visited = backOrder(root);
  std::for_each(visited.begin(), visited.end(),
                [=](int e) { std::cout << e << " "; });
  std::cout << std::endl;
  return 0;
}
