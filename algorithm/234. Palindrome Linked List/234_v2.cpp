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
    bool isPalindrome(ListNode* head) {
        if(!head ) return 1;
        ListNode tem(0);
        tem.next = head;
        ListNode *pre, *cur = head, *fast = head, *nex;
        while(fast && fast->next &&fast->next->next)
        {
            
            fast  = fast->next->next;
            nex = cur->next;
            cur->next = nex->next;
            nex->next = tem.next;
            tem.next = nex;
        }
        
        ListNode *rev = tem.next;

        if(!fast->next)    
        {
            rev = rev->next;
            
        }
        cur = cur->next;
        while(cur && cur->val == rev->val)
        {
            cur = cur->next;
            rev = rev->next;
        }
        return !cur;
    }
};
