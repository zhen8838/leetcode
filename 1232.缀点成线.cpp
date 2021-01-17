/*
 * @lc app=leetcode.cn id=1232 lang=cpp
 *
 * [1232] 缀点成线
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  bool checkStraightLine(vector<vector<int>>& coordinates) {
    int dx = coordinates[1][0] - coordinates[0][0],
        dy = coordinates[1][1] - coordinates[0][1];
    float k = dx == 0 ? abs((float)dy / (float)dx) : (float)dy / (float)dx;

    for (size_t i = 2; i < coordinates.size(); i++) {
      int cdx = coordinates[i][0] - coordinates[i - 1][0],
          cdy = coordinates[i][1] - coordinates[i - 1][1];
      float ck =
          cdx == 0 ? abs((float)cdy / (float)cdx) : (float)cdy / (float)cdx;
      // ic(k, ck);
      if (ck != k) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Mat<int> coords{{0, 0}, {0, 5}, {0, -5}};
  Solution s;
  ic(s.checkStraightLine(coords));
  return 0;
}
