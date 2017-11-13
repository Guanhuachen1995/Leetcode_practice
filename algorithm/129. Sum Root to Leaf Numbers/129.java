/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    int res = 0;
    public int sumNumbers(TreeNode root) {
        if(root == null)    return 0;
        helper(root, 0);
        return res;
    }
    private void helper(TreeNode root, int sum)
    {
        if(root.left == null && root.right == null)
        {
            res += sum*10 + root.val;
            return;
        }
        if(root.left == null) helper(root.right,  sum*10 + root.val);
        else if(root.right == null)  helper(root.left, sum*10 + root.val);
        else
        {
            helper(root.right,  sum*10 + root.val);
            helper(root.left,  sum*10 + root.val);
        }
    }
}
