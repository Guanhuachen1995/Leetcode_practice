/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode plusOne(ListNode head) {
        ListNode res = new ListNode(0);
        res.next = head;
        ListNode fast = res, slow = res;
        while(fast.next != null) {
            if(fast.next.val != 9) {
                slow = fast.next;
            }
            fast = fast.next;
        }
        slow.val++;
        if(slow.next != null) {
            while(slow.next != null) {
                slow.next.val = 0;
                slow = slow.next;
            }
            
        }
        if(res.val == 1) {
            return res;
        }
        return res.next;
    }
}
