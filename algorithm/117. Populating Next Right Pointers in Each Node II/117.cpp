/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* head = NULL, *tail = NULL;
        TreeLinkNode* cur = root;
        
        while(cur)
        {
            if(cur->left)
            {
                if(tail)    tail = tail->next = cur->left;
                else    head = tail = cur->left;
            }
            
            if(cur->right)
            {
                if(tail != NULL)    tail = tail->next = cur->right;
                else    head = tail = cur->right;
            }
            if(!(cur = cur->next))
            {
                cur = head;
                head = tail = NULL;
            }
        }
    }
};
