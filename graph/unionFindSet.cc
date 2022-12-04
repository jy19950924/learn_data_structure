#include "unionFindSet.h"

UnionFindSet::UnionFindSet(vector<type_value> nodes) {
  for (auto node : nodes) {
    Node* p = new Node(node);
    p->father(p);
    this->_roots.insert({node, p});
    this->_nodes.insert({node, p});
  }
}

Node* UnionFindSet::Find(type_value value) {
  Node* res = nullptr;
  auto iter = this->_nodes.find(value);
  if (iter != this->_nodes.end()) {
    Node* node = iter.second;
    while (node && node->getFather() != node) {
      node = node->getFather();
    }
    res = node;
  }
  return res;
}
void UnionFindSet::Union(Node* distNode, Node* srcNode) {
  int distRootValue = distNode->getValue();
  int srcRootValue = srcNode->getValue();

  Node* distRoot = this->Find(distRootValue);
  Node* srcRoot = this->Find(srcRootValue);
  if (distRoot != srcRoot) {
    srcRoot->setFather(disRoot);
  }
}