#ifndef GRAPH_H
#define GRAPH_H

#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <vector>

struct Edge;
struct Node {
  int in;
  int out;
  // std::vector<Edge *> nexts; // no-direct
  std::vector<Edge *> edges;
  std::string val;

  Node(std::string val) : val(val), in(0), out(0) {}
};

struct Edge {
  Node *_from;
  Node *_to;
  int _weight;

public:
  Edge(Node *from, Node *to, int weight);
};

class Graph {
  std::set<Node *> nodes; // int:value
  std::set<Edge *> edges; // int:weight

  void _display(std::vector<std::vector<std::string>> &matrix);

public:
  Graph() = default;
  Graph(std::map<std::string, std::string> &connects);

  void display();
};

#endif
