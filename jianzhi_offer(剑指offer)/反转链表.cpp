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
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL || pHead->next == NULL) return pHead;
        ListNode *p1 = pHead, *p2 = p1->next, *p3;
        while(p2 != NULL){
            p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        } pHead->next = NULL; // 容易遗漏
        return p1;
    }
};
int main(){

    return 0;
}
