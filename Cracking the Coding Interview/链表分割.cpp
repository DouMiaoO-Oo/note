#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        ListNode small(-1), large(-1);
        ListNode *p1=&small, *p2=&large;
        while(pHead != NULL){
            if(pHead->val < x){
                p1->next = pHead;
                p1 = pHead;
            } else{
                p2->next = pHead;
                p2 = pHead;
            } pHead = pHead->next;
        } p1->next = large.next;
        p2->next = NULL; // 神tm要注意修改的地方
        return small.next;
    }
};
void print(ListNode* r){
    while(r != NULL){
        cout << r->val << endl;
        r = r->next;
    } return;
}
int main(){
    ListNode *root = new ListNode(3);
    ListNode *p = root;
    p->next = new ListNode(1);
    p = p->next;

    p->next = new ListNode(5);
    p = p->next;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(2);
    p = p->next;

    //print(root);
    print(Partition().partition(root, 3));
    return 0;
}
