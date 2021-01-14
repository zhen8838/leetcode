/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
#include <numeric>

#include "commom.hpp"
// @lc code=start
class Solution {
 private:
  vector<vector<int>> ans;

 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<int> track;
    sort(nums.begin(), nums.end(), less<int>());
    dfs(nums, track, 0, 0, target);
    return ans;
  }
  void dfs(vector<int>& nums, vector<int>& track, int pos, int sum,
           int target) {
    if (track.size() == 4 and sum == target) {
      ans.push_back(track);
      return;
    }
    for (size_t i = pos; i < nums.size(); i++) {
      if ((nums.size() - i) < (4 - track.size())) {
        // 如果剩余元素不足,剪枝
        return;
      }
      if (i > pos and nums[i - 1] == nums[i]) {
        // 去除重复节点,剪枝
        continue;
      }
      if (i < nums.size() - 1 and
          (sum + nums[i] + int(3 - track.size()) * nums[i + 1]) > target) {
        // 如果当前这个数加上去之后,
        return;
      }
      if (i < nums.size() - 1 and
          (sum + nums[i] + int(3 - track.size()) * nums.back()) < target) {
        // 如果当前这个数加上去之后,
        continue;
      }

      track.push_back(nums[i]);
      dfs(nums, track, i + 1, sum + nums[i], target);
      track.pop_back();
    }
  }
};
// class Solution {
//  private:
//   vector<vector<int>> ans;
//   vector<int> myNums, subans;
//   int tar, numSize;
//   void DFS(int low, int sum) {
//     if (sum == tar && subans.size() == 4) {
//       ans.emplace_back(subans);
//       return;
//     }
//     for (int i = low; i < numSize; ++i) {
//       if (numSize - i < int(4 - subans.size()))  //剪枝
//         return;
//       if (i > low && myNums[i] == myNums[i - 1])  //去重
//         continue;
//       if (i < numSize - 1 &&
//           sum + myNums[i] + int(3 - subans.size()) * myNums[i + 1] >
//               tar)  //剪枝
//         return;
//       if (i < numSize - 1 &&
//           sum + myNums[i] + int(3 - subans.size()) * myNums[numSize - 1] <
//               tar)  //剪枝
//         continue;
//       subans.emplace_back(myNums[i]);
//       DFS(i + 1, myNums[i] + sum);
//       subans.pop_back();
//     }
//     return;
//   }

//  public:
//   vector<vector<int>> fourSum(vector<int>& nums, int target) {
//     sort(nums.begin(), nums.end());
//     myNums = nums;
//     tar = target;
//     numSize = nums.size();
//     if (numSize < 4) return ans;
//     DFS(0, 0);
//     return ans;
//   }
// };

// @lc code=end

int main(int argc, char const* argv[]) {
  Vec<int> v{1, 0, -1, 0, -2, 2};
  Solution s;
  ic(s.fourSum(v, 0));
  return 0;
}
