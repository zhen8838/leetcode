#
# @lc app=leetcode.cn id=104 lang=python3
#
# [104] 二叉树的最大深度
#

# @lc code=start
# Definition for a binary tree node.
from common import *


class Solution:
  def maxDepth(self, root: TreeNode) -> int:
    # 递归
    # if root:
    #   return max(self.maxDepth(root.right), self.maxDepth(root.left)) + 1
    # else:
    #   return 0
    # 层序遍历
    if root == None:
      return 0
    high = 0
    l = []
    l.append(root)
    while len(l) != 0:
      for i in range(len(l)):
        nd: TreeNode = l.pop(0)
        # 这里一定要pop第一个,不然下一个加进来的数据立马被pop了
        if nd.left:
          l.append(nd.left)
        if nd.right:
          l.append(nd.right)
      high += 1
    return high


# @lc code=end
if __name__ == "__main__":
  # r = TreeNode(20, TreeNode(15), TreeNode(7))
  # l = TreeNode(9)
  x = TreeNode(1, TreeNode(2, TreeNode(4)), TreeNode(3, None, TreeNode(5)))
  S = Solution()
  print(S.maxDepth(x))
