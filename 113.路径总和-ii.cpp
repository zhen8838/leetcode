/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
  vector<vector<int>> ans;

 public:
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<int> track;
    if (not root) {
      return ans;
    }

    track.push_back(root->val);
    dfs(root, track, root->val, sum);
    return ans;
  }

  void dfs(TreeNode* root, vector<int>& track, int sum, int target) {
    if (sum == target and not root->left and not root->right) {
      ans.push_back(track);
      return;
    }
    if (root->left) {
      track.push_back(root->left->val);
      dfs(root->left, track, sum + root->left->val, target);
      track.pop_back();
    }
    if (root->right) {
      track.push_back(root->right->val);
      dfs(root->right, track, sum + root->right->val, target);
      track.pop_back();
    }
  }
};
// @lc code=end
