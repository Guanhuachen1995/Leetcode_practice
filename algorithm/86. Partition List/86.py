# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        small,large=ListNode(0),ListNode(0)
        p1,p2=small,large
        while head:
            if head.val <x:
                p1.next=head
                p1=p1.next
            else:
                p2.next=head
                p2=p2.next
            head=head.next
        p1.next=large.next
        p2.next=None
        return small.next
