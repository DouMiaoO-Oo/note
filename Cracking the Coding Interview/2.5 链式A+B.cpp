#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Plus {
public:
    ListNode* plusAB(ListNode* a, ListNode* b) {
        int res, c = 0; // carry
        ListNode dummy(-1), *p=&dummy;
        while(a!=NULL && b!=NULL){
            res = a->val + b->val + c;
            c = res/10;
            p->next = new ListNode(res%10);
            p = p->next;
            a = a->next;
            b = b->next;
        }
        if(a == NULL) a = b;
        while(a != NULL){
            res = a->val + c;
            c = res/10;
            p->next = new ListNode(res%10);
            p = p->next;
            a = a->next;
        } if(c != 0) p->next = new ListNode(c);
        return dummy.next;
    }
};
int main(){

    return 0;
}
