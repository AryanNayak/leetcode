/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    
    public TreeNode buildTree(int[] nums, int st, int ei)
    {
        
        if(st > ei)
        {
            return null; 
        }
        
        int mid = (st + ei)/2; 
        
        TreeNode node = new TreeNode(nums[mid]); 
        
        node.left = buildTree(nums, st, mid - 1); 
        node.right = buildTree(nums, mid + 1, ei); 
    
        return node; 

    }
    public TreeNode sortedArrayToBST(int[] nums) {
        int n = nums.length; 
        
        return buildTree(nums, 0, n - 1); 
        
    }
}