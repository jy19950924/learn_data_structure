
#ifndef TRIE_TREE_H
#define TRIE_TREE_H

#include <iostream>
#include <string>

using std::string;

const int MAX_NEXT_SET = 26;

namespace TrieTree {
struct Node {
  int pass;
  int end;
  Node *nexts[MAX_NEXT_SET] = {nullptr};
  Node() : pass(0), end(0) {}
};
class TrieTree {
  Node *_root;

public:
  TrieTree();

  void Insert(string s);

  void Delete();

  int Count(string s);
  int CountPrefixed(string s);
};

} // namespace TrieTree

#endif
