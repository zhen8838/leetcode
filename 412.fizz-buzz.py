#
# @lc app=leetcode.cn id=412 lang=python3
#
# [412] Fizz Buzz
#
from common import *
# @lc code=start


class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        l = []
        for i in range(1, n + 1):
            s = ''
            if i % 3 == 0:
                s += 'Fizz'
            if i % 5 == 0:
                s += 'Buzz'
            if len(s) == 0:
                s += str(i)
            l.append(s)
        return l

# @lc code=end


if __name__ == "__main__":
    pass
