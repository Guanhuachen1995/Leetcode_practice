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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode res(0);
        ListNode *p = &res;
        while(l1 || l2 || carry)
        {
            int tem = (l1?l1->val:0) + (l2?l2->val:0) + carry;
            ListNode* node = new ListNode(tem%10);
            p->next = node;
            p = p->next;
            carry = tem / 10;
            l1 = l1?l1->next:l1;
            l2 = l2?l2->next:l2;
        }
        return res.next;
    }
};
