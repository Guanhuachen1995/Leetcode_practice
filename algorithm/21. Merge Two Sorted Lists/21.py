# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        a=ListNode(0)
        tem=a
        while l1 and l2:
            if l1.val<l2.val:
                tem.next=l1
                l1=l1.next
            else:
                tem.next=l2
                l2=l2.next
            tem=tem.next
        if l1:
            tem.next=l1
        if l2:
            tem.next=l2
        return a.next
