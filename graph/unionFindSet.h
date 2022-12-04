#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Node {
  Node* _father;
  string _val;

 public:
  Node(string val) : _father(nullptr), _val(val) {}
  Node() : Node("0") {}

  void setFather(Node* f) { this->_father = f; }
  Node* getFather() { return this->_father; }

  string getValue() { return this->_val; }
};

class UnionFindSet {
 public:
  UnionFindSet(vector<string> nodes);

  Node* Find(string targer);
  void Union(string distNodeValue, string srcNodeValue);
  int Count();

 private:
  std::map<string, Node*> _nodes;
};
