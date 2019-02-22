#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > res;
        if(pRoot == NULL) return res;
        vector<int> cur;
        //queue<TreeNode*> q;
        stack<TreeNode*> s;
        stack<TreeNode*> sn;  // stack for next level 容易遗漏
        s.push(pRoot);
        int cnt = 1, next_cnt = 0;
        bool odd = true;
        while(!s.empty()){
            TreeNode* r = s.top();
            s.pop();
            cur.push_back(r->val);
            TreeNode* left = r->left, *right = r->right;
            if(!odd) swap(left, right);
            if(left != NULL){
                sn.push(left);
                ++next_cnt;
            }
            if(right != NULL){
                sn.push(right);
                ++next_cnt;
            }
            if(--cnt == 0){
                cnt = next_cnt;
                next_cnt = 0;
                odd = !odd;
                res.push_back(cur);
                cur = vector<int>();
                swap(s, sn);  // 这一步如果嫌效率低，可以通过指针来操作
            }
        } return res;
    }
};
int main(){

    return 0;
}
