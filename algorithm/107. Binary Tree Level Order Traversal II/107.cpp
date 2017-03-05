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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        DFS(root, result, 0);
        reverse(result.begin(), result.end());
        return result;
    }
    void DFS(TreeNode* root, vector<vector<int> > &v, int level)
    {
        if(root==NULL)
            return;
        if (v.empty() || level > (v.size() - 1)) {
		    v.push_back(vector<int>());
	    }
	    v[level].push_back(root->val);
	    DFS(root->left,v,level+1);
	    DFS(root->right,v,level+1);
    }
};
