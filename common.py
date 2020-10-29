from binarytree import Node as TreeNode
from typing import List


def build_tree(l: list):
    nl = []
    parent = TreeNode(l.pop(0))
    nl.append(parent)
    while len(l) > 0:
        for i in range(len(nl)):
            nd: TreeNode = nl.pop(0)
            left = l.pop(0)
            if left:
                nd.left = TreeNode(left)
            right = l.pop(0)
            if right:
                nd.right = TreeNode(right)
            nl.append(nd.left)
            nl.append(nd.right)
    return parent
