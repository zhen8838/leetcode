/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第 K 大元素
 */

// @lc code=start
class KthLargest {
  multiset<int> uset;
  int idx;

 public:
  KthLargest(int k, vector<int>& nums)
      : idx(k), uset(nums.begin(), nums.end()) {
    // 长度为k,又是从大到小排序,那么第一个就是第K大的元素.
    while (uset.size() > idx) {
      uset.erase(uset.begin());
    }
  }

  int add(int val) {
    uset.insert(val);
    if (uset.size() > idx) {
      uset.erase(uset.begin());
    }
    return *uset.begin();
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end
