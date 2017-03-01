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
        ListNode* rev=NULL;
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* tem;
        ListNode* tem1;
        while(fast && fast->next)
        {
            fast=fast->next->next;
            tem=rev;
            tem1=slow->next;
            rev=slow;
            rev->next=tem;
            slow=tem1;
        }
        if(fast)
            slow=slow->next;
        while ( rev && rev->val==slow->val)
        {
            rev=rev->next;
            slow=slow->next;
        }
        return rev==NULL;
    }
};
