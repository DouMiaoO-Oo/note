#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
/*
补充题目的要求，返回指向最小节点的指针。
*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree){
        if(pRootOfTree == NULL) return NULL;
        TreeNode* pre = NULL;
        helper(pRootOfTree, pre);
        while(pRootOfTree->left != NULL){
            pRootOfTree = pRootOfTree->left;
        } return pRootOfTree;
    }
    void helper(TreeNode* cur, TreeNode*& pre){
        if(cur == NULL) return;
        helper(cur->left, pre);
        cur->left = pre;
        if(pre != NULL) pre->right = cur;
        pre = cur;
        helper(cur->right, pre);
    }
};
int main(){

    return 0;
}
