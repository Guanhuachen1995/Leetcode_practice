/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        if( head == null)   return null;
        if(head.next == null)   return head;
        
        ListNode tem = head.next;
        head.next = swapPairs(tem.next);
        tem.next = head;
        return tem;
    }
}
