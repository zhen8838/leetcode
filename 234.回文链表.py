#
# @lc app=leetcode.cn id=234 lang=python3
#
# [234] 回文链表
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
  def isPalindrome(self, head: ListNode) -> bool:
    if head == None or head.next == None:
      return True
    # 快慢指针，慢指针移动一半的时候，快指针刚好比他多一倍
    slow_head = head
    fast_head = head
    while fast_head != None and fast_head.next != None:
      slow_head = slow_head.next
      fast_head = fast_head.next.next
    # 翻转
    mid = slow_head
    # print_nodelist(mid)
    end = self.reverseList(mid)  # 奇数的时候从下一个开始，中间不用判定
    # print_nodelist(end)

    tend = end
    thead = head
    res = True
    while tend != None:
      if tend.val != thead.val:
        res = False
        break
      tend = tend.next
      thead = thead.next
    mid.next = self.reverseList(end)
    # print_nodelist(head)
    return res

  @staticmethod
  def reverseList(head: ListNode) -> ListNode:
    if head == None:
      return head

    left = None
    right = None
    while head.next:
      right = head.next
      head.next = left
      left = head
      head = right
    head.next = left
    return head


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
  l = init_nodelist([1, 2, 3, 2, 1])
  S = Solution()
  b = S.isPalindrome(l)
  print(b)
  # print_nodelist(h)
