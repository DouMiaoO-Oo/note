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


RandomListNode* Clone(RandomListNode* pHead){
    if(pHead == NULL) return pHead;
    RandomListNode* h = new RandomListNode(pHead->label);
    RandomListNode* p1 = pHead->next;
    RandomListNode* p2 = NULL;
    h->next = pHead->next;
    //h->random = pHead->random;
    pHead->next = h;
    while(p1 != NULL){
        p2 = new RandomListNode(p1->label);
        p2->next = p1->next;
        //p2->random = p1->random;
        p1->next = p2;
        p1 = p2->next;
    }
    // step2
    p1 = pHead;
    while(p1 != NULL){
        p2 = p1->next;
        if(p1->random != NULL){  // 这里可能为NULL
            p2->random = p1->random->next;
        } else{
            p2->random = NULL;
        }
        p1 = p2->next;
    }
    // step3
    p1 = pHead;
    while(p1 != NULL){
        p2 = p1->next;
        RandomListNode* p1_next = p2->next;
        if(p1_next != NULL){   // 这里可能为NULL
            p2->next = p1_next->next;
        } else{
            p2->next = NULL;
        }
        p1->next = p1_next;
        p1 = p1_next;
    }
    return h;
}


int main(){

    return 0;
}
