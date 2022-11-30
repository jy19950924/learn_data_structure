#include "graph.h"
#include <fstream>
#include <string>

Edge::Edge(Node *from, Node *to, int weight) {
  this->_from = from;
  this->_weight = weight;
  this->_to = to;
}
Graph::Graph(std::map<std::string, std::string> &connects) {}

void Graph::display() {
  std::ofstream out;
  out.open("grahp.txt");
  if (out.is_open()) {
    std::cout << "failed" << std::endl;
    return;
  }
  size_t len = this->nodes.size();
  std::vector<std::vector<std::string>> matrix(
      len + 1, std::vector<std::string>(len + 1, ""));
  auto iter = this->nodes.cbegin();
  for (int i = 0; i < len; i++) {
    matrix[len][i] = matrix[i][len] = (*iter)->val;
    iter++;
  }
  this->_display(matrix);
  for (const auto &row : matrix) {
    for (const auto &col : row) {
      out << col << '\t';
    }
    out << std::endl;
  }
}
void Graph::_display(std::vector<std::vector<std::string>> &matrix) {
  int len = this->nodes.size();
  for (int i = 0; i < len; i++) {
    auto iter = this->nodes.begin();
    std::advance(iter, i);
    Node *node = *iter;
    this->nodes.find(node);
  }
}

int main() {
  using namespace std;
  map<string, string> connects = {
      {"A", "C"}, {"C", "A"}, {"A", "B"}, {"B", "A"}, {"A", "D"}, {"D", "A"},
      {"B", "C"}, {"C", "B"}, {"B", "D"}, {"D", "B"}, {"D", "C"}, {"C", "D"},
      {"C", "E"}, {"E", "C"}, {"D", "E"}, {"E", "D"}};

  Graph *graph = new Graph(connects);
}
