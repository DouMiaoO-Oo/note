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
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    TreeNode* helper(vector<int>& pre, vector<int>& vin, int s1, int e1, int s2, int e2){
        if(s1 > e1) return NULL; // ÈÝÒ×´í
        int root_id = s2, root_val = pre[s1];
        TreeNode* root = new TreeNode(root_val);
        while(vin[root_id] != root_val){
            ++root_id;
        } int l_cnt = root_id-s2, r_cnt = e2-root_id;
        root->left = helper(pre,vin, s1+1, s1+l_cnt, s2, root_id-1);
        root->right = helper(pre,vin,e1-r_cnt+1,e1,root_id+1, e2);
        return root;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if(pre.size() != vin.size() || pre.size() <= 0) return NULL;
        return helper(pre, vin, 0, pre.size()-1, 0, vin.size()-1);
    }
};
int main(){

    return 0;
}
