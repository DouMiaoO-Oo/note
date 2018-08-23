#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<cmath>
using namespace std;

class Solution {
public:
    bool result;
    int helper(TreeNode* r, int d){
        int dl, dr;  // depth of left and right
        if(r->left == NULL) dl = d;
        else dl = helper(r->left, d+1);
        if(r->right == NULL) dr = d;
        else dr = helper(r->right, d+1);
        if(abs(dl-dr)>1) result = false;
        return max(dl, dr);
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == NULL) return true;
        result = true;
        helper(pRoot, 1); // depth of tree
        return result;
    }
};
int main(){

    return 0;
}
