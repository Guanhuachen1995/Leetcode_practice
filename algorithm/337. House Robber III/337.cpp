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
    int rob(TreeNode* root) {
        int l,r;
        return help(root, l ,r);
    }
    
    int help(TreeNode* root, int& l, int& r) {
        if(!root)   return 0;
        int ll= 0, lr = 0, rl = 0, rr = 0;
        l = help(root->left, ll ,lr);
        r = help(root->right, rl, rr);
        
        return max(root->val + ll + lr + rl+rr, l+r);
    }
};
