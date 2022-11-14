import java.util.*;

/*
 * public class TreeNode {
 *   int val = 0;
 *   TreeNode left = null;
 *   TreeNode right = null;
 *   public TreeNode(int val) {
 *     this.val = val;
 *   }
 * }
 */

public class Solution {
    private int cnt = 0;
    private TreeNode res = null;
    private void inOrder(TreeNode r){
        if(r == null) return;
        inOrder(r.left);
        if(--cnt == 0){
            this.res = r;
            return;
        }
        inOrder(r.right);
    }
    public int KthNode (TreeNode root, int k) {
        this.cnt = k;
        this.res = null;
        inOrder(root);
        if(this.res == null) return -1;
        return this.res.val;
    }
}