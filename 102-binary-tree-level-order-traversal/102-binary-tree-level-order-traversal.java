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
    public List<List<Integer>> levelOrder(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        List<List<Integer>> ans = new ArrayList<>(); 
        if(root == null)
            return ans;
        q.add(root);
        while(q.size() !=0){
            int count = q.size();
            List<Integer> res = new ArrayList<>(); 
            for(int i=0;i<count; i++){
                TreeNode curr = q.remove();//first element will be deleted
                //  System.out.println(curr.val);
                res.add(curr.val); 
                 if(curr.left != null){
                    q.add(curr.left);
                 }
                 if(curr.right !=null){
                     q.add(curr.right);
                 }
            }
            ans.add(res);
        }

        return ans;
    }
}