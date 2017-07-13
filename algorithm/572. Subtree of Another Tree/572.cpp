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
    bool isSubtree(TreeNode* s, TreeNode* t)
    {
        if(s==NULL && t==NULL)
            return 1;
        if(t==NULL)
            return 1;
        if(s==NULL)
            return 0;
        
        return helper(s,t) || isSubtree(s->left,t) ||isSubtree(s->right,t);
    }
    bool helper(TreeNode* s, TreeNode* t) {
        if(s==NULL && t==NULL)
            return 1;
        else if(s && t)
        {
            if(s->val != t->val)
                return 0;
            return helper( s->left, t->left) && helper(s->right, t->right);
        }
        else
            return 0;
    }
};
