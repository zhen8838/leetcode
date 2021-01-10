/*
 * @lc app=leetcode.cn id=820 lang=cpp
 *
 * [820] 单词的压缩编码
 */

#include "commom.hpp"
// @lc code=start
class CharTree {
 public:
  int count = 1;
  CharTree* child[26];
  CharTree() : count(1) {
    for (size_t i = 0; i < 26; i++) {
      child[i] = nullptr;
    }
  }
  CharTree(int count) : count(count) {
    for (size_t i = 0; i < 26; i++) {
      child[i] = nullptr;
    }
  }
};

class Solution {
  // 利用字典树寻找相同共性
 public:
  int minimumLengthEncoding(vector<string>& words) {
    CharTree* root = new CharTree();
    for (auto&& word : words) {
      putstring(root, word);
    }
    int res = 0;
    for (size_t i = 0; i < 26; i++) {
      res += height(root->child[i]);
    }

    return res;
  }

  int height(CharTree* root) {
    if (root == nullptr) {
      return 0;
    }
    int h = 0;
    for (size_t i = 0; i < 26; i++) {
      h += height(root->child[i]);
    }
    if (h == 0) {
      return root->count;
    }
    return h;
  }
  void putstring(CharTree* root, string& s) {
    CharTree* node = root;
    for (auto p = s.rbegin(); p != s.rend(); p++) {
      if (node->child[*p - 'a'] == nullptr) {
        node->child[*p - 'a'] = new CharTree(node->count + 1);
      }
      node = node->child[*p - 'a'];
      // ic(node->count);
      // ic(*p, node->child[*p - 'a']);
    }
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  vector<string> words{"time", "me", "bell"};
  ic(s.minimumLengthEncoding(words));
  return 0;
}
