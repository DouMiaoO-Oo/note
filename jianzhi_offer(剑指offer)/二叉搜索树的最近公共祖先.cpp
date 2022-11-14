/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * @param root TreeNode类 
     * @param p int整型 
     * @param q int整型 
     * @return int整型
     */
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        // if(root == NULL) return -1;  // not find
        if((p <= root->val && root->val <= q) || (q <= root->val && root->val <= p)){
            return root->val;
        }
        if(p <= root->val && q <= root->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        //if(root->val <= p && root->val <= q){
            return lowestCommonAncestor(root->right, p, q);
        //}
    }
};

class Solution2 {
public:
    /**
     * @param root TreeNode类 
     * @param p int整型 
     * @param q int整型 
     * @return int整型
     * 针对节点值不重复的二叉树的通用解法
     */
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
       vector<TreeNode* > v1, v2;
       this->findPath(v1, root, p);
       this->findPath(v2, root, q);
       int res = -1;  //  -1: not find
       for(int i = 0; i < v1.size() && i < v2.size(); ++i){
           if(v1[i] == v2[i]) res = v1[i]->val;
           else break;
       }
       return res;
    }
private:
    void findPath(vector<TreeNode* > &v, TreeNode* root, int val){
        // 假设节点 val 一定在二叉树中
        if(root == NULL) return;
        v.push_back(root);
        if(val == root->val){
            return;
        }
        if(val < root->val){
            return findPath(v, root->left, val);
        }
        //if(root->val < val){
            return findPath(v, root->right, val);
        //}
    }
};
