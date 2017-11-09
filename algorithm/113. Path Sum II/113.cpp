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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> tem;
        helper(root,sum,res,tem);
        return res;
    }
    
    void helper(TreeNode* root, int sum, vector<vector<int>>& res, vector<int> tem) {
        if(!root) return;
        if(root->val==sum && !root->left && !root->right) 
        {
            tem.push_back(root->val);
            res.push_back(tem);
            return;
        }
        tem.push_back(root->val);
        helper(root->left, sum-root->val,res,tem);
        helper(root->right, sum-root->val,res,tem);
    }
};
