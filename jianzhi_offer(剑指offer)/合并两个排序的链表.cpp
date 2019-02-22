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
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* p1, ListNode* p2)
    {
        ListNode dummy(-1), *p = &dummy;
        while(p1 != NULL && p2 != NULL){
            if(p1->val <= p2->val){
                p->next = p1;
                p1 = p1->next;
            } else{
                p->next = p2;
                p2 = p2->next;
            } p = p->next;
        }
        /* 下面的写法太sb了
		while(p1 != NULL){
            p->next = p1;
            p1 = p1->next;
            p = p->next;
        }
        while(p2 != NULL){
            p->next = p2;
            p2 = p2->next;
            p = p->next;
        }*/ 
		if(p1 != NULL) p->next = p1;
        else if(p2 != NULL) p->next = p2;
        return dummy.next;
    }
};
int main(){

    return 0;
}
