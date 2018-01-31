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
    ListNode* partition(ListNode* head, int x) {
        ListNode res(0);
        res.next = head;
        ListNode *fast = &res, *slow = &res;
        while(fast->next && fast->next->val < x)    fast = fast->next;
        slow = fast;
        while(fast->next && slow->next)
        {
            while(fast->next && fast->next->val >= x)   fast = fast->next;
            if(!fast->next) break;
            ListNode *tem = slow->next;
            slow->next = fast->next;
            fast->next = slow->next->next;
            slow->next->next = tem;
            slow = slow->next;
        }
        return res.next;
    }
};
