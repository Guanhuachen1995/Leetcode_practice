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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)   return NULL;
        
        if(root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if(root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            if(!root->left) return root->right;
            if(!root->right)    return root->left;
            TreeNode* temp = findrightmin(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, root->val);
        }
        return root;
    }
    
    TreeNode* findrightmin(TreeNode* root) {
        while(root->left)   root = root->left;
        return root;
    }
};
