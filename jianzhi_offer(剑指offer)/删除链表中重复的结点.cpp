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
这个代码写的不是很优雅
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        //if(pHead == NULL) return pHead;
        ListNode dummy(0);
        dummy.next = pHead;
        ListNode* p = &dummy;
        int cur = 1^(pHead->val);
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
int main(){

    return 0;
}
