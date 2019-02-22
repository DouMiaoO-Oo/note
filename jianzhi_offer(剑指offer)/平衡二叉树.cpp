#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<cmath>
using namespace std;
/* 对比计算二叉树的深度 */
class Solution {
public:
    int helper(TreeNode* r){
        if(r == NULL) return 0;
        int left = helper(r->left);
        int right = helper(r->right);
        if(left == -1 || right == -1) return -1;
        if(abs(left-right) > 1) return -1;
        return max(left, right)+1;
    }
    bool IsBalanced_Solution(TreeNode* root) {
        if(root == NULL) return true;
        return helper(root) != -1;
    }
};
int main(){

    return 0;
}
