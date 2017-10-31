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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||k==1) return head;
        ListNode res(0);
        res.next = head;
        ListNode *cur = &res, *pre = &res, *nex;
        int len = 0;
        while(cur = cur->next)
            len++;
        while(len >= k)
        {
            cur = pre->next;
            nex = cur->next;
            for(int i = 1; i < k; i++)
            {
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            pre = cur;
            len -= k;
        }
        return res.next;
    }
};
