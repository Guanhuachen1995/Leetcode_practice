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
    public TreeNode sortedArrayToBST(int[] nums) {
        return helper(nums, 0 ,nums.length -1);
    }
    private TreeNode helper(int[] nums, int start, int end)
    {
        if(start > end)    return null;
        int mid = (start + end)/2;
        TreeNode tem = new TreeNode(nums[mid]);
        tem.left = helper(nums, start, mid -1);
        tem.right = helper(nums, mid +1, end);
        return tem;
    }
}
