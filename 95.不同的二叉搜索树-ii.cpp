/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 */
#include "commom.hpp"
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 private:
  vector<TreeNode*> res;

 public:
  vector<TreeNode*> generateTrees(int n) {
    if (n == 0) {
      return res;
    }

    return dfs(1, n);
  }
  vector<TreeNode*> dfs(int l, int r) {
    vector<TreeNode*> res;
    if (l > r) {
      return {nullptr};
    }
    for (size_t mid = l; mid <= r; mid++) {
      auto left_res = dfs(l, mid - 1);
      auto right_res = dfs(mid + 1, r);
      for (auto&& left : left_res) {
        for (auto&& right : right_res) {
          auto root = new TreeNode(mid);
          root->left = left;
          root->right = right;
          res.push_back(root);
        }
      }
    }
    return res;
  }
};
// @lc code=end
