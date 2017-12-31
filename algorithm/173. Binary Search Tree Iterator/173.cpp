/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    stack<TreeNode *> st;
public:
    BSTIterator(TreeNode *root) {
        left(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(st.empty())  return false;
        return true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *tem = st.top();
        st.pop();
        if(tem->right)
            left(tem->right);
        return tem->val;
    }
    
    
    void left(TreeNode *root)
    {
        while(root)
        {
            st.push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
