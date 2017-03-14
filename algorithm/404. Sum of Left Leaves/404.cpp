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
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root,false);
    }
    int helper(TreeNode* root,bool isleft)
    {
        if (!root) return 0;
        if(!root->left && ! root->right)
        {
            if(isleft)
                return root->val;
            else
                return 0;
        }
        return helper(root->left,true) + helper(root->right,false);
    }
};
