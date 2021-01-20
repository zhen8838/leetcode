/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
 public:
  int rob(TreeNode* root) {
    // 层序遍历不太行,需要每个分支单独考虑
    auto res = dfs(root);
    return max(res[0], res[1]);
  }
  vector<int> dfs(TreeNode* root) {
    vector<int> res(2, 0);
    if (not root) {
      return res;
    }
    auto left = dfs(root->left);
    auto right = dfs(root->right);
    // 后序遍历,在子节点数据返回时进行选择;
    //如果偷当前节点,那么子节点选择不能偷;
    res[0] = root->val + left[1] + right[1];
    //如果不偷当前节点,那么当前最大值是子节点中的最大值(当前不偷,子节点可偷可不偷);
    res[1] = max(left[0], left[1]) + max(right[0], right[1]);
    return res;
  }
};
// @lc code=end
