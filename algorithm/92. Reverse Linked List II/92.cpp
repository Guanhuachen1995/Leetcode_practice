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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head)   return NULL;
        ListNode res(0);
        res.next = head;
        ListNode *pre = &res;
        n -= m;
        while(--m)  pre = pre->next;
        ListNode *cur = pre->next;
        while(n--)
        {
            ListNode* move = cur -> next; 
            cur -> next = move -> next;
            move -> next = pre -> next;
            pre -> next = move;
        }

        return res.next;
    }
};
