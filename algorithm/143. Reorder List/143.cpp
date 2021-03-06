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
    void reorderList(ListNode* head) {
        if(!head || !head->next)    return;
        
        //find the middle
        ListNode *p1 = head;
        ListNode *p2 = head;
        while(p2->next && p2->next->next)
        {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        
        
        //Reverse the half after middle  1->2->3->4->5->6 to 1->2->3->6->5->4
        
        ListNode *head2 = p1->next;
        p1->next = NULL;
    
        p2 = head2->next;
        head2->next = NULL;
        while (p2) {
            p1 = p2->next;
            p2->next = head2;
            head2 = p2;
            p2 = p1;
        }
        
        
        //Start reorder one by one  1->2->3->6->5->4 to 1->6->2->5->3->4
        
        for (p1 = head, p2 = head2; p1; ) {
            auto t = p1->next;
            p1 = p1->next = p2;
            p2 = t;
        }
    }
};
