/*
 * @lc app=leetcode.cn id=480 lang=cpp
 *
 * [480] 滑动窗口中位数
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    vector<double> res;
    multiset<int> window(nums.begin(), nums.begin() + k);
    auto pmid = next(window.begin(), (k / 2));
    bool even = ((k % 2) == 0);
    for (int i = k;; i++) {
      double midv =
          even ? ((double)(*pmid) + (double)(*(prev(pmid)))) / 2 : (double)(*pmid);
      res.push_back(midv);
      if (i == nums.size()) {
        break;
      }

      /* NOTE
       * 因为set的底层是红黑树，所以插入元素之后，当前指针指向的数不会改变，需要手动修改值
       */
      window.insert(nums[i]);

      // 如果来了个更小的数，那么指针要减小。
      // ic(string("-----------"));
      // ic(window, *pmid);
      if (nums[i] < *pmid) {
        pmid--;
      }

      // ic(window, *pmid);
      // 如果要删除的数比当前数小
      if (nums[i - k] <= *pmid) {
        pmid++;
      }
      // ic(window, *pmid);
      // 删除对应元素
      window.erase(window.lower_bound(nums[i - k]));
    }
    return res;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  Vec<int> nums{1,4,2,3};
  ic(s.medianSlidingWindow(nums, 4));
  // -1 1  3
  // -3 [-1]  1  3
  // -3 [-1]  1  3
  return 0;
}
