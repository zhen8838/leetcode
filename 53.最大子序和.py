#
# @lc app=leetcode.cn id=53 lang=python3
#
# [53] 最大子序和
#
from common import *
# @lc code=start


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        elif len(nums) == 1:
            return nums[0]

        max_n = float("-inf")
        sum = 0
        for n in nums:
            if sum + n > max_n:
                max_n = sum + n
            if sum + n >= 0:
                sum += n
            else:
                sum = 0

        return max_n
# @lc code=end


if __name__ == "__main__":
    s = Solution()
    print(s.maxSubArray([-2, -1]))
