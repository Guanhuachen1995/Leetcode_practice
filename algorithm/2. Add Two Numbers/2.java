/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        ListNode result = new ListNode(0);
        ListNode p = result;
        while(l1 != null || l2 != null || carry != 0)
        {
            int tem = ((l2 == null) ? 0 : l2.val) + ((l1 == null) ? 0 : l1.val) + carry;
            ListNode node = new ListNode(tem%10);
            p.next = node;
            p = p.next;
            carry = tem/10;
            l1 = (l1 == null)?l1:l1.next;
            l2 = (l2 == null)?l2:l2.next;
        }
        return result.next;
    }
}
