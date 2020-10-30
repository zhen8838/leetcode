#
# @lc app=leetcode.cn id=70 lang=python3
#
# [70] 爬楼梯
#

# @lc code=start
class Solution:
    def climbStairs(self, n: int) -> int:
        # 每次其实都只要考虑最后一步是跨一个还是两个，那么就是f(x-1)+f(x-2)
        a = 0
        b = 1
        c = 0
        for i in range(n):
            c = a + b
            a = b
            b = c
        return c
# @lc code=end


if __name__ == "__main__":
    s = Solution()
    s.climbStairs(1)
    s.climbStairs(2)
    s.climbStairs(3)
    s.climbStairs(4)
    s.climbStairs(5)
