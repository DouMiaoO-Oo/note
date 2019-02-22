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
/*
思路1：
因为是单链表，所以从第一个公共节点之后都是两个链表共享的节点，两个链表会有相同的结尾节点。
先获取两个链表各自的长度，然后获取长度的差值。
*/
class Solution {
public:
    int getLen(ListNode* p){
        int len = 0;
        while(p != NULL){
            ++len;
            p = p->next;
        } return len;
    }
    ListNode* FindFirstCommonNode( ListNode* p1, ListNode* p2) {
        int len1 = getLen(p1), len2 = getLen(p2);
        if(len1 > len2){
            swap(len1, len2);
            swap(p1, p2);
        }
        int diff = len2-len1;
        while(diff--){
            p2 = p2->next;
        }
        while(p1 != p2){
            p1 = p1->next;
            p2 = p2->next;
        } return p1;
        
    }
};
/*
思路2：
哈希法，用哈希表记录链表p1节点
返回遍历p2时遇到的第一个哈希表中保存的节点
*/

/*
参考牛客网链接：https://www.nowcoder.com/questionTerminal/6ab1d9a29e88450685099d45c9e31e46

思路3:
记链表L1的长度为 a+c, 链表L2的长度为b+c, 两个链表的公共节点的长度为c.
如果每次遍历一个链表到结尾NULL时改去遍历另一个链表。就类似于把两个链表拼接起来，变成(L1+L2)与(L2+L1)
那么两个遍历的指针会在遍历a+b+c个节点之后相遇。
缺陷：如果有循环链表，该方法无效是个死循环。

验证：
(1) 两个链表长度不同有公共交点：可以在第二次遍历返回正确结果.  
(2) 两个链表长度相同有公共交点： 可以在第一次遍历返回正确结果
(3) 两个链表没有公共交点，长度相同：第一遍返回NULL.
(4) 两个链表没有公共交点，长度不同: ? 貌似是走一个最小公倍数之后停在NULL处返回
(4) 空链表的影响

*/
/*
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;
        while(p1!=p2){
            p1 = (p1==NULL ? pHead2 : p1->next);
            p2 = (p2==NULL ? pHead1 : p2->next);
        }
        return p1;
    }
};
*/
int main(){

    return 0;
}
