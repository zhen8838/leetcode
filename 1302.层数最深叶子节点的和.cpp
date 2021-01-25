/*
 * @lc app=leetcode.cn id=1302 lang=cpp
 *
 * [1302] 层数最深叶子节点的和
 */
#include "commom.hpp"
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 private:
  int level;
  int ans;

 public:
  int deepestLeavesSum(TreeNode* root) {
    level = 0;
    ans = 0;
    helper(root, 0);
    return ans;
  }

  void helper(TreeNode* root, int l) {
    if (not root) {
      return;
    }
    if (l > level) {
      ans = 0;
      level = l;
    }
    if (level == l) {
      ans += root->val;
    }
    helper(root->left, l + 1);
    helper(root->right, l + 1);
  }
};
// @lc code=end
