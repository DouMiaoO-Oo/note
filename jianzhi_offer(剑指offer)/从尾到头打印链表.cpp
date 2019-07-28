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
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        if(head == NULL) return res;
        ListNode *p1=head, *p2=p1->next, *p3;
		// p1->next = NULL; // 容易遗漏的这句写在这里也可以
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
};

int main(){

    return 0;
}

/*
# 方法一：直接用stack
vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        if(head == NULL) return res;
        stack<ListNode*> s;
        while(head != NULL){
            s.push(head);
            head = head->next;
        }
        while(!s.empty()){
            res.push_back(s.top()->val);
            s.pop();
        } return res;
    }
# 方法二：利用递归
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
*/