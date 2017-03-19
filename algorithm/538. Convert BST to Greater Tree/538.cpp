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
    TreeNode* convertBST(TreeNode* root) {
        int plus=0;
        helper(root,plus);
        return root;
    }
    void helper(TreeNode* root, int & plus)
    {
        if(root)
        {
            helper(root->right,plus);
            root->val+=plus;
            plus=root->val;
            helper(root->left,plus);
        }
    }
};
