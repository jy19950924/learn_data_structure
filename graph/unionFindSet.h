#include <iostream>
#include <map>
#include <vector>

using std::vector;

class Node {
  Node* _father;
  int _val;

 public:
  Node(int val) : _father(nullptr), _val(val) {}
  Node() : Node() {}

  void setFather(Node* f) { this->_father = f; }
  Node* getFather() { return this->_father; }

  int getValue() { return this->_val; }
};
// not weight
class UnionFindSet {
 public:
  typedef int type_value;
  UnionFindSet() = default;
  UnionFindSet(vector<type_value> nodes);

  Node* Find(int targer);
  void Union(Node* distNode, Node* srcNode);

 private:
  std::map<type_value, Node*> _roots;
  std::map<type_value, Node*> _nodes;
};