#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <sstream>
#include <cmath>
#include <unordered_set>  // 需要c++ 11才能支持
#include <unordered_map>  // 需要c++ 11才能支持
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
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
// 相同题目 《剑指offer》 二叉搜索树与双向链表
class Converter {
public:
    ListNode* treeToList(TreeNode* root) {
        ListNode dummy(-1), *pre = &dummy;
        inorder(root, pre);
        return dummy.next;
    }
private:
    void inorder(TreeNode* root, ListNode*& pre){
        if(root == NULL) return;
        inorder(root->left, pre);
        pre->next = new ListNode(root->val);
        pre = pre->next;
        inorder(root->right, pre);
    }
};
int main(){

    return 0;
}
