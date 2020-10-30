#
# @lc app=leetcode.cn id=198 lang=python3
#
# [198] 打家劫舍
#
from common import *
# @lc code=start


class Solution:
    def rob(self, nums: List[int]) -> int:
        # 1. 定义子问题，子问题需要是原问题的子集，并且可以通过其他子问题求解
        # 2. 定义递推关系，此处定义为，偷到倒数第二间房子，也就是奇数，或者偷到倒数第三间和最后一间房子。那么也就是偷不偷第i个房子，取决于偷到dp[i-2]+dp[k]与偷到dp[i-1]间的大小关系决定
        # 3. 定义自底向上的dp数组。
        # 4. 优化dp数组，比如这里就只要用三个元素即可
        if len(nums) == 0:
            return 0
        # 因为依赖前面两个状态
        dp = [0] * (len(nums) + 1)
        dp[1] = nums[0]
        for i in range(2, len(nums) + 1):
            dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2])
        return dp[-1]
# @lc code=end


if __name__ == "__main__":
    s = Solution()
    print(s.rob([2, 1, 1, 2]))
