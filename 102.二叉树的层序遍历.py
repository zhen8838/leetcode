#
# @lc app=leetcode.cn id=102 lang=python3
#
# [102] 二叉树的层序遍历
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
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        l: List[TreeNode] = []
        out = []
        if root == None:
            return out
        l.append(root)
        while len(l) > 0:
            t = []
            for _ in range(len(l)):
                node = l.pop(0)
                t.append(node.val)
                if node.left:
                    l.append(node.left)
                if node.right:
                    l.append(node.right)
            out.append(t)

        return out
# @lc code=end


if __name__ == "__main__":
    l = [3, 9, 20, None, None, 15, 7]
    root = build_tree(l)
    s = Solution()
    print(s.levelOrder(root))
