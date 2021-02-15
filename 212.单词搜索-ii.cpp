/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */
#include <unordered_map>

#include "commom.hpp"
// @lc code=start
class TrieTree {
 public:
  unordered_map<char, TrieTree*> child;
  bool isend;
  TrieTree() : child(), isend(false) {}
};
class Solution {
 private:
  int w, h;
  vector<string> ans;

 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    h = board.size(), w = board[0].size();
    TrieTree *root = new TrieTree(), *node = nullptr;
    for (auto&& word : words) {
      node = root;
      for (auto&& c : word) {
        if (not node->child.count(c)) { node->child[c] = new TrieTree(); }
        node = node->child[c];
      }
      node->isend = true;
    }
    string s;
    for (int y = 0; y < h; y++) {
      for (int x = 0; x < w; x++) { dfs(board, root, s, x, y); }
    }
    delete root;
    return ans;
  }
  bool dfs(vector<vector<char>>& board, TrieTree* root, string& s, int x,
           int y) {
    if (root->isend) {
      if (not s.empty()) { ans.push_back(s); }
      root->isend = false;
      if (root->child.empty()) { return true; }
    }
    if (not isvalid(x, y)) { return false; }
    if (not root->child.count(board[y][x])) { return false; }
    s.push_back(board[y][x]);
    board[y][x] = '*';
    bool ret = dfs(board, root->child[s.back()], s, x + 1, y);
    ret |= dfs(board, root->child[s.back()], s, x - 1, y);
    ret |= dfs(board, root->child[s.back()], s, x, y + 1);
    ret |= dfs(board, root->child[s.back()], s, x, y - 1);
    if (ret and root->child.size() == 1) {
      //加了一个裁剪多调试了一个小时..
      delete root->child[s.back()];
      root->child.erase(s.back());
    }
    board[y][x] = s.back();
    s.pop_back();
    return ret;
  }

  bool isvalid(int x, int y) { return 0 <= x and x < w and 0 <= y and y < h; }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Mat<char> board{{'o', 'a', 'a', 'n'},
                  {'e', 't', 'a', 'e'},
                  {'i', 'h', 'k', 'r'},
                  {'i', 'f', 'l', 'v'}};
  Vec<string> words{"oath", "pea", "eat", "rain", "hklf", "hf"};
  Solution s;
  ic(s.findWords(board, words));
  return 0;
}
