/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int size = 0;
        ListNode* tem = head;
        while(tem)
        {
            size++;
            tem = tem -> next;
        }
        
        return helper(head, size);
    }
    
    TreeNode* helper(ListNode* head, int size)
    {
        if(size == 0)   return NULL;
        int mid = size/2;
        ListNode* tem = head;
        while(mid > 0)
        {
            head = head->next;
            mid--;
        }
        
        TreeNode* Node = new TreeNode(head->val);
        Node->left = helper(tem, size/2);
        Node->right = helper(head->next,size - size/2 - 1);
        return Node;
    }
};
