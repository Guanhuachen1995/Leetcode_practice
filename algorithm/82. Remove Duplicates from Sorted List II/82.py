# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        tem1=tem=ListNode(0)
        tem.next=head
        while head:
            if head.next and head.val==head.next.val:
                while head.next and head.val==head.next.val:
                    head=head.next
                head=head.next
                tem1.next=head
            else:
                head=head.next
                tem1=tem1.next
        return tem.next
        
