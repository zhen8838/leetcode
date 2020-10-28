#
# @lc app=leetcode.cn id=98 lang=python3
#
# [98] 验证二叉搜索树
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
  last = float('-inf')

  def isValidBST(self, root: TreeNode) -> bool:
    # 递归不行，无法得知其他节点信息
    # if root is None:
    #   return True
    # if root.right is None and root.left is None:
    #   return True
    # if (root.right is not None) and (root.left is not None):
    #   if root.left.val < root.val and root.val < root.right.val:
    #     return (True and self.isValidBST(root.left) and self.isValidBST(root.right))
    #   else:
    #     return (False and self.isValidBST(root.left) and self.isValidBST(root.right))
    # elif root.right:
    #   return root.val < root.right.val
    # else:
    #   return root.left.val < root.val
    if root is None:
      return True

    if not self.isValidBST(root.left):
      return False

    if root.val <= self.last:
      return False

    self.last = root.val

    return self.isValidBST(root.right)


    # l = []
    # l.append(root)
    # while len(l):
    #   for i in range(len(l)):
    #     x = l.pop(0)
# @lc code=end
if __name__ == "__main__":
  tree = build_tree([10, 5, 15, None, None, 6, 20])
  print(tree)
  S = Solution()
  b = S.isValidBST(tree)
  print(b)
