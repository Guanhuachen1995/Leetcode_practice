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
    int kthSmallest(TreeNode* root, int &k) {
        stack<TreeNode*>    st;
        while(root) {
            st.push(root);
            root = root->left;
        }
        
        while(k > 0) {
            TreeNode* p = st.top();
            st.pop();
            if(--k == 0)    return p->val;
            p = p->right;
            while(p) {
                st.push(p);
                p = p->left;
            }
        }
        return -1;
    }
};
