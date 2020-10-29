#
# @lc app=leetcode.cn id=108 lang=python3
#
# [108] 将有序数组转换为二叉搜索树
#
from common import *
# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def build(self, nums, start, end):
        if start > end:
            return None
        mid = (start + end) // 2
        return TreeNode(nums[mid],
                        self.build(nums, start, mid - 1),
                        self.build(nums, mid + 1, end))

    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        if len(nums) < 1:
            return None
        # 去中点构建树，因为是升序排列的，所以直接取中点然后中序遍历即可。
        start = 0
        end = len(nums) - 1
        return self.build(nums, start, end)


# @lc code=end
if __name__ == "__main__":
    l = [-10]
    s = Solution()
    print(s.sortedArrayToBST(l))
    # l = [0, -3, 9, -10, None, 5, None]
    # print(build_tree(l))
