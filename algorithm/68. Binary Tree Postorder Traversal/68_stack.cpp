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
     * @return: Postorder in ArrayList which contains node values.
     */
    vector<int> postorderTraversal(TreeNode * root) {
        // write your code here
        vector<int> res;
        if(!root)   return res;
        stack<TreeNode*>   st;
        TreeNode *cur =root, *lastVisited = NULL;
        while(cur || !st.empty()) {
            while(cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            if(cur->right == NULL || cur->right == lastVisited) {
                st.pop();
                res.push_back(cur->val);
                lastVisited = cur;
                cur = NULL;
            } else {
                cur = cur->right;
            }
        }
        return res;
    }
};
