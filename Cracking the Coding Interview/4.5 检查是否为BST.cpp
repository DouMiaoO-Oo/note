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

class Checker {
public:
    bool helper(TreeNode* root, int& pre){
        if(root == NULL) return true;
        if(!helper(root->left, pre)){
            return false;
        } if(pre > root->val){
            return false;
        } pre = root->val;
        return helper(root->right, pre);
    }
    bool checkBST(TreeNode* root) {
        if(root == NULL) return false;
        int pre = INT_MIN;
        return helper(root, pre);
    }
};
int main(){

    return 0;
}
