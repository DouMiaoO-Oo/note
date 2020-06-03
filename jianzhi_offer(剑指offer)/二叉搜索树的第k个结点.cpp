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
    int id;
    Solution() :id(0){}
    TreeNode* KthNode(TreeNode* p, int k)
    {
        if(p == NULL) return NULL;
        TreeNode* n = KthNode(p->left, k);
        if(n != NULL) return n;
        if(++id == k) return p;
        n = KthNode(p->right, k);
        if(n != NULL) return n;
        return NULL;
    }

    
};
/*
2019.2.19 下面这样应该也行
class Solution {
public:
    TreeNode* helper(TreeNode* r, int k){
        if(r == NULL) return NULL;
        TreeNode* node = NULL;
        node = helper(r->left, k);
        if(node != NULL) return node;
        if(++cnt == k)
            return r;
        return helper(r->right, k);   // 直接返回右节点
    }
    TreeNode* KthNode(TreeNode* pRoot, int k){
        cnt = 0;
        if(pRoot == NULL || k == 0) return NULL;
        return helper(pRoot, k);
    }
private:
    int cnt;
};
*/

/*2020.5.9*/
class Solution {
public:
    void helper(TreeNode* p){
        if(res) return;
        if(p->left) helper(p->left);
        if(--k == 0){
            res = p;
            return;
        }
        if(p->right) helper(p->right);
    }
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(!pRoot || k<=0) return NULL;
        this->k = k;
        helper(pRoot);
        return res;
    }

private:
    int k;
        TreeNode* res = NULL;
};
int main(){

    return 0;
}
