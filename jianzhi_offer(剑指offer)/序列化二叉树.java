import java.util.Queue;
import java.util.LinkedList;
import java.util.ArrayList;

class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;
    }
}

public class Solution {
    String Serialize(TreeNode root) {
        if(root == null) return "{}";
        ArrayList<String> arr = new ArrayList<String>();
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.offer(root);
        while(!q.isEmpty()){
            TreeNode node = q.poll();
            if(node == null){
                arr.add("#");
            } else{
                arr.add(Integer.toString(node.val));
                q.offer(node.left);
                q.offer(node.right);    
            }
        }
        return "{"+String.join(",", arr)+"}";
    }
    TreeNode Deserialize(String str) {
        String [] nodes = str.replaceAll("(^\\{)|(}$)", "").split(",");
        if(nodes.length == 1 && nodes[0].equals("")) return null;
        TreeNode r = new TreeNode(Integer.parseInt(nodes[0]));
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.add(r);
        int idx = 1;
        while(!q.isEmpty()){
            TreeNode node = q.poll();
            String s;
            for(int i = 0; i < 2; ++i){
                if(idx == nodes.length) break;
                s = nodes[idx++];
                if(s.equals("#")) continue;
                if(i == 0){
                    node.left = new TreeNode(Integer.parseInt(s));
                    q.add(node.left);
                } else{
                    node.right = new TreeNode(Integer.parseInt(s));
                    q.add(node.right);
                }
            }
        }
        return r;
    }
    public static void main(String[] args){
        String [] arr = {
                "{1,2,3,#,#,6,7}",
                "{1}",
                "{}"
        };
        Solution obj = new Solution();
        for(String str: arr){
            TreeNode node = obj.Deserialize(str);
            String res = obj.Serialize(node);
            System.out.println(res);
        }
    }
}