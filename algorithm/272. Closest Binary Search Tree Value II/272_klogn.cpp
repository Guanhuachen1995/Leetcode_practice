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
        stack<TreeNode*>    pred;
        stack<TreeNode*>    succ;
        TreeNode* cur = root;
        while(cur) {
            if(target < cur->val) {
                succ.push(cur);
                cur = cur->left;
            } else {
                pred.push(cur);
                cur = cur->right;
            }
        }
        
        while(k-- > 0) {
            if(succ.empty())
                res.push_back(getpredecessor(pred));
            else if(pred.empty())
                res.push_back(getsuccessor(succ));
            else if(abs(target - succ.top()->val) < abs(target - pred.top()->val))
                res.push_back(getsuccessor(succ));
            else
                res.push_back(getpredecessor(pred));
        }
        return res;
        
        
    }
    
    int getsuccessor(stack<TreeNode*>   &succ) {
        TreeNode*   poped = succ.top();
        succ.pop();
        TreeNode* cur = poped->right;
        while(cur) {
            succ.push(cur);
            cur = cur->left;
        }
        return poped->val;
    }
    
    int getpredecessor(stack<TreeNode*> &pred) {
        TreeNode* poped = pred.top();
        pred.pop();
        TreeNode* cur = poped->left;
        while(cur) {
            pred.push(cur);
            cur = cur->right;
        }
        return poped->val;
    }
};
