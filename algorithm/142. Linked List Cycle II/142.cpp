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
    ListNode *detectCycle(ListNode *head) {
        if(!head)   return NULL;
        ListNode *fast = head, *slow = head;
        bool iscycle = 0;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                iscycle = 1;
                break;
            }
        }
        if(!iscycle)    return NULL;
        slow = head;
        while(fast != slow)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};
