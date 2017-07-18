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
    int findTilt(TreeNode* root) {
        if(!root)
            return 0;
        int res = 0;
        helper(root, res);
        return res;
    }
    int helper(TreeNode* root, int & res){
        if(!root)
            return 0;
        int leftsum = helper(root->left, res);
        int rightsum = helper(root->right, res);
        res += abs(rightsum - leftsum);
        return rightsum + leftsum + root->val;
    }
};
