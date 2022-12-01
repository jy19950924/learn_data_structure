#include "graph.h"
#include <algorithm>
#include <fstream>
#include <iterator>
#include <queue>
#include <string>

Edge::Edge(Node *from, Node *to, int weight) {
  this->_from = from;
  this->_weight = weight;
  this->_to = to;
}

void Graph::display() {

  std::map<Node *, int> collects;
  int idx = 0;
  for (const auto &node : nodes)
    collects.insert({node, idx++});

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
    for (const auto &col : row)
      out << col << '\t';
    out << std::endl;
  }
  std::cout << "successed!" << std::endl;
}
void Graph::_display(std::vector<std::vector<string>> &matrix,
                     std::map<Node *, int> &collects) {
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

bool Graph::_hasCircle(Node *from, Node *to) { return false; }
void Graph::kruskal(Node *head) {
  std::set<Node *> records;
  std::priority_queue<Node *, >
}
Graph::Graph(std::vector<std::vector<std::string>> connects) {
  std::map<std::string, Node *> steps;

  for (const vector<string> &connect : connects) {
    std::string weight = "0", from = connect[0], to = connect[1];
    if (connect.size() > 2)
      weight = connect[2];
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

int main() {
  using namespace std;
  vector<vector<string>> connects = {
      {"A", "C"}, {"C", "A"}, {"A", "B"}, {"B", "A"}, {"A", "D"},
      {"D", "A"}, {"B", "C"}, {"C", "B"}, {"D", "C"}, {"C", "D"},
      {"C", "E"}, {"E", "C"}, {"D", "E"}, {"E", "D"}};

  Graph *graph = new Graph(connects);
  graph->display();
}
