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

 List<Integer> str = new LinkedList<>(); 
  public void Inorder(TreeNode root)
    {
        if(root == null) //BASE CASE 
            return; 

        //LMR
        Inorder(root.left);//L
        str.add(root.val); //M
        Inorder(root.right);//R
    }
    
    public boolean isValidBST(TreeNode root) {
        Inorder(root); 
        for(int i =0;i<str.size()- 1;i++){
            System.out.println("here"); 
            if(str.get(i) >= str.get(i + 1)){
                return false;
            }
        }
        return true; 
    }

}