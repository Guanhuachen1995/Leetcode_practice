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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int length = lists.size();  
        if (length == 0) {  
          return NULL;  
        } else if(length == 1)  
            return lists[0];  
        else if(length == 2) {  
            return mergeTwoLists(lists[0], lists[1]);  
        }  
        vector<ListNode*> leftHalf(lists.begin(), lists.begin()+length/2);  
        vector<ListNode*> rightHalf(lists.begin()+length/2, lists.end());  
        return mergeTwoLists(mergeKLists(leftHalf), mergeKLists(rightHalf)); 
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head(-1);
        ListNode * tem=&head;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                tem->next=l1;
                l1=l1->next;
            }
            else
            {
                tem->next=l2;
                l2=l2->next;
            }
            tem=tem->next;
        }
        if(l1)
            tem->next=l1;
        if(l2)
            tem->next=l2;
        return head.next;
    }
};
