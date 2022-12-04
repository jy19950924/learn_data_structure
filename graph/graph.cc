#include "./graph.h"

#include <algorithm>
#include <fstream>

Edge::Edge(Node *from, Node *to, int weight) {
  this->_from = from;
  this->_weight = weight;
  this->_to = to;
}

void Graph::display() {
  std::map<Node *, int> collects;
  int idx = 0;
  for (const auto &node : nodes) collects.insert({node, idx++});

  size_t len = this->nodes.size();
  vector<vector<string>> matrix(len + 1, vector<string>(len + 1, "X"));
  for (auto &node : this->nodes) {
    int nodeIndex = collects.find(node)->second;
    matrix[len][nodeIndex] = matrix[nodeIndex][len] = node->val;
  }
  this->_display(matrix, collects);

  std::ofstream out;
  out.open("grahp.txt");
  if (!out.is_open()) {
    std::cout << "failed" << std::endl;
    return;
  }
  for (const auto &row : matrix) {
    for (const auto &col : row) out << col << '\t';
    out << std::endl;
  }
  std::cout << "successed!" << std::endl;
}
void Graph::_display(std::vector<std::vector<string>> &matrix, std::map<Node *, int> &collects) {
  int len = this->nodes.size();
  for (const auto &node : this->nodes) {
    int fromNodeIndex = collects.find(node)->second;
    for (const auto *next : node->nexts) {
      Node *toNode = next->_to;
      int toNodeIndex = collects.find(toNode)->second;
      matrix[fromNodeIndex][toNodeIndex] = "O";
    }
  }
}
Graph::Graph(std::vector<std::vector<std::string>> connects) {
  std::map<std::string, Node *> steps;

  for (const vector<string> &connect : connects) {
    std::string weight = "0", from = connect[0], to = connect[1];
    if (connect.size() > 2) weight = connect[2];
    if (steps.find(from) == steps.end()) {
      Node *node = new Node(from);
      steps.insert({from, node});
      this->nodes.insert(node);
    }
    if (steps.find(to) == steps.end()) {
      Node *node = new Node(to);
      steps.insert({to, node});
      this->nodes.insert(node);
    }
    Node *fNode = steps.find(from)->second;
    fNode->out++;
    Node *tNode = steps.find(to)->second;
    tNode->in++;
    Edge *nEdge = new Edge(fNode, tNode, stoi(weight));
    fNode->edges.push_back(nEdge);
    fNode->nexts.push_back(nEdge);
    tNode->edges.push_back(nEdge);
    this->edges.insert(nEdge);
  }
}

vector<Edge *> Graph::_kruskal() { UnionFindSet sset() return res; }

void Graph::krusal() {
  vector<Edge *> res = this->_kruskal();
  std::ofstream out;
  out.open("./krusal.txt");
  if (!out.is_open()) return;
  out << "from" << '\t' << "to" << '\t' << "weight";
  for (const auto &edge : res) {
    out << edge->_from << '\t' << edge->_to << '\t' << edge->_weight << std::endl;
  }
  std::cout << "krusal successed" << std::endl;
}

int main() {
  using namespace std;
  vector<vector<string>> connects = {{"A", "C", "3"}, {"C", "A", "3"}, {"A", "B", "10"}, {"B", "A", "10"}, {"A", "D", "5"}, {"D", "A", "5"}, {"B", "C", "4"},   {"C", "B", "4"},
                                     {"D", "C", "2"}, {"C", "D", "2"}, {"D", "E", "6"},  {"E", "D", "6"},  {"B", "D", "1"}, {"D", "B", "1"}, {"B", "E", "100"}, {"E", "B", "100"}};

  Graph *graph = new Graph(connects);
  graph->display();
  graph->krusal();
}
