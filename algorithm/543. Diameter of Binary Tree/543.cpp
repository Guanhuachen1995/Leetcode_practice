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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int leftheight=getheight(root->left);
        int rightheight=getheight(root->right);
        
        int subdia=max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right));
        return max(subdia,leftheight+rightheight);
    }
    int getheight(TreeNode* root)
    {
        if (!root)
            return 0;
        return 1+max(getheight(root->left),getheight(root->right));
    }
};
