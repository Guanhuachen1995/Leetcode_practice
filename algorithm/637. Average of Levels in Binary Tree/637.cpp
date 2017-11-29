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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        vector<int> levsize;
        helper(root,0,levsize,res);
        for(int i =0; i < res.size(); i++)
        {
            res[i] /= levsize[i];
        }
        return res;
    }
    void helper(TreeNode* root, int level, vector<int> &levsize, vector<double> &levsum)
    {
        if(!root)   return;
        if(levsize.size() < level + 1)
        {
            levsize.push_back(1);
            levsum.push_back(root->val);
        }
        else
        {
            levsize[level]++;
            levsum[level] += root->val;
        }
        helper(root->left, level+1, levsize, levsum);
        helper(root->right, level+1, levsize, levsum);
    }
};
