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

class Balance {
public:
    int helper(TreeNode* root, int k){
        // if(root->left == NULL && root->right == NULL) return k;
        int left_level = k;
        if(root->left != NULL) left_level = helper(root->left, k+1);
        if(left_level == -1) return -1;
        int right_level = k;
        if(root->right != NULL) right_level = helper(root->right, k+1);
        if(right_level == -1) return -1;
        return abs(left_level-right_level) <= 1
            ? max(left_level, right_level) : -1;
    }
    bool isBalance(TreeNode* root) {
        if(root == NULL) return false;
        return helper(root, 0) != -1;
    }
};
int main(){

    return 0;
}
