/*
 * @lc app=leetcode.cn id=679 lang=cpp
 *
 * [679] 24 点游戏
 */
#include <functional>
#include <unordered_map>

#include "commom.hpp"
// @lc code=start
class Solution {
 private:
  bool res = false;

 public:
  bool judgePoint24(vector<int>& nums) {
    vector<double> dnums(nums.begin(), nums.end());
    map<int, function<double(double, double)>> umap{
        {0, [](double a, double b) -> double { return a + b; }},
        {1, [](double a, double b) -> double { return a - b; }},
        {2, [](double a, double b) -> double { return a * b; }},
        {3, [](double a, double b) -> double { return a / b; }}};
    dfs(dnums, umap);
    return res;
  }

  void dfs(vector<double>& nums,
           map<int, function<double(double, double)>>& umap) {
    if (res) {
      return;
    }

    if (nums.size() == 1) {
      if (fabs(nums[0] - 24.) < 1e-9) {
        res = true;
      }
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      double a = nums[i];

      nums.erase(nums.begin() + i);
      for (int j = 0; j < nums.size(); j++) {
        double b = nums[j];
        nums.erase(nums.begin() + j);
        for (int k = 0; k < 4; k++) {
          nums.push_back(umap[k](a, b));
          dfs(nums, umap);
          nums.pop_back();
          if (a != b) {
            nums.push_back(umap[k](b, a));
            dfs(nums, umap);
            nums.pop_back();
          }
        }
        nums.insert(nums.begin() + j, b);
      }
      nums.insert(nums.begin() + i, a);
    }
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  Vec<int> nums{3, 3, 8, 8};
  ic(s.judgePoint24(nums));
  double a = 8, b = 3;
  ic((a / (b - (a / b))), 24., (a / (b - (a / b))) == 24.,
     (a / (b - (a / b))) - 24.);
  return 0;
}
