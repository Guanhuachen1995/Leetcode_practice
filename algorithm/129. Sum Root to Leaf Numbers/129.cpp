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
    int sumNumbers(TreeNode* root) {
        int res = 0;
        if(!root)   return 0;
        helper(root, res, 0);
        return res;
    }
    void helper(TreeNode* root, int &res, int sum)
    {
        if(!root->right && !root->left)
        {
            res += sum*10 + root->val;
            return;
        }
        if(!root->right)    helper(root->left, res, sum*10+root->val);
        else if(!root->left)     helper(root->right, res, sum*10 + root->val);
        else
        {
            
            helper(root->right, res, sum*10 + root->val);
            helper(root->left, res, sum*10 +root->val);
        }
        
    }
};
