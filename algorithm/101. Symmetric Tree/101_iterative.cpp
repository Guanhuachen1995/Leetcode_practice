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
    bool isSymmetric(TreeNode* root) {
        if(!root)   return true;
        TreeNode *l, *r;
        queue<TreeNode*>    q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()) {
            l = q.front();q.pop();
            r = q.front();q.pop();
            if(l == NULL && r == NULL)
                continue;
            if(l == NULL || r == NULL)
                return false;
            if(l->val != r->val)
                return false;
            q.push(l->left);
            q.push(r->right);
            q.push(l->right);
            q.push(r->left);
        }
        return true;
    }
};
