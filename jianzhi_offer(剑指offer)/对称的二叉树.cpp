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
};
*/
/*
对比判断两个二叉树相同的题目
                    2
                  /   \
                 /     \
                3       3
              /  \     / \             
             5    4   4   5
            /\   /\  /\   /\ 
           7 6  9 8  8 9 6  7                            
*/
class Solution {
public:
    bool helper(TreeNode* a, TreeNode* b){
        if(a == NULL && b == NULL) return true;
        if(a == NULL || b == NULL) return false;
        if(a->val != b->val) return false;
        return helper(a->left, b->right) && helper(a->right, b->left);
    }
    bool isSymmetrical(TreeNode* root){
        if(root == NULL) return true;
        return helper(root->left, root->right);
    }

};
int main(){

    return 0;
}
