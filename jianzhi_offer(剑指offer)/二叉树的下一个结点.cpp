#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
/*
1. 空节点时，返回NULL
2. 有右子节点，则返回右子节点的叶节点
3. 循环到父节点的左子节点
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* p)
    {
        if(p == NULL) return NULL;
        if(p->right) {
            p = p->right;
            TreeLinkNode* l = p->left;
            while(l != NULL){
                p = l;
                l = p->left;
            } return p;
        }
        TreeLinkNode* parent = p->next;
        while(parent != NULL){
            if(p == parent->left) return parent;
            p = parent;
            parent = p->next;
        } return NULL;
    }
};
int main(){

    return 0;
}
