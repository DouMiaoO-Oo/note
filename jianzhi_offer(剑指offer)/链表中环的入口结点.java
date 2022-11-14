public class Solution {
    /*
        快慢指针法，慢指针 p1 每次走1步，快指针 p2 每次走2步。
        环之前的节点数记为 x, 环上的节点个数记录为 y, 快慢指针相遇在环上的第 z 个节点。
        快慢指针相遇的场景：
            慢指针 p1 走完了 x，且在环上走了不到一圈，在环上第 z 个节点就被快指针 p2 追上。
            快指针 p2 走了 x + n*y + z，即快指针可能在环上绕了 n 圈，且 n >= 1.
            又因为快慢指针每次移动的步数存在2倍的关系可得： 2(x+z) = x + n*y + z
        综上可得：x = n*y - z
        又因为快慢指针相遇时慢指针已经在环上走了 z 步，刚好再走 n*y-z 步，即 x 步就可以回到环上的最后一个节点
        因此我们可以再设置一个慢指针 p3 ，从整个链表的起点开始走x+1步，同时让慢指针 p1 继续在环上也走 x+1 步。
        最终 p1 和 p3 会相遇在环上的起点。
    */
    static class ListNode {
        int val;
        ListNode next = null;

        ListNode(int val) {
            this.val = val;
        }
    }
    public ListNode EntryNodeOfLoop(ListNode p)
    {
        ListNode dummy = new ListNode(-1);
        dummy.next = p;
        ListNode p1 = dummy;
        ListNode p2 = dummy;
        while(true){
            if(p2.next == null) return null;
            p2 = p2.next;
            if(p2.next == null) return null;
            p2 = p2.next;
            p1 = p1.next;
            if(p1 == p2) break;
        }
        p2 = dummy;
        while(p1 != p2){
            p1 = p1.next;
            p2 = p2.next;
        } return p1;
    }
    public static void main(String [] args){
        int N = 18;
        int x = 15;
        ListNode dummy = new ListNode(-1);
        ListNode tail = dummy;
        ListNode p = dummy;
        for(int i = 0; i < N; ++i){
            tail.next = new ListNode(i);
            tail = tail.next;
        }
        for(int i = 0; i < x; ++i){
            p = p.next;
        }
        ListNode entryNode = p.next;
        tail.next = entryNode; // 构建环形节点
        System.out.println(new Solution().EntryNodeOfLoop(dummy.next).val);
    }
}
