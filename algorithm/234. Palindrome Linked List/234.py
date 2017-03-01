# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        fast=slow=head
        rev=None
        while fast and fast.next:
            fast=fast.next.next
            slow,rev,rev.next=slow.next,slow,rev
        if fast:
            slow=slow.next
        while slow and slow.val==rev.val:
            slow=slow.next
            rev=rev.next
        return rev==None
