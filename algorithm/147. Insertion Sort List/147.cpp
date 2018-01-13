/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode res = ListNode(0);
        ListNode *cur = head, *pre = &res, *next = NULL;
        while(cur)
        {
            next = cur->next;
            while(pre->next && pre->next->val < cur->val)
                pre = pre->next;
            
            /* Insert cur -> next after pre.*/
            cur->next = pre->next;
            pre->next = cur;
            
            pre = &res;
            cur = next;
        }
        return res.next;
    }
};
