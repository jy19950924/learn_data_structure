#include "skipList.h"
#include <ctime>
#include <fstream>
#include <ios>
#include <random>

// Node
Node::Node(int val, int level) {
  this->val = val;
  this->level = level;
  for (auto &next : nexts)
    next = nullptr;
}
// SkipList
Node *SkipList::_find(int val) {
  Node *cur = this->_head;
  for (int level = this->levelCount - 1; level >= 0; level--) {

    while (cur && cur->nexts[level] && cur->nexts[level]->val < val) {
      cur = cur->nexts[level];
    }
  }
  return cur;
}

Node *SkipList::find(int val) {
  Node *prev = this->_find(val);
  if (prev->nexts[0] && prev->nexts[0]->val == val) {
    return prev->nexts[0];
  }
  return nullptr;
}

SkipList::SkipList(const int level) {
  this->levelCount = level;
  this->nodeCount = 0;
  this->_head = new Node();
}

int GetRandom() {
  static int _count = 1;
  std::default_random_engine generator(time(0) + _count);
  std::uniform_int_distribution<int> distribution(1, 99999 /*0x7FFFFFFF*/);
  int dice_roll = distribution(generator);
  _count += 100;
  return dice_roll;
}
int SkipList::_getRandomLevel() {
  int level = 1;
  for (int i = 1; i < MAX_LEVEL; ++i) {
    if (1 == (GetRandom() % 3)) {
      level++;
    }
  }
  return level;
}

void SkipList::insert(int val) {
  int level = this->_getRandomLevel();
  this->levelCount = level > this->levelCount ? level : this->levelCount;
  Node *node = new Node(val, level);
  if (!node)
    return;
  this->nodeCount++;
  Node *cur = this->_head;

  for (int t_level = this->levelCount - 1; t_level >= 0; t_level--) {
    while (cur && cur->nexts[t_level] && cur->nexts[t_level]->val < val) {
      cur = cur->nexts[t_level];
    }
    if (t_level < level) {
      Node *next = cur->nexts[t_level];
      cur->nexts[t_level] = node;
      node->nexts[t_level] = next;
    }
  }
}

void SkipList::display() {
  using namespace std;
  vector<vector<string>> nums(levelCount, vector<string>(nodeCount, "\t"));
  Node *cur = this->_head->nexts[0];
  int nodeIndex = 0;
  while (cur && nodeIndex < this->nodeCount) {
    int curNodeLevel = cur->level;
    for (int t_level = 0; t_level < curNodeLevel; t_level++) {
      nums[t_level][nodeIndex] = to_string(cur->val) + '\t';
    }
    nodeIndex++;
    cur = cur->nexts[0];
  }
  ofstream out;
  out.open("out.txt");
  if (!out.is_open()) {
    cout << "failed!" << endl;
    return;
  }
  for (const auto &words : nums) {
    for (const auto &word : words)
      out << word;
    out << endl;
  }
  cout << "success!" << endl;
}

void SkipList::remove(int val) {}

int main() {
  using namespace std;
  SkipList sset;
  for (int i = 0; i < 50; i++) {
    sset.insert(i);
  }
  sset.display();
  return 0;
}
