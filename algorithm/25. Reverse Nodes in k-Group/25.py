# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        dummy = ListNode(-1)
        dummy.next = head
        
        cur, cur_dummy = head, dummy
        length = 0
        
        while cur:
            next_cur = cur.next
            length = (length + 1) % k
            
            if length == 0:
                next_dummy = cur_dummy.next
                self.reverse(cur_dummy, cur.next)
                cur_dummy = next_dummy
                
            cur = next_cur
            
        return dummy.next
    
    def reverse(self, begin, end):
            first = begin.next
            cur = first.next
            
            while cur != end:
                first.next = cur.next
                cur.next = begin.next
                begin.next = cur
                cur = first.next
