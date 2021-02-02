/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 */
#include "commom.hpp"
// @lc code=start
struct TrieTree {
  TrieTree* zero;
  TrieTree* one;
  int val;
  TrieTree(int v) : val(v), zero(nullptr), one(nullptr) {}
};

class Solution {
 private:
  vector<int> dp;

 public:
  int findMaximumXOR(vector<int>& nums) {
    dp = vector<int>(33, 0);
    TrieTree* root = new TrieTree(0);
    for (auto&& num : nums) {
      insert(root, num);
    }

    dfs(root, root, 0, 0, 0);
    return dp[32];
  }
  void insert(TrieTree* root, int num) {
    TrieTree* node = root;
    uint mask = 0x80000000;
    for (size_t i = 0; i < 32; i++) {
      if ((num & mask) == 0) {
        if (not node->zero) {
          node->zero = new TrieTree(0);
        }
        node = node->zero;
      } else {
        if (not node->one) {
          node->one = new TrieTree(mask);
        }
        node = node->one;
      }
      mask >>= 1;
    }
  }

  void dfs(TrieTree* maxnd, TrieTree* minnd, int max, int min, int idx) {
    // 因为异或值不一样的位数越多就越大，因此可以使用dfs进行查找。
    if (idx == 33) {
      return;
    }
    if (maxnd == nullptr or minnd == nullptr) {
      return;
    }
    max |= maxnd->val;
    min |= minnd->val;
    if ((max ^ min) < dp[idx]) {  //根据记忆进行剪枝
      return;
    }
    dp[idx] = max ^ min;
    // 存在1对0的情况必进行遍历
    dfs(maxnd->one, minnd->zero, max, min, idx + 1);
    dfs(maxnd->zero, minnd->one, max, min, idx + 1);
    if (not(maxnd->one and minnd->zero) and not(maxnd->zero and minnd->one)) {
      // 如果不存在相对的情况，能执行什么就执行什么
      dfs(maxnd->one ? maxnd->one : maxnd->zero,
          minnd->one ? minnd->one : minnd->zero, max, min, idx + 1);
    }
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Vec<int> nums{3, 10, 5, 25, 2, 8};
  Solution s;
  ic(s.findMaximumXOR(nums));
  return 0;
}
