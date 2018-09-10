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
        int lastval = INT_MIN, count = -1, maxcount = 0;
        vector<int> res;
        inorder(root, lastval, count, maxcount, res);
        if(count > maxcount) {
            res.clear();
            res.push_back(lastval);
            maxcount = count;
        } else if(count == maxcount) {
            res.push_back(lastval);
        }
        return res;
    }
    
    void inorder(TreeNode* root, int& lastval, int& count, int& maxcount, vector<int>& res) {
        if(!root)   return;
        inorder(root->left, lastval,count, maxcount,res);
        if(root->val == lastval) {
            count++;
        } else {
            if(count > maxcount) {
                res.clear();
                res.push_back(lastval);
                maxcount = count;
            } else if(count == maxcount) {
                res.push_back(lastval);
            }
            count = 1;
            lastval = root->val;
        }
        inorder(root->right, lastval,count, maxcount,res);
    }
};
