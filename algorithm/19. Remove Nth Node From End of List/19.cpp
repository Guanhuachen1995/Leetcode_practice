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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy{0};
        dummy.next = head;
        ListNode* fast=&dummy;
        ListNode* slow=&dummy;
        for(int i=0; i <n ; i++)
        {
            fast=fast->next;
        }
        while(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* tem=slow->next;
        slow->next=tem->next;
        delete tem;
        return dummy.next;
    }
};
