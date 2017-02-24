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
    bool isSymmetric(TreeNode* root) {
        if(!root) return 1;
        return helper(root->left, root->right);
    }
    
    bool helper(TreeNode* left1, TreeNode * right1)
    {
        if(!left1 &&  !right1)    return true;
        else if(!left1 || !right1) return false;
        else if(left1->val != right1->val) return false;
        
        return helper(left1->left,right1->right)&&helper(left1->right,right1->left);
    }
};
