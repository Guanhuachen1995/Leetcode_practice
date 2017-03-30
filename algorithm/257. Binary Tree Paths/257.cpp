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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(!root) return result;
        helper(root,result,"");
        return result;
    }
    void helper(TreeNode* root, vector<string> & result,  string  str )
    {
        if(!root) return;
        if(str=="")
            str+=to_string(root->val);
        else
        {
            str+="->";
            str+=to_string(root->val);
        }
        if(!root->left && !root->right)
        {
            result.push_back(str);
        }
        else
        {
            helper(root->left,result,str);
            helper(root->right,result,str);
        }
    }
};
