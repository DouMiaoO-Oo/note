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
        stack<TreeNode*> s;
        stack<TreeNode*> next_s;
        s.push(pRoot);
        TreeNode *p, *l, *r = NULL;
        int cur_cnt = 1;
        res.push_back(vector<int>());
        int next_cnt = 0;
        bool odd = true;
        int id = 0; // level of res
        while(!s.empty()){
            p = s.top();
            s.pop();
            (res[id]).push_back(p->val);
            l = p->left;
            r = p->right;
            if(!odd) swap(l, r);
            if(l){
                next_s.push(l);
                ++next_cnt;
            } if(r){
                next_s.push(r);
                ++next_cnt;
            } if(--cur_cnt == 0 && next_cnt != 0){
                cur_cnt = next_cnt;
                swap(s, next_s);
                next_cnt = 0;
                odd = !odd;
                res.push_back(vector<int>());
                ++id;
            }
        } return res;
    }
    
};
int main(){

    return 0;
}
