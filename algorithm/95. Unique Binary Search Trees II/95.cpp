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
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)    return vector<TreeNode*>();
        return helper(1,n);
    }
private:
    vector<TreeNode*> helper(int start, int end) {
        vector<TreeNode*>   list;
        
        if(start > end) {
            list.push_back(NULL);
            return list;
        }
        
        if(start == end) {
            list.push_back(new TreeNode(start));
            return list;
        }
        
        vector<TreeNode*>   left;
        vector<TreeNode*>   right;

        for(int i = start; i <= end; i++) {
            left = helper(start, i-1);
            right = helper(i+1, end);
            
            for(auto lnode:left) {
                for(auto rnode:right) {
                    TreeNode* cur = new TreeNode(i);
                    cur->left = lnode;
                    cur->right = rnode;
                    list.push_back(cur);
                }
            }
        }
        return list;
        
    }
    
};
