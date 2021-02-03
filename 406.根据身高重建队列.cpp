/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */
// @lc code=start
class Solution {
 public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
      return a[0] > b[0] or (a[0] == b[0] and a[1] < b[1]);
    });
    vector<vector<int>> res;
    for (auto&& p : people) {
      res.insert(res.begin() + p[1], p);
    }
    return res;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<vector<int>> people{{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
  Solution s;
  ic(s.reconstructQueue(people));
  return 0;
}
