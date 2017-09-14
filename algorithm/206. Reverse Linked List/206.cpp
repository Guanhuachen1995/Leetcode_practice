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
    ListNode* reverseList(ListNode* head) {
        if(!head)   return NULL;
        ListNode *tem = head->next, *tem2;
        head->next = NULL;
        while(tem && tem->next)
        {
            tem2 = tem->next;
            tem->next = head;
            head = tem;
            tem = tem2;
        }
        if(tem)
            tem->next = head;
        else
            return head;
        return tem;
    }
};
