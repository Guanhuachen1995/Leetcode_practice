/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0)
		    return null;
        return mergeKLists(lists, 0, lists.length - 1);
    }
    
    private ListNode mergeKLists(ListNode[] lists, int start, int end) {
	    if (start == end) {
		    return lists[start];
	    } else if (start < end){
		    int mid = (end - start) / 2 + start;
		    ListNode left = mergeKLists(lists, start, mid);
		    ListNode right = mergeKLists(lists, mid + 1, end);
		    return mergeTwoLists(left, right);
	    } else {
		    return null;
	    }
}
    
    public ListNode mergeTwoLists(ListNode l1, ListNode l2)
    {
        ListNode res = new ListNode(0);
        ListNode tem = res;
        while(l1 != null && l2 != null)
        {
            if(l1.val < l2.val)
            {
                tem.next = l1;
                l1 = l1.next;
            }
            else
            {
                tem.next = l2;
                l2 = l2.next;
            }
                tem = tem.next;
        }
        if(l1 != null)
            tem.next = l1;
        if(l2 != null)
            tem.next = l2;
        return res.next;
    }
}
