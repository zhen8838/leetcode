/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
 public:
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return helper(nums.begin(), nums.end());
  }

  TreeNode* helper(vector<int>::iterator left, vector<int>::iterator right) {
    if (left >= right) {
      return nullptr;
    }
    auto maxval = max_element(left, right);
    TreeNode* root = new TreeNode(*maxval);
    root->left = helper(left, maxval);
    root->right = helper(maxval + 1, right);
    return root;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums{3, 2, 1, 6, 0, 5};
  s.constructMaximumBinaryTree(nums);
  return 0;
}
