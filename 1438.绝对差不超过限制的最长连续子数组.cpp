/*
 * @lc app=leetcode.cn id=1438 lang=cpp
 *
 * [1438] 绝对差不超过限制的最长连续子数组
 */

// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
      multiset<int> s;
      int ans=0;
      for(int l=0,r=0; r<nums.size(); r++){
        s.insert(nums[r]);
        while(abs(*s.begin()-*s.rbegin())>limit){
          s.erase(s.find(nums[l++]));
        }
        ans=max(ans,r-l+1);
      }
      return ans;
    }
};
// @lc code=end

