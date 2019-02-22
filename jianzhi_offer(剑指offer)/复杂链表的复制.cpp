#include <iostream>
#include<vector>
#include <algorithm>
#include <string>

using namespace std;

/*
核心思想，将原链表和新链表节点之间对应的联系建立起来。
*/

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};


class Solution {
public:
    RandomListNode* Clone(RandomListNode* head){
        if(head == NULL) return NULL;
        RandomListNode dummy(-1), *p1 = head, *p2, *pt;
        // 假设通过next可以遍历完所有node
        while(p1 != NULL){  // old->new
            p2 = new RandomListNode(p1->label);
            p2->next = p1->next;
            p1->next = p2;
            p1 = p2->next;
        } p1 = head;
        while(p1 != NULL){
            p2 = p1->next;
            if(p1->random != NULL){  // random可能为NULL
                p2->random = p1->random->next;
            } else p2->random = NULL;
            p1 = p2->next;
        } p1 = head;
        dummy.next = head->next;
        while(p1->next->next != NULL){
            p2 = p1->next;
            pt = p2->next; // next old node
            p1->next = pt;
            p2->next = p2->next->next;
            p1= pt;
        }  // assert p1 is the last non-null node
        p1->next = NULL;
        return dummy.next;
    }
};


int main(){

    return 0;
}
