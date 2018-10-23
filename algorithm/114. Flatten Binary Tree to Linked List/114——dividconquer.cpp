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
    void flatten(TreeNode* root) {
        DFS(root);
    }
    
    TreeNode* DFS(TreeNode* root) {
        if(root== NULL) return NULL;
        
        TreeNode *leftlast = DFS(root->left);
        TreeNode *rightlast = DFS(root->right);
        
        if(leftlast) {
            leftlast->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        
        if(rightlast)   return rightlast;
        if(leftlast)    return leftlast;
        return root;
    }
};
