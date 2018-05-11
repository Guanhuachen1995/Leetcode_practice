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
    ListNode* plusOne(ListNode* head) {
        ListNode* res = new ListNode(0);
        res->next = head;
        ListNode *fast = res, *slow = res; 
        while(fast->next)
        {
            if(fast->next->val != 9)
                slow = fast->next;
            fast = fast->next;
        }
        slow->val++;
        if(slow->next != NULL)
        {
            while(slow->next)
            {
                slow->next->val = 0;
                slow = slow->next;
            }
        }
        if(res->val == 1)
            return res;
        return res->next;
    }
};
