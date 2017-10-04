/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head == null || k == 1)  return head;
        ListNode res = new ListNode(0);
        res.next = head;
        int len = 0;
        ListNode pre = res, cur = res, nex;
        while(cur.next != null){
            len++;
            cur = cur.next;
        }
        while(len >= k)
        {
            cur = pre.next;
            nex = cur.next;
            for(int i = 1; i < k; i++)
            {
                cur.next = nex.next;
                nex.next = pre.next;
                pre.next = nex;
                nex = cur.next;
            }
            pre = cur;
            len -= k;
        }
        return res.next;
    }
}
