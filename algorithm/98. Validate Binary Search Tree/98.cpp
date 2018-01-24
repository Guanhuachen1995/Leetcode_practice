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
    bool isValidBST(TreeNode* root) {
        int i = 1;
        TreeNode* prev = NULL;
        DFS(prev, root, i);
        return i ==1;
    }
    
    void DFS(TreeNode* &prev, TreeNode* root ,int &i)
    {
        if(!root) return;
        DFS(prev, root->left, i);
        if (prev != NULL && prev->val >= root->val) i = 0;
        prev = root;
        DFS(prev, root->right, i);
        
    }
};
