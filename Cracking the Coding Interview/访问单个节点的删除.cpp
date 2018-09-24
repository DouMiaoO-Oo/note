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
class Remove {
public:
    /* 因为没有办法访问到上一个node, 所以只能通过删除val来实现对node的删除*/
    bool removeNode(ListNode* pNode) {
        // write code here
        if(pNode == NULL || pNode->next == NULL) return false;
        while(pNode->next->next != NULL){
            pNode->val = pNode->next->val;
            pNode = pNode->next;
        } pNode->val = pNode->next->val;
        pNode->next = NULL;
        return true;
    }
};

/*
// 更加简洁的做法
class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node == NULL || node->next == NULL) return;
        node->val = node->next->val;
        node->next = node->next->next;
        return;
    }
};

---------------------

本文来自 DouMiaoO_Oo 的CSDN 博客 ，全文地址请点击：https://blog.csdn.net/DouMiaoO_Oo/article/details/51165829?utm_source=copy 
*/
int main(){

    return 0;
}
