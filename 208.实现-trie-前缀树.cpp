/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */
#include "commom.hpp"
// @lc code=start
struct NTree {
  char val;
  bool end;
  vector<NTree*> child;
  NTree(char v) : val(v), child(26, nullptr), end(false){};
};

class Trie {
 private:
  NTree* root;

 public:
  /** Initialize your data structure here. */
  Trie() { root = new NTree('?'); }

  /** Inserts a word into the trie. */
  void insert(string word) {
    NTree* node = root;
    for (auto&& c : word) {
      if (not node->child[c - 'a']) {
        node->child[c - 'a'] = new NTree(c);
      }
      node = node->child[c - 'a'];
    }
    node->end = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    NTree* node = root;
    for (auto&& c : word) {
      if (not node->child[c - 'a']) {
        return false;
      }
      node = node->child[c - 'a'];
    }
    return node->end;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    NTree* node = root;
    for (auto&& c : prefix) {
      if (not node->child[c - 'a']) {
        return false;
      }
      node = node->child[c - 'a'];
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
