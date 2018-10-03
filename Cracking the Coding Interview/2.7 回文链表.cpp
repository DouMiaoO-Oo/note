#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
#include <cmath>
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
int a[] = {2,3,4,5,6,2,1,5,5,1,2,9,1,8,6,8,3,6,5,9,9,4,9,9,9,5,5,8,3,9,8,8,4,2,8,8,8,2,5,0,4,4,8,3,9,7,7,5,6,6,9,5,8,2,8,8,4,4,6,3,3,2,4,1,7,9,4,1,5,7,6,8,3,7,2,2,5,7,6,7,2,7,9,9,7,9,2,4,6,8,1,5,7,6,5,9,1,8,8,5,7,3,7,6,4,6,6,7,4,7,7,2,1,6,4,8,3,7,1,9,6,4,9,2,8};
int n = 125;
class Palindrome {
public:
    bool isPalindrome(ListNode* pHead) {
        /* �ҵ������������Ҫ����Ŀռ䣬���ǻ��޸�ԭʼ����.
        ��Ȼ��Ҳ���Ը�ԭԭʼ���� */
        if(pHead == NULL) return false;
        if(pHead->next == NULL) return true;
        ListNode* slow=pHead, *fast=pHead->next;
         if(fast->next && fast->next->next==NULL){
            return pHead->val == fast->next->val;
        } bool odd = false;  // error, len=2
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
            if(fast->next){
                fast = fast->next;
            } else odd = true;
        }  // ��ʱslowΪ�м�ڵ�(�ڵ���nΪ����)������slowΪ��n/2���ڵ�
        ListNode *l2 = slow;  // ���ε����ָ��
        if(!odd) l2 = l2->next;
        ListNode *pre = l2, *next;
        while(l2->next != NULL){
            next = l2->next;
            l2->next = pre;
            pre = l2;
            l2 = next;
        }
        while(true){
            if(pHead->val != l2->val) return false;
            if(pHead == slow) return true;
            pHead = pHead->next;
            l2 = l2->next;
        }
        // cout << "completed\n";
        return true;
        /* Ҳ���������ָ��޸ĵ����� */
    }
};
bool check(int *a, int n){
    int i = 0, j = n-1;
    while(i < j){
        if(a[i++] != a[j--]) return false;
    } return true;
}
int main(){
    ListNode* root = new ListNode(a[0]), *p=root, *t;
    for(int i = 1; i < n; ++i){
        p->next = new ListNode(a[i]);
        p = p->next;
    }
    p = root;
    for(int i = 0; p != NULL; ++i){
        if(a[i] != p->val) {
            cout << "������ʧ��\n";
            break;
        } p = p->next;
    } cout << "�������ɹ�\n";
    bool flag = Palindrome().isPalindrome(root);
    cout << flag << endl;
    cout << check(a, n) << endl;

    return 0;
}
