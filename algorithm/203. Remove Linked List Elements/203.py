# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        a=ListNode(0)
        a.next=head
        tem=a
        while tem and tem.next:
            while tem.next and tem.next.val==val:
                tem.next=tem.next.next
            tem=tem.next
        return a.next
