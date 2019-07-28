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
/*
输入描述:
二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5
*/
class Solution {
public:
    void Mirror(TreeNode *r) {
        if(r == NULL) return;
        swap(r->left, r->right);
        Mirror(r->left);
        Mirror(r->right);
    }
};
/*
// 傻逼做法
class Solution {
public:
    void helper(TreeNode*& l, TreeNode*& r){
        swap(l, r);
        if(l != NULL)
            helper(l->left, l->right);
        if(r != NULL)
            helper(r->left, r->right);
    }
    void Mirror(TreeNode *pRoot) {
        if(pRoot == NULL) return;
        helper(pRoot->left, pRoot->right);
        return;
    }
};
*/
int main(){

    return 0;
}
