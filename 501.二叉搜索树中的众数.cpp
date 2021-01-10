/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
  int base, maxcount = 0, count = 0;
  vector<int> ans;

 public:
  vector<int> findMode(TreeNode* root) {
    TreeNode *cur = root, *pre = nullptr;

    while (cur) {
      if (!cur->left) {
        update(cur->val);
        // ic(cur->val);
        cur = cur->right;
        continue;
      }
      pre = cur->left;
      while (pre->right && pre->right != cur) {
        pre = pre->right;
      }
      if (!pre->right) {
        pre->right = cur;
        cur = cur->left;
      } else {
        pre->right = nullptr;
        update(cur->val);
        // ic(cur->val);
        cur = cur->right;
      }
    }
    return ans;
  }
  void update(int val) {
    if (count == 0) {
      base = val;
    }
    if (base == val) {
      count++;
    } else {
      base = val;
      count = 1;
    }
    // cout << count << val << endl;
    if (count > maxcount) {
      maxcount = count;
      ans.clear();
      ans.push_back(val);
    } else if (count == maxcount) {
      ans.push_back(val);
    }
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums{4, 2, 6, 1, 3, 5, 7};
  auto root = vector2tree(nums);
  s.findMode(root);
  return 0;
}
