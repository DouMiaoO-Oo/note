#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
#include <cmath>
#include<unordered_set>  // 需要c++ 11才能支持
using namespace std;
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class TreeLevel {
public:
    ListNode* getTreeLevel(TreeNode* root, int d) {
        int cnt = 1, next = 0;  // #currrent level node, #next level node
        int cur_d = 1; // 假设数的根节点d=1
        ListNode dummy = ListNode(-1), *l = &dummy;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty() && cur_d<=d){
            TreeNode* r = q.front();
            if(cur_d == d){
                l->next = new ListNode(r->val);
                l = l->next;
            }
            q.pop();
            --cnt;
            if(r->left != NULL) {  // cur_d等于d时，可以放弃这一步
                q.push(r->left);
                ++next;
            } if(r->right != NULL){  // cur_d等于d时，可以放弃这一步
                q.push(r->right);
                ++next;
            } if(cnt == 0){
                swap(cnt, next);
                ++cur_d;
            }
        } return dummy.next;
    }
};
int main(){

    return 0;
}
