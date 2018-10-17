/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Inorder in ArrayList which contains node values.
     */
    vector<int> inorderTraversal(TreeNode * root) {
        // write your code here
        vector<int> res;
        DFS(root, res);
        return res;
    }
    
    void DFS(TreeNode *root, vector<int>  &res) {
        if(!root)   return;
        DFS(root->left, res);
        res.push_back(root->val);
        DFS(root->right, res);
    }
};
