import java.util.*;

/* Java
 * public class ListNode {
 *   int val;
 *   ListNode next = null;
 *   public ListNode(int val) {
 *     this.val = val;
 *   }
 * }
 */

public class Solution {
    public ListNode deleteNode (ListNode head, int val) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode p = dummy;
        
        while(p.next != null){
            if(p.next.val == val){
                ListNode tmp = p.next.next;
                p.next.next = null;
                p.next = tmp;
                break;
            }
            p = p.next;
        }
        return dummy.next;
    }
}



/** cpp
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
// class Solution {
// public:
//     ListNode* deleteNode(ListNode* head, int val) {
//         ListNode dummy(-1);
//         dummy.next = head;
//         ListNode *p = &dummy;
//         while(p->next != NULL){
//             if(p->next->val == val){
//                 ListNode *tmp = p->next->next;
//                 p->next->next = NULL;
//                 p->next = tmp;
//             }
//             p = p->next;
//         } return dummy.next;
//     }
// };
