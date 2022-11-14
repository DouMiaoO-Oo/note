/**
public class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
*/
public class Solution {
    private TreeNode pre = null;
    private TreeNode head;
    public TreeNode Convert(TreeNode r) {
        if(r == null) return null;
        Convert(r.left);
        if(pre != null) pre.right = r;
        else {
            head = r;
        }
        r.left = pre;
        pre = r;
        Convert(r.right);
        return head;
    }
}
