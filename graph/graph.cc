#include "./graph.h"

#include <algorithm>
#include <fstream>
#include <functional>
#include <queue>

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
void Graph::_display(vector<vector<string>> &matrix,
                     map<Node *, int> &collects) {
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

vector<Edge *> Graph::_kruskal(vector<string> &nodes) {
  UnionFindSet::UnionFindSet sset(nodes);
  std::priority_queue<Edge *, vector<Edge *>, CompareEdgeWeight> edgeSet;
  for (auto edge : this->edges) {
    edgeSet.push(edge);
  }
  vector<Edge *> res;
  while (!edgeSet.empty()) {
    Edge *edge = edgeSet.top();
    edgeSet.pop();
    Node *fromNode = edge->_from, *toNode = edge->_to;
    UnionFindSet::Node *fromRoot = sset.Find(fromNode->val);
    UnionFindSet::Node *toRoot = sset.Find(toNode->val);
    if (fromRoot != toRoot) {
      res.push_back(edge);
      sset.Union(fromNode->val, toNode->val);
    }
  }
  return res;
}

void Graph::krusal(vector<string> nodes) {
  vector<Edge *> res = this->_kruskal(nodes);
  this->_displayTree("krusal", res);
}
// prim
void Graph::prim() {
  vector<Edge *> res = this->_prim();
  this->_displayTree("prim", res);
}

void Graph::_displayTree(string type, vector<Edge *> &edges) {
  std::ofstream out;
  string path = type + ".txt";
  out.open(path);
  if (!out.is_open()) {
    std::cout << type << " failed!" << std::endl;
    return;
  }
  out << "F" << '\t' << "T" << '\t' << "W" << std::endl;
  for (const auto &edge : edges) {
    out << edge->_from->val << '\t' << edge->_to->val << '\t' << edge->_weight
        << std::endl;
  }
  std::cout << type << " successed" << std::endl;
}

vector<Edge *> Graph::_prim() {
  std::set<Node *> passingNodes;
  vector<Edge *> selectedEdges;
  std::priority_queue<Edge *, vector<Edge *>, CompareEdgeWeight> unlockedEdges;
  for (const auto node : this->nodes) {
    if (passingNodes.find(node) == passingNodes.end()) {
      passingNodes.insert(node);
      for (const auto edge : node->edges) {
        unlockedEdges.push(edge);
      }
      while (!unlockedEdges.empty()) {
        Edge *minWeightEdge = unlockedEdges.top();
        unlockedEdges.pop();
        Node *toNode = minWeightEdge->_to;
        if (passingNodes.find(toNode) == passingNodes.end()) {
          passingNodes.insert(toNode);
          selectedEdges.push_back(minWeightEdge);
          for (const auto edge : toNode->edges) {
            unlockedEdges.push(edge);
          }
        }
      }
    }
  }
  return selectedEdges;
}
// dijkstra
void Graph::dijkstra(Node *beginPoint, Node *endPoint) {
  vector<Edge *> res = this->_dijkstra(beginPoint, endPoint);
  this->_displayTree("dijkstra", res);
}
vector<Edge *> Graph::_dijkstra(Node *beginPoint, Node *endPoint) {
  std::set<Node *> passingNode;
  std::map<Node *, int> cost;
  vector<Edge *> edges = beginPoint->edges;
  for (const auto edge : edges) {
  }
}

int main() {
  using namespace std;
  vector<string> nodes = {"A", "B", "C", "D", "E"};
  vector<vector<string>> connects = {
      {"A", "C", "3"}, {"C", "A", "3"}, {"A", "B", "10"},  {"B", "A", "10"},
      {"A", "D", "5"}, {"D", "A", "5"}, {"B", "C", "4"},   {"C", "B", "4"},
      {"D", "C", "2"}, {"C", "D", "2"}, {"D", "E", "6"},   {"E", "D", "6"},
      {"B", "D", "1"}, {"D", "B", "1"}, {"B", "E", "100"}, {"E", "B", "100"}};

  Graph *graph = new Graph(connects);
  graph->display();
  graph->krusal(nodes);
  graph->prim();
  return 0;
}
