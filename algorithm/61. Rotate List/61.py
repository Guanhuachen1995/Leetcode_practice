# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if(not head):
            return head
        fast=slow=head
        len=1
        while(fast.next):
            fast=fast.next
            len+=1
        fast.next=head
        k%=len
        if k>0:
            for i in range(len-k):
                fast=fast.next
        slow=fast.next
        fast.next=None
        return slow
