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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == NULL || k <= 0) return NULL;
        ListNode* p1 = pListHead, *p2=p1;
        for(int i = 1; i < k; ++i){
            if(p1->next != NULL){
                p1 = p1->next;
            } else{
                return NULL;
            }
        }
        while(p1->next != NULL){
            p1 = p1->next;
            p2 = p2->next;
        } return p2;
    }
};
int main(){

    return 0;
}
