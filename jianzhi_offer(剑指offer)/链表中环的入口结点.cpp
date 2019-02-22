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
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead == NULL || pHead->next == NULL)
            return NULL;
        ListNode* s = pHead;        // slow 指针走了1步
        ListNode* f = pHead->next;  // fast 指针走了2步
        bool exist = false;
        while(f != NULL){
            s = s->next;
            f = f->next;
            if(f != NULL){
                f = f->next;
                if(s == f){
                    exist = true;
                    break;
                }
            }
        } if(!exist) return NULL;  // 如果f == NULL 也说明不存在环
        s = pHead;  //  slow 指针从head开始走了1步
        f = f->next;  // 容易遗漏
        while(s != f){
            s = s->next;
            f = f->next;
        } return s;
    }
};
int main(){

    return 0;
}
