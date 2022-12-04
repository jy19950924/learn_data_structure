#include "unionFindSet.h"

UnionFindSet::UnionFindSet(vector<type_value> nodes) {
  for (auto node : nodes) {
    Node* p = new Node(node);
    p->father(p);
    this->_roots.insert({node, p});
  }
}

Node* UnionFindSet::Find(type_value value) { Node* res = nullptr; }