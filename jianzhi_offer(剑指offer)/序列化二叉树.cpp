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
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
    public:
    void SerializeHelper(TreeNode *r, string& str){
        str += ',';
        if(r == NULL) str += '$';
        else {
            //str += i2s(r->val);
            str += i2s_v2(r->val);
            SerializeHelper(r->left, str);
            SerializeHelper(r->right, str);
        }
        cout << str << endl;
    }
    char* Serialize(TreeNode *root) {
        string str;
        SerializeHelper(root, str);
        /*
        char* res = new char[str.size()+1];
        strcpy(res, str.c_str());
        ++res;  // escape one ','
        */

        //*
        char* res = new char[str.size()];
        char *dst = res;
        const char *src = (str.c_str())+1;  // escape one ','
        while ((*dst++=*src++)!='\0');
        //*/
        return res;
    }

    TreeNode* DeserializeHelper(TreeNode* p, char*& str) {
        if(*str == '\0') return NULL;
        if(*str == '$'){
            if(*(++str) == ','){
                ++str;  // 0, 1,2,$,$,$,$'\0'
            }
            return NULL;
        }
        p = new TreeNode(s2i(str));
        p->left = DeserializeHelper(p->left, str);
        p->right = DeserializeHelper(p->right, str);
        return p;
    }
    TreeNode* Deserialize(char *str) {
        return DeserializeHelper(NULL, str);
    }
private:
    string i2s(long long x){
        if(x == 0) return "0";
        string str;
        bool negative = false;
        if(x<0){
            negative = true;
            x = -x;
        }
        while(x != 0){
            str += char(x%10 + '0');
            x /= 10;
        } if(negative) str += '-';
        std::reverse(str.begin(), str.end());
        return str;
    }
    string i2s_v2(int x){
        stringstream ss;
        ss << x;
        string res;
        ss >> res;
        return res;
    }
    int s2i(char*& s){
        int res = 0;
        bool negative = false;
        if(*s == '-'){
            negative = true;
            ++s;
        } while(*s != ',' && *s != '\0'){
            res = res*10 + (*s++ - '0');
        } if(negative) res = -res;
        if(*s == ',') ++s;
        return res;
    }
};
TreeNode* constructTree(int& v, int x){
    if(v>x) return NULL;
    TreeNode* r = new TreeNode(v++);
    r->left = constructTree(v, x);
    r->right = constructTree(v, x);
    return r;
}
void printTreeNode(TreeNode* r){
    if(r){
        cout << r->val << endl;
        printTreeNode(r->left);
        printTreeNode(r->right);
    }
}
int main(){
    Solution solution = Solution();
    int cur_v = 0;
    //cout << solution.i2s(-1234) << endl;
    //cout << solution.s2i("-123") << endl;
    TreeNode* r = constructTree(cur_v, 100);
    printTreeNode(r);
    char* str_tree =  Solution().Serialize(r);
    cout << endl;
    cout << endl;
    cout << str_tree << endl;
    //cout << endl;
    //printTreeNode(solution.Deserialize(str_tree));

    return 0;
}
