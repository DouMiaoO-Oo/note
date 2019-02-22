#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    void helper(vector<int>& res, ListNode* h){
        if(h == NULL) return;
        helper(res, h->next);
        res.push_back(h->val);
    }
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        helper(res, head);
        return res;
    }
};
vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        if(head == NULL) return res;
        ListNode *p1=head, *p2=p1->next, *p3;
        while(p2 != NULL){
            p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }head->next = NULL; // 容易遗漏
        while(p1 != NULL){
            res.push_back(p1->val);
            p1 = p1->next;
        } return res;
    }
int main(){

    return 0;
}
