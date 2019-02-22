#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
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
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root, int exp) {
        res = vector<vector<int> >();
        if(root == NULL) return res;
        helper(root, vector<int>(), exp);
        sort(res.begin(), res.end(), cmp);  // 这一行不加也能过，好像样例太弱了
        return res;
    }
private:
    static bool cmp(vector<int> a, vector<int> b){
        return a.size()>b.size();
    }
    void helper(TreeNode* r, vector<int> cur, int e){
        e -= r->val;
        cur.push_back(r->val);
        if(r->left == NULL && r->right == NULL){
            if(e == 0) res.push_back(cur);
        } else{
            if(r->left) helper(r->left, cur, e);
            if(r->right) helper(r->right, cur, e);
        } return;
    }
    vector<vector<int> > res;
};
int main(){

    return 0;
}
