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
        List<List<Integer>> ans = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<TreeNode> ();
        if(root==null) return ans;
        q.add(root);
        while(!q.isEmpty()){
            List<Integer> ans1 = new ArrayList<>();
            int currlevel = q.size();
            for(int i=0;i<currlevel;i++){
                TreeNode curNode = q.poll();
                ans1.add(curNode.val);
                if(curNode.left!=null){
                    q.add(curNode.left);
                }
                if(curNode.right!=null){
                    q.add(curNode.right);
                }
            }
            ans.add(ans1);
        }
        return ans;
    }
}