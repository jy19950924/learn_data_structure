#ifndef GRAPH_H
#define GRAPH_H

#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using std::string;
using std::vector;
struct Edge;
struct Node {
  int in;
  int out;
  std::vector<Edge *> nexts;
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

  void _display(vector<vector<string>> &, std::map<Node *, int> &);
  bool _hasCircle(Node *from, Node *to);

public:
  Graph(vector<vector<string>> connects);

  void display();
  void kruskal(Node *head);
};

#endif
