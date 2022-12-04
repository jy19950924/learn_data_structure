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

  void father(Node* f) { this->_father = f; }
};
// not weight
class UnionFindSet {
 public:
  typedef int type_value;
  UnionFindSet() = default;
  UnionFindSet(int count, std::vector<std::vector<int>> connects);

  Node* Find(int targer);
  Node* Union(Node* dist, Node* src);

 private:
  std::map<type_value, Node*> _roots;
};