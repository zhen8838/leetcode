/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int findNumberOfLIS(vector<int>& nums) {
    if (nums.size() < 2) {
      return nums.size();
    }
    map<int, int> d;
    int tmp;
    vector<int> len(nums.size(), 1);
    vector<int> cnt(nums.size(), 1);
    int maxans = 0;
    for (size_t i = 1; i < nums.size(); i++) {
      for (size_t j = 0; j < i; j++) {
        if (nums[i] > nums[j]) {
          // 大于nums[j]也就是说可以追加
          int tmp = max(len[j] + 1, len[i]);
          if (len[i] != tmp) {
            // 如果第一次出现,那么当前的子序列数量就是和之前保持不变
            len[i] = tmp;
            cnt[i] = cnt[j];
          } else if (len[j] + 1 == len[i]) {
            // 如果第二次出现,我们需要把之前的cnt数量累加到当前
            // NOTE 这里最需要注意的就是,之前必须要比现在小1,也就是说当前值加上之前那个值到达了最大长度,也就是必走之前那个路径,所以加上之前的路径.
            cnt[i] += cnt[j];
          }
        }
      }
      maxans = max(len[i], maxans);
      // ic(maxans, len, cnt);
    }
    int ans = 0;
    for (size_t i = 0; i < nums.size(); i++) {
      if (maxans == len[i]) {
        ans += cnt[i];
      }
    }
    return ans;
  }
};
// @lc code=end
int main(int argc, char const* argv[]) {
  vector<int> nums{1, 2, 3, 1, 2, 3, 1, 2, 3};
  Solution s;
  ic(s.findNumberOfLIS(nums));

  return 0;
}
