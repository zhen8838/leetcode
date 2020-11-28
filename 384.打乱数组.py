#
# @lc app=leetcode.cn id=384 lang=python3
#
# [384] 打乱数组
#
from common import *
# @lc code=start


class Solution:

    def __init__(self, nums: List[int]):
        self.nums = nums
        self._nums = nums.copy()

    def reset(self) -> List[int]:
        """
        Resets the array to its original configuration and return it.
        """
        if hasattr(self, 'idxs'):
            self.nums[:] = self._nums[:]
        return self.nums

    def shuffle(self) -> List[int]:
        """
        Returns a random shuffling of the array.
        """
        import random
        if not hasattr(self, 'idxs'):
            l = list(range(len(self.nums)))
            random.shuffle(l)
            self.idxs = l
        else:
            random.shuffle(self.idxs)

        self.nums[:] = [self.nums[i] for i in self.idxs]
        return self.nums


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
# @lc code=end
if __name__ == "__main__":
    nums = [1, 2, 3]
    obj = Solution(nums)
    obj.shuffle()
    print(nums)
    obj.reset()
    print(nums)
    obj.shuffle()
    print(nums)
    obj.reset()
    print(nums)
    obj.shuffle()
    print(nums)
    obj.reset()
    print(nums)
    obj.shuffle()
    print(nums)
