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
    TreeNode prev;
    int diff = Integer.MAX_VALUE;
    public int getMinimumDifference(TreeNode root) {
        helper(root);
        return diff;
    }
    
    private void helper(TreeNode root) {
        if(root == null)
            return;
        helper(root.left);
        if(prev != null)    diff = Math.min(diff, root.val - prev.val);
        prev = root;
        helper(root.right);
    }
    
}
