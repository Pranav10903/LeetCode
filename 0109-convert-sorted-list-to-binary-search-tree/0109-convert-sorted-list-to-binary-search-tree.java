/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
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
    private int[] A;
    public TreeNode sortedListToBST(ListNode head) {
        int len=0;
        if(head==null) return null;
        ListNode tem=head;
        while(tem!=null){
            len++;
            tem=tem.next;
        }
        this.A = new int[len];
        int i=0;
        ListNode root=head;
        while(root!=null){
            A[i++]=root.val;
            root=root.next;
        }
        return bst(0,len-1);
    }
    private TreeNode bst(int left,int right){
            if(left>right) return null;
            int mid = left+(right-left)/2;
            TreeNode ans = new TreeNode(A[mid]);
            ans.left=bst(left,mid-1);
            ans.right=bst(mid+1,right);
            return ans;
    }
}