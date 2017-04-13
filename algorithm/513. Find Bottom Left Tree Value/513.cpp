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
    int findBottomLeftValue(TreeNode* root) {
        int result,resultdeep=-1;
        helper(root,result,resultdeep,0);
        return result;
    }
    void helper(TreeNode* root, int &result, int & resultdeep, int deep ){
        if(!root) return;
        if(!root->left && !root->right)
        {
            if(deep>resultdeep)
            {
                result = root->val;
                resultdeep=deep;
            }
        }
        helper(root->left,result,resultdeep,1+deep);
        helper(root->right,result,resultdeep,1+deep);
        
    }
};
