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
    int widthOfBinaryTree(TreeNode* root) {
        vector<int> lefts;
        return helper(root, 1, 0, lefts);
    }
private:
    
    int helper(TreeNode* root, int index, int level,vector<int>& lefts) {
        if(!root)   return 0;
        if(level == lefts.size())
            lefts.push_back(index);
        return max({index - lefts[level] + 1, helper(root->left, index * 2, level + 1, lefts), helper(root->right, index * 2 + 1, level + 1, lefts)});
    }
};
