#include <iostream>
#include<vector>
#include <algorithm>
#include <string>

using namespace std;
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
/*
dummy是构造的节点，p代表上一个保留的节点
cur代表当前需要删除节点所具有的值
这个代码写的不是很优雅 2018.8.23
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        //if(pHead == NULL) return pHead;
        ListNode dummy(0);
        dummy.next = pHead;
        ListNode* p = &dummy;   // 需要保留的上一个节点
        int cur = 1^(pHead->val);  // 构造一个与head->val不同的值
        while(p->next != NULL){
            if(cur == p->next->val){  // 下一个节点需要删除
                p->next = p->next->next;
            } else{
                cur = p->next->val;
                if(p->next->next != NULL){
                    if(p->next->next->val == p->next->val){
                        // 此时p之后的节点是重复节点，也需要删除
                        p->next = p->next->next->next;
                    } else{  // p 之后的节点不是重复节点
                        p = p->next;
                    }
                } else{  // P之后只有一个1个节点，且不用删除
                    //p = p->next;
                    return dummy.next;
                }
            }
        } return dummy.next;
    }
};

/*
方法二： 2019.2.19
p->p1->p2
设p代表的是要保留的节点，p与p1的节点值不一样。
*/
/*
class Solution {
public:
    ListNode* deleteDuplication(ListNode* head){
        if(head == NULL) return NULL;
        ListNode dummy(-1), *p = &dummy, *p1 = head, *p2 = head->next;
        p->next = p1;
        while(p2 != NULL){
            if(p1->val != p2->val){
                p = p1;
                p1 = p2;
                p2 = p1->next;
            } else{  // p1和p2需要删除
                while(p2->next != NULL && p2->next->val == p1->val){  // p2指向最后一个需要删除的节点
                    p2 = p2->next;
                }
                p1 = p2->next;
                p->next = p1;
                p2 = (p1 == NULL)?NULL:p1->next;
            }
        } return dummy.next;
    }
};
*/

/*2020.5.9 */
class Solution {
public:
    ListNode* deleteDuplication(ListNode* p){
        if(p == NULL || p->next == NULL) return p;
        ListNode dummy(-1), *p1 = &dummy, *p2 = p;
        while(p2){
            if(p2->next == NULL || p2->next->val != p2->val){
                p1->next = p2;
                p1 = p2;
                p2 = p2->next;
            } else{
                while(p2->next && p2->val == p2->next->val){
                    p2 = p2->next;
                } p2 = p2->next;
                p1->next = NULL;  // 这里就是为了断开，考虑样例{1, 2, 3, 3, 4, 4, 4, 5}
            }
        } return dummy.next;
    }
};
int main(){

    return 0;
}
