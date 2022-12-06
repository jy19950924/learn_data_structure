
#include "trieTree.h"

TrieTree::TrieTree::TrieTree() { this->_root = new Node(); }

void TrieTree::TrieTree::Insert(string s) {
  Node *cur = this->_root;
  const char *p = s.c_str();
  int s_len = strlen(p);
  for (int i = 0; i < s_len; i++) {
    cur->pass++;
    int index = p[i]-'a';
    if(!cur->nexts[index]){
      cur->nexts[index] = new Node();
    }
    cur = cur->nexts[index];
  }
  cur->end ++;
}
