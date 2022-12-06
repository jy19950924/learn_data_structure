
#include "trieTree.h"

TrieTree::TrieTree::TrieTree() { this->_root = new Node(); }

void TrieTree::TrieTree::Insert(string s) {
  Node* cur = this->_root;
  cur->pass++;
  const char* p = s.c_str();
  int s_len = strlen(p);
  for (int i = 0; i < s_len; i++) {
    int index = p[i] - 'a';
    if (!cur->nexts[index]) {
      cur->nexts[index] = new Node();
    }
    cur = cur->nexts[index];
    cur->pass++;
  }
  cur->end++;
}
int TrieTree::TrieTree::Count(string s) {
  const char* p = s.c_str();
  int s_len = strlen(p);
  Node* cur = this._root;

  for (int i = 0; i < s_len; i++) {
    int path = p[i] = 'a';
    if (!cur->nexts[path]) return 0;
    cur = cur->nexts[path];
  }
  return cur->end;
}

void TrieTree::TrieTree::Delete(string s) {
  Node* cur = this->_root;
  const char* p = s.c_str();
  int s_len = strlen(p);
  if (this->Count <= 0) return;

  stack<Node*> deleteNode;
  for (int i = 0; i < s_len; i++) {
    int index = p[i] - 'a';
    if (--cur->nexts[index]->pass == 0) {
      Node* nextNode = cur->nexts[index];
      cur->nexts[index] = nullptr;
      cur = nextNode;
    } else
      cur = cur->nexts[index];
  }
  cur->end--;
  while (!deleteNode.empty()) {
    delete deleteNode.top();
    deleteNode.pop();
  }
}

int TrieTree::TrieTree::CountPrefixed(string s) {
  const char* p = s.c_str();
  int s_len = strlen(p);
  Node* cur = this._root;

  for (int i = 0; i < s_len; i++) {
    int path = p[i] = 'a';
    if (!cur->nexts[path]) return 0;
    cur = cur->nexts[path];
  }
  return cur->pass;
}