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
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return helper(root,sum,sum)+pathSum(root->left,sum)+pathSum(root->right,sum) ;
    }
    
    int helper(TreeNode* root, int sum,int nowsum) {
        if(!root) return 0;
        if(root->val==nowsum) return 1+ helper(root->left,sum, nowsum-root->val) + helper(root->right,sum, nowsum-root->val);
        return helper(root->left,sum, nowsum-root->val) + helper(root->right,sum, nowsum-root->val);
    }
};
