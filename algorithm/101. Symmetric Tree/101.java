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
    public boolean isSymmetric(TreeNode root) {
        if(root == null)    return true;
        return helper(root.left, root.right);
    }
    
    
    private boolean helper(TreeNode leftnode, TreeNode rightnode)
    {
        if(leftnode == null && rightnode == null)   return true;
        else if(leftnode == null || rightnode == null)  return false;
        else if(leftnode.val != rightnode.val)  return false;
        return helper(leftnode.left, rightnode.right)&&helper(leftnode.right, rightnode.left);
    }
}
