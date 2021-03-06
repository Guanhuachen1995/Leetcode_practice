# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        dummy = ListNode(-1)
        dummy.next = head
        slow, fast = dummy, dummy
        
        for i in xrange(n):
            fast = fast.next
            
        while fast.next:
            slow, fast = slow.next, fast.next
            
        slow.next = slow.next.next
        
        return dummy.next
