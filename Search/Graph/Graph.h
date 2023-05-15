#ifndef GRAPH_H
#define GRAPH_H

#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

#include "./unionFindSet.h"

using std::map;
using std::set;
using std::string;
using std::vector;

struct Edge;
struct Node {
  int in;
  int out;
  std::vector<Edge*> nexts;
  std::vector<Edge*> edges;
  std::string val;

  Node() : Node("") {}
  Node(std::string val) : val(val), in(0), out(0) {}
};

struct Edge {
  Node* _from;
  Node* _to;
  int _weight;

public:
  Edge(Node* from, Node* to, int weight);

  bool operator>(const Edge& edge) { return this->_weight < edge._weight; }
};

class Graph {
  std::set<Node*> nodes;
  std::set<Edge*> edges;

  void _display(vector<vector<string>>&, std::map<Node*, int>&);
  vector<Edge*> _kruskal(vector<string>& nodes);
  vector<Edge*> _prim();
  void _displayTree(string type, vector<Edge*>& edges);
  int _dijkstra(Node* beginPoint, Node* endPoint);
  Node* _getUnselectedMinNode(set<Node*>& passingNode, map<Node*, int>& cost);

public:
  Graph(vector<vector<string>> connects);

  void display();
  void krusal(vector<string> nodes);
  void prim();
  void dijkstra(Node* beginPoint, Node* endPoint);
  set<Node*>& getNodes() { return this->nodes; }
};
struct CompareEdge {
  bool operator()(const Edge* first, const Edge* second) {
    return first->_weight > second->_weight;
  }
};
#endif
