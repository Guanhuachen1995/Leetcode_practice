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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0) return head;
        ListNode* fast,*slow;
        int len=1;
        fast=slow=head;
        while(fast->next)
        {
            len++;
            fast=fast->next;
        }
        fast->next=head;
        if(k%=len)
        {
            for(int i=0; i<len-k;i++)
                fast=fast->next;
        }
        slow=fast->next;
        fast->next=NULL;
        return slow;
    }
};
