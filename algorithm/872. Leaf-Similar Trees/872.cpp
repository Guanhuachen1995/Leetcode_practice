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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1,s2;
        helper(root1, s1);
        helper(root2, s2);
        return s1 == s2;
    }
    
    void helper(TreeNode* root, string& s) {
        if(!root)   return;
        if(!root->left && !root->right) s += to_string(root->val)+"_";
        helper(root->left, s);
        helper(root->right, s);
    }
};
