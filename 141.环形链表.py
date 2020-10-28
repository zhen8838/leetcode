#
# @lc app=leetcode.cn id=141 lang=python3
#
# [141] 环形链表
#

class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next: ListNode = next


# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
  def hasCycle(self, head: ListNode) -> bool:
    if head == None:
      return False

    slow = head
    fast = head.next
    while slow and fast:
      if slow == fast:
        return True
      slow = slow.next
      if fast.next == None:
        return False
      fast = fast.next.next
    return False


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
  l = init_nodelist([3, 2, 0, -4])

  # print_nodelist(l1)
  # print_nodelist(l2)
  # S = Solution()
  # h = S.mergeTwoLists(l1, l2)
  # print_nodelist(h)
