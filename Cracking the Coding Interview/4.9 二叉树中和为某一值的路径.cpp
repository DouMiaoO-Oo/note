#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;
/*
题目描述
输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)
*/
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
    /*
    tip: 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
    我自己的假设，假设节点的数值都是正数
*/
    void helper(TreeNode* root, vector<vector<int> >& res, vector<int> p,
                int k, int cur){
        p.push_back(root->val);
        if(root->val + cur == k){
            if(root->left == NULL && root->right == NULL){
                res.push_back(p);
            }
        } else if(root->val + cur < k){
            if(root->left) helper(root->left, res, p, k, cur+root->val);
            if(root->right) helper(root->right, res, p, k, cur+root->val);
        }
    }
    vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
        vector<vector<int> > res;
        if(root == NULL) return res;
        helper(root, res, vector<int>(), expectNumber, 0);
        return res;
    }
};
/*
// 稍微整洁一点的代码
class Solution {
public:
    void helper(TreeNode* node, int exp){
        exp -= node->val;
        cur.push_back(node->val);
        if(node->left == NULL && node->right == NULL){
            if(exp == 0) res.push_back(cur);
        }
        else{
            if(node->left) 
                helper(node->left, exp);
            if(node->right) 
                helper(node->right, exp);
        }
        cur.pop_back();
    }
    vector<vector<int> > FindPath(TreeNode* root, int exp) {
        cur.clear();
        res.clear();
        if(root == NULL) return res;
        helper(root, exp);
        return res;
    }
private:
    vector<vector<int> > res;
    vector<int> cur;
};

*/
int main(){

    return 0;
}
