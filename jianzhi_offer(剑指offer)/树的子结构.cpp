#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;
/*
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
e.g.:
{8,8,7,9,2,#,#,#,#,4,7},{8,9,2}
输出true
*/

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
    bool HasSubtree(TreeNode* r1, TreeNode* r2){
        if(r1 == NULL || r2 == NULL) return false;
        return partial_identity(r1, r2)
            || HasSubtree(r1->left, r2) || HasSubtree(r1->right, r2); 
    }
private:
    bool partial_identity(TreeNode* r1, TreeNode* r2){
        if(r2 == NULL) return true;
        if(r1 == NULL) return false;
        if(r1->val != r2->val) return false;
        return partial_identity(r1->left, r2->left) 
            && partial_identity(r1->right, r2->right);
    }
};
int main(){

    return 0;
}
