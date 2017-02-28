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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode a= ListNode(0);
        a.next=head;
        ListNode* tem=&a;
        while(tem && tem->next)
        {
            while(tem->next && tem->next->val==val)
            {
                tem->next=tem->next->next;
            }
            tem=tem->next;
        }
        return a.next;
    }
};
