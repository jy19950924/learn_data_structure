#include <iostream>
#include <map>
#include <vector>

using std::vector;

class Node {
  Node* _father;
  int _val;

 public:
  Node(int val) : _father(nullptr), _val(val) {}
  Node() : Node(0) {}

  void setFather(Node* f) { this->_father = f; }
  Node* getFather() { return this->_father; }

  int getValue() { return this->_val; }
};
// not weight
class UnionFindSet {
 public:
  UnionFindSet(vector<int> nodes);

  Node* Find(int targer);
  void Union(int distNodeValue, int srcNodeValue);
  int Count();

 private:
  std::map<int, Node*> _nodes;
};
