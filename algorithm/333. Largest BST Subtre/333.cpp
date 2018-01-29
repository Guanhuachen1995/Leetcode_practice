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
    int largestBSTSubtree(TreeNode* root) {
        int res = 0;
        auto tem1 = count(root,res);
        return res;
    }
    
    vector<int> count(TreeNode *root, int & res)
    {
        if(!root)   return vector<int>{INT_MAX,INT_MIN, 0};
        auto tem1 = count(root->left,res), tem2 = count(root->right,res);
        if(root->val <= tem1[1] || root->val >= tem2[0] )
            return vector<int>{INT_MIN,INT_MAX, 0}; 
    
        int Min =min(root->val, tem1[0]), Max =max(root->val, tem2[1]);  
        res = max(res, tem1[2] + tem2[2] + 1);  
        return vector<int>{ Min , Max,tem1[2] + tem2[2] + 1};  
        
    }
};
