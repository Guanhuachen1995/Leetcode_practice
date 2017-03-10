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
        ListNode small=ListNode(0), large=ListNode(0);
        ListNode *p1= &small, *p2=&large;
        while(head)
        {
            if(head->val<x)
            {
                p1->next=head;
                p1=p1->next;
            }
            else
            {
                p2=p2->next=head;
            }
            head=head->next;
        }
        p1->next=large.next;
        p2->next=NULL;
        return small.next;
    }
};
