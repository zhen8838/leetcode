#
# @lc app=leetcode.cn id=101 lang=python3
#
# [101] 对称二叉树
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
  def check(self, left: TreeNode, right: TreeNode):
    if left == right:  # 两个都没有
      return True
    if not left or not right:  # 一个有，一个没有
      return False
    return (left.val == right.val) and self.check(left.left, right.right) and self.check(left.right, right.left)

  def isSymmetric(self, root: TreeNode) -> bool:
    if root == None:
      return True

    return self.check(root.left, root.right)


# @lc code=end


if __name__ == "__main__":
  l = [1, 2, 2, 3, 4, 4, 3]
  root = build_tree(l)
  s = Solution()
  print(s.isSymmetric(root))
