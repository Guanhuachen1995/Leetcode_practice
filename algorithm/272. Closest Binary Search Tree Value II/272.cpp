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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        stack<int> pre;
        stack<int> suc;
        
        inorder(root, target, false, pre);
        inorder(root, target, true, suc);
        
        while(k-- > 0) {
            if(pre.empty() && suc.empty())  break;
            else if(pre.empty()) {
                res.push_back(suc.top());
                suc.pop();
            } else if(suc.empty()) {
                res.push_back(pre.top());
                pre.pop();
            } else if(abs(pre.top() - target) < abs(suc.top() - target)) {
                res.push_back(pre.top());
                pre.pop();
            } else {
                res.push_back(suc.top());
                suc.pop();
            }
                
        }
        return res;
    }
    
    void inorder(TreeNode* root, double target, bool reverse, stack<int>& stack) {
        if(!root)   return;
        
        inorder(reverse?root->right:root->left, target,reverse, stack);
        
        if((!reverse && root->val > target) || (reverse && root->val <= target)) return;
        
        stack.push(root->val);
        inorder(reverse?root->left:root->right, target, reverse, stack);
    }
};
