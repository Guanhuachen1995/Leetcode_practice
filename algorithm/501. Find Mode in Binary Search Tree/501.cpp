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
    vector<int> findMode(TreeNode* root) {
        map<int,int> m;
        int tem=helper(root,m);
        vector<int> result;
        for(auto i:m)
        {
            if(i.second==tem)
                result.push_back(i.first);
        }
        return result;
    }
    int helper(TreeNode* root, map<int,int> & m )
    {
        if(root)
        {
            m[root->val]++;
        }
        else
            return 0;
        return max(m[root->val],max(helper(root->left,m),helper(root->right,m)));
    }
    
};
