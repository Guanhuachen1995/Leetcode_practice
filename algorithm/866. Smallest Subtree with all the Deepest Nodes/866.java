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
    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        if( root == null ) return null;
		int left =  depth(root.left);
		int right = depth(root.right);
		if( left  == right ) return root;
		if( left > right ) return subtreeWithAllDeepest(root.left);
		return subtreeWithAllDeepest(root.right);
    }
    
    public int depth(TreeNode root){
		if(root == null ) return 0;
		return Math.max(depth(root.left),depth(root.right))+1;
	}
}
