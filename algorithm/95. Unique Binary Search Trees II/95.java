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
    public List<TreeNode> generateTrees(int n) {
        if(n == 0)  return new ArrayList<TreeNode>();
        return helper(1,n);
    }
    
    private List<TreeNode>  helper(int start, int end) {
        List<TreeNode> list = new ArrayList<TreeNode>();
        
        if(start > end) {
            list.add(null);
            return list;
        }
        
        if(start == end) {
            list.add(new TreeNode(start));
            return list;
        }
        List<TreeNode> left = new ArrayList<TreeNode>();
        List<TreeNode> right = new ArrayList<TreeNode>();
        
        for(int i = start; i <= end; i++) {
            left = helper(start, i - 1);
            right = helper(i + 1, end);
            for(TreeNode lnode:left) {
                for(TreeNode rnode:right) {
                    TreeNode cur = new TreeNode(i);
                    cur.left = lnode;
                    cur.right = rnode;
                    list.add(cur);
                }
            }
        }
        return list;
    }
}
