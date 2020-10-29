#
# @lc app=leetcode.cn id=88 lang=python3
#
# [88] 合并两个有序数组
#
from common import *
# @lc code=start


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        # 这个题目的边界条件真的烦
        if len(nums2) < 1:
            return
        i = m - 1
        j = n - 1
        t = m + n - 1
        while t >= 0:
            if i >= 0 and nums1[i] > nums2[j]:
                if t > m - 1:
                    nums1[t], nums1[i] = nums1[i], float('-inf')
                else:
                    nums1[t], nums1[i] = nums1[i], nums1[t]
                i -= 1
            else:
                if t > m - 1:
                    nums1[t], nums2[j] = nums2[j], float('-inf')
                else:
                    nums1[t], nums2[j] = nums2[j], nums1[t]
                j -= 1

            t -= 1


# @lc code=end
if __name__ == "__main__":
    nums1 = [-1, 0, 0, 3, 3, 3, 0, 0, 0]
    m = 6
    nums2 = [1, 2, 2]
    n = 3
    s = Solution()
    s.merge(nums1, m, nums2, n)
    print(nums1)
    # l = [0, -3, 9, -10, None, 5, None]
    # print(build_tree(l))
