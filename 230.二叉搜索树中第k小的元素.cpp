/*
二叉搜索树中第K小的元素 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
// 这题其实就是一个中序遍历的事情，
class Solution {
 private:
  int n = 0, ans = 0;

 public:
  int kthSmallest(TreeNode* root, int k) {
    /* 利用递归加剪枝效果更好 */
    dfs(root, k);
    return ans;
  }
  void dfs(TreeNode* root, int k) {
    if (root == nullptr) {
      return;
    }
    dfs(root->left, k);
    n++;
    if (n == k) {
      ans = root->val;
    } else if (n > k) {
      return;  // 剪枝
    }
    dfs(root->right, k);
  }
  int kthSmallest2(TreeNode* root, int k) {
    /* 迭代法效率低 */
    stack<TreeNode*> l;
    TreeNode* cur = root;
    while (cur || l.size()) {
      while (cur) {
        l.push(cur);
        cur = cur->left;
      }
      cur = l.top();
      l.pop();
      if (--k == 0) {
        return cur->val;
      }
      cur = cur->right;
    }
    return k;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> nums = {5, 3, 6, 2, 4, NULL, NULL, 1};
  auto root = vector2tree(nums);
  Solution s;
  IC(s.kthSmallest(root, 3));
  return 0;
}
