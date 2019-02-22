#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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
/*
2018.8.23
这个方法是剑指offer上面的方法，
我想到的记录节点对应层数的方法，
是在queue中每次push进<节点， 节点的depth>
显然没有书上的方法好
*/
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int> > res;
            if(pRoot == NULL) return res;
            queue<TreeNode*> q;
            q.push(pRoot);
            res.push_back(vector<int>());
            int next_level_cnt = 0;
            int cur_level_cnt = 1;
            while(!q.empty()){
                TreeNode* r = q.front();
                q.pop();
                if(cur_level_cnt){
                    --cur_level_cnt;
                } else{
                    cur_level_cnt = --next_level_cnt;
                    next_level_cnt = 0;
                    res.push_back(vector<int>());
                }
                res[res.size()-1].push_back(r->val);
                if(r->left != NULL){
                    q.push(r->left);
                    ++next_level_cnt;
                } if(r->right != NULL){
                    q.push(r->right);
                    ++next_level_cnt;
                }
            }
            return res;
        }
    
};
/*
// 方法二：改进了把cur加进res的逻辑
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int> > res;
            if(pRoot == NULL) return res;
            vector<int> cur;
            queue<TreeNode*> q;
            q.push(pRoot);
            int cnt = 1, next_cnt = 0;
            while(!q.empty()){
                TreeNode* r = q.front();
                q.pop();
                cur.push_back(r->val);
                if(r->left != NULL) {
                    q.push(r->left);
                    ++next_cnt;
                }
                if(r->right != NULL) {
                    q.push(r->right);
                    ++next_cnt;
                }
                if(--cnt == 0){
                    cnt = next_cnt;
                    next_cnt = 0;
                    res.push_back(cur);
                    cur = vector<int>();
                }
            } return res;
        }
    
};

*/

int main(){

    return 0;
}
