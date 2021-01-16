/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
  vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    if (not root) {
      return res;
    }

    TreeNode* node = root;
    queue<TreeNode*> q;
    q.push(node);
    while (!q.empty()) {
      int n = q.size();
      for (size_t i = 0; i < n; i++) {
        node = q.front(), q.pop();
        // ic(node->val);
        if (node->left) {
          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
      }
      // ic(node->val);
      res.push_back(node->val);
    }
    return res;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> nums = {1, 2, 3, NULL, 5, NULL, 4};
  auto tree = vector2tree(nums);
  Solution s;
  ic(s.rightSideView(tree));
  return 0;
}
