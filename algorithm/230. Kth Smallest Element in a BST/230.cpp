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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> resarr;
        inorder(root, resarr);
        return resarr[k-1];
    }
    
    void inorder(TreeNode* root, vector<int>& resarr)
    {
        if(root == NULL)
            return;
        inorder(root->left, resarr);
        resarr.push_back(root->val);
        inorder(root->right, resarr);
    }
};
