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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if(root)    helper(root, result, 1);
        return result;
    }
    void helper(TreeNode* root, vector<int> & result, int depth)
    {
        if(depth > result.size()) result.push_back(root->val);
        else
        {
            if(root->val > result[depth-1]) result[depth-1]=root->val;
        }
        
        if(root->left) helper(root->left, result, depth+1);
        if(root->right) helper(root->right, result, depth+1);
    }
};
