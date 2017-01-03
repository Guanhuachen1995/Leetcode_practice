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
        ListNode *kp, *start;
        int carry;
        if (l1 || l2)
        {
        	int k=getValueAndMoveNext(l1) + getValueAndMoveNext(l2);
        	if(k<10)
        		carry=0;
        	else
        		carry=1;
        	ListNode * tem = new ListNode(k%10);
        	start = tem;
        	kp=start;
        }
        while (l1!=NULL || l2!=NULL)
        {
        	int k=getValueAndMoveNext(l1) + getValueAndMoveNext(l2)+carry;
        	if(k<10)
        		carry=0;
        	else
        		carry=1;
        	ListNode * tem = new ListNode(k%10);
        	kp->next=tem;
        	kp=tem;
        }
        if(carry>0)
            kp->next = new ListNode(1);
        return start;
    }
    int getValueAndMoveNext(ListNode* &l){
        int x = 0;
        if (l != NULL){
            x = l->val;
            l = l->next;
        }
        return x;
    }
};