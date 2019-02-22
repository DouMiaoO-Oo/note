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

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
/* 2018.10*/
class Successor {  /* 这份代码可以通过 */
public:
    int helper(TreeNode* root, int p, bool &find){
        if(root == NULL) return -1;
        int left = helper(root->left, p, find);
        if(left != -1) return left;
        if(find) return root->val;
        if(p == root->val) find = true;
        return helper(root->right, p, find);
    }
    int findSucc(TreeNode* root, int p) {
        bool find = false;
        return helper(root, p, find);
    }
};
/*  // 2018.10
class Successor {  // 思路类似，是判断上一个访问的节点是不是p
public:
    void helper(TreeNode* root, int p, int& pre, int& ans){
        if(root == NULL) return;
        helper(root->left, p, pre, ans);
        if(ans != -1) return;
        if(pre == p) {
            ans = root->val;
            // return;  // 这一行要注释掉才可以通过。
			// 可以思考一个例子, 在下面这个只有left节点的树上找p=3的后继节点，答案为2
			//                1
			//              2 
			//            3
			//          4
			// 如果没有注释掉return这一句的话，因为pre没有更新，最后返回的就是1
        } pre = root->val;
        helper(root->right, p, pre, ans);
    }
    int findSucc(TreeNode* root, int p) {
        int ans = -1, pre=-1;
        helper(root, p, pre, ans);
        return ans;
    }
};
*/

/*
// 2019.2.19
class Successor {
public:
    void helper(TreeNode* cur, TreeNode*& pre, int p){
        if(cur == NULL || res != -1) return;
        helper(cur->left, pre, p);
        if(res != -1) return;  // 容易遗漏
        if(pre != NULL && pre->val == p){
            res = cur->val;
            return;
        }
        pre = cur;
        helper(cur->right, pre, p);
        
    }
    int findSucc(TreeNode* root, int p) {
        if(root == NULL) return -1;
        TreeNode* pre = NULL;
        res = -1;
        helper(root, pre, p);
        return res;
    }
private:
    int res;
};
*/
int main(){
	int n = 300;
    TreeNode* root = new TreeNode(0);

    return 0;
}
