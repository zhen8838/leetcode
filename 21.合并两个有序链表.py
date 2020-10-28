#
# @lc app=leetcode.cn id=21 lang=python3
#
# [21] 合并两个有序链表
#
class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next: ListNode = next


# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
  def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
    if l1 == None and l2 == None:
      return None
    pre_head = ListNode(-1)
    thead = pre_head
    while l1 != None or l2 != None:
      if l1 != None and l2 != None:
        if l1.val <= l2.val:
          thead.next = l1
          l1 = l1.next
        else:
          thead.next = l2
          l2 = l2.next
      elif l1 != None:
        thead.next = l1
        l1 = l1.next
      elif l2 != None:
        thead.next = l2
        l2 = l2.next
      thead = thead.next
    return pre_head.next

# @lc code=end


def init_nodelist(l: list):
  l1 = ListNode(l[0])
  tmp = l1
  for i in l[1:]:
    tmp.next = ListNode(i)
    tmp = tmp.next
  return l1


def print_nodelist(head: ListNode):
  vs = []
  while head != None:
    vs.append(str(head.val))
    head = head.next
  print('->'.join(vs))


if __name__ == "__main__":
  l1 = init_nodelist([1, 2, 4])
  l2 = init_nodelist([1, 3, 4])
  # print_nodelist(l1)
  # print_nodelist(l2)
  S = Solution()
  h = S.mergeTwoLists(l1, l2)
  print_nodelist(h)
