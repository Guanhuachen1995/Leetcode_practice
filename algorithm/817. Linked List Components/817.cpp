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
    int numComponents(ListNode* head, vector<int>& G) {
        int res = 0;
        bool now = false;
        
        while(head)
        {
            if(find(G.begin(),G.end(),head->val) != G.end())
            {
                if(now == false)
                {
                    now = true;
                }
            }
            else
            {
                if(now == true)
                {
                    res++;
                    now = false;
                }
            }
            head = head->next;
        }
        
        if(now == true)
            res++;
        return res;
        
    }
};
