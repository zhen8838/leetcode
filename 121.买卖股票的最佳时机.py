#
# @lc app=leetcode.cn id=121 lang=python3
#
# [121] 买卖股票的最佳时机
#
from common import *
# @lc code=start


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min = float('inf')
        max_profit = 0
        # 找到最小的，然后每天和他做差值
        for i, p in enumerate(prices):
            if p < min:
                min = p
            elif (p - min) > max_profit:
                # max = prices[i]
                # max_i = i
                max_profit = p - min
        return max_profit

# @lc code=end


if __name__ == "__main__":
    s = Solution()
    print(s.maxProfit([7, 1, 5, 3, 6, 4]))
    pass
