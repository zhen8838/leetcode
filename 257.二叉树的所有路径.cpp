/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */

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
  vector<string> res;
 public:
  vector<string> binaryTreePaths(TreeNode* root) {
    if (not root) return res;
    dfs(root, "");
    return res;
  }
  void dfs(TreeNode* root, string track) {
    track += to_string(root->val);
    if (not root->left and not root->right) {
      res.push_back(track);
      return;
    }
    if (root->left) dfs(root->left, track + "->");
    if (root->right) dfs(root->right, track + "->");
  }
};
// @lc code=end
