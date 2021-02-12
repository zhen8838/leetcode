/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
// @lc code=start
class Solution {
 private:
  vector<vector<int>> res;

 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<int> track;
    dfs(nums, track, 0, nums.size());
    return res;
  }

  void dfs(vector<int>& nums, vector<int>& track, int pos, int n) {
    if (pos == n) {
      res.push_back(track);
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      track.push_back(nums[i]);
      nums.erase(nums.begin() + i);
      dfs(nums, track, pos + 1, n);
      nums.insert(nums.begin() + i, track.back());
      track.pop_back();
    }
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums = {1, 2, 3};
  auto res = s.permute(nums);
  IC(res);
  return 0;
}
