/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        res += '{';
        queue<TreeNode*>    q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode * temp = q.front();
            q.pop();
            
            if(temp != NULL) {
                if(temp != root)
                    res += ',';
                res += to_string(temp->val);
                q.push(temp->left);
                q.push(temp->right);
            } else {
                res += ",#";
            }
        }
        
        int i = res.size() - 1;
        while(res[i] == '#' || res[i] == ',')
            i--;
        res = res.substr(0, i + 1);
        return res + '}';
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode ** root = new TreeNode*;
        *root = NULL;
        queue<TreeNode **>   q;
        q.push(root);
        cout<<data;
        for(int i = 1; i < data.size() - 1; i++) {
            if(data[i] == ',' )
                continue;

            TreeNode ** cur = q.front();
            q.pop();
            
            if(data[i] != '#') {
                int tem = 0;
                int minus = 1;
                if(data[i] == '-') {
                    minus = -1;
                    i++;
                }
                while(isdigit(data[i])) {
                    tem = tem*10 + data[i] - '0';
                    i++;
                }
                *cur = new TreeNode(tem * minus);
                q.push(&((*cur) -> left));
                q.push(&((*cur)->right));
            }  else {
                *cur = NULL;
            }
            
        }
        
        return *root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
