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
     * @return: Preorder in ArrayList which contains node values.
     */
    vector<int> preorderTraversal(TreeNode * root) {
        // write your code here
        vector<int> res;
        if(!root)   return res;
        stack<TreeNode*>    st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* temp = st.top();
            st.pop();
            res.push_back(temp->val);
            
            if(temp->right) st.push(temp->right);
            if(temp->left)  st.push(temp->left);
        }
        return res;
    }
};
