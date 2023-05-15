#ifndef SKIP_LIST_H
#define SKIP_LIST_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

const int MAX_LEVEL = 16;

int GetRandom();

struct Node {
  Node *nexts[MAX_LEVEL];
  int val;
  int level;

  Node() : Node(-1, 0) {}
  Node(int val, int level);
};

class SkipList {
  Node *_head;
  int levelCount;
  int nodeCount;

  Node *_find(int val);
  int _getRandomLevel();

public:
  SkipList() : SkipList(1) {}
  SkipList(const int level);
  void insert(int insert_value);
  void remove(int val);
  void display();
  Node *find(int val);
};

#endif
