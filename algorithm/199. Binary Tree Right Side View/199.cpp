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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        helper(res, 0, root);
        return res;
    }
    
    void helper(vector<int> &res, int level, TreeNode* root)
    {
        if(!root)   return;
        if(res.size() < level + 1)  res.push_back(0);
        res[level]=root->val;
        helper(res, level + 1, root->left);
        helper(res, level + 1, root->right);
    }
};
