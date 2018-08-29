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
int main(){

    return 0;
}
