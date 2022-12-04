#include "unionFindSet.h"

UnionFindSet::UnionFindSet::UnionFindSet(vector<string> nodes) {
  for (auto node : nodes) {
    Node* p = new Node(node);
    p->setFather(p);
    this->_nodes.insert({node, p});
  }
}

UnionFindSet::Node* UnionFindSet::UnionFindSet::Find(string value) {
  Node* res = nullptr;
  auto iter = this->_nodes.find(value);
  if (iter != this->_nodes.end()) {
    Node* node = iter->second;
    while (node && node->getFather() != node) node = node->getFather();
    res = node;
  }
  return res;
}
void UnionFindSet::UnionFindSet::Union(string distRootValue, string srcRootValue) {
  Node* distRoot = this->Find(distRootValue);
  Node* srcRoot = this->Find(srcRootValue);
  if (distRoot != srcRoot) {
    srcRoot->setFather(distRoot);
  }
}
int UnionFindSet::UnionFindSet::Count() {
  int count = 0;
  for (auto node : this->_nodes) {
    if (node.second->getFather() == node.second) {
      count++;
    }
  }
  return count;
}
// int countCriminalGangs(vector<string>& nodes, vector<vector<string>>& edges) {
//   UnionFindSet findSet(nodes);
//   for (const auto edge : edges) {
//     string fromValue = edge[0], toValue = edge[1];
//     findSet.Union(fromValue, toValue);
//   }
//   return findSet.Count();
// };

// int main() {
//   using namespace std;
//   vector<string> nodes = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11"};
//   vector<vector<string>> edges = {{"1", "2"}, {"4", "5"}, {"3", "4"}, {"1", "3"}, {"5", "6"}, {"7", "10"}, {"5", "10"}, {"8", "9"}};
//   cout << countCriminalGangs(nodes, edges) << endl;
//   return 0;
// }