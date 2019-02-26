#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

template<typename T>
void print(vector<T> v){
    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << endl;
    } return;
}
// ref: https://www.cnblogs.com/grandyang/p/4358848.html
vector<string> permutation(string str){
    if(str == "") return vector<string>(1, ""); // n, v
    string subs = str.substr(1, str.size()-1);
    vector<string> str_list = permutation(subs);
    vector<string> new_str_list;
    for(int i = 0; i < str_list.size(); ++i){
        for(int j = 0; j <= str_list[i].size(); ++j){
            new_str_list.push_back(str_list[i].substr(0, j) + str[0] + str_list[i].substr(j, str.size()-j));  // str.substr(str.size(), 0), 这个能运行估计是因为'\0'
        } //new_str_list.push_back(str_list[i] + str[0]);  // substr(start, len)  start 超过了范围? 能运行
    } return new_str_list;
}

vector<string> permutation_iter(string str){
    /*
    迭代版本插入法生成全排列 */
    if(str == "") return vector<string>();
    vector<string> str_list(1, ""), new_str_list;
    vector<string> *a = &str_list, *b = &new_str_list;
    for(char c: str){
        for(string substring: (*a)){
            for(int i = 0; i <= substring.size(); ++i){
                (*b).push_back(substring.substr(0, i) + c + substring.substr(i, substring.size()-i));
            }
        } swap(a, b);  // swap pointer, 我觉得这操作复杂度比较低
        (*b) = vector<string>();
    } return *a;
}

class Solution {
public:
    /* 集合版本的代码 */
    vector<vector<int>> permute(vector<int> num) {
        if (num.empty()) return vector<vector<int>>(1, vector<int>());
        vector<vector<int>> res;
        int first = num[0];
        num.erase(num.begin());
        vector<vector<int>> words = permute(num);
        for (auto &a : words) {
            for (int i = 0; i <= a.size(); ++i) {
                a.insert(a.begin() + i, first);  // insert (position, value);
                res.push_back(a);
                a.erase(a.begin() + i);  // erase (position);
            }
        }
        return res;
    }
};
void test(){
    int a[] = {1, 2, 3}, n = 3;
    vector<vector<int> > res = Solution().permute(vector<int>(a, a+n));
    for(int i = 0; i < res.size(); ++i){
        for(int j = 0; j < res[i].size(); ++j){
            cout << res[i][j] << ' ';
        } cout << endl;
    }
}
int main(){
    // test(); return 0;
    string str = "1234";
    int n = str.size();
    //cout << str.substr(4, 0) << endl; return 0;  // 测试str.substr(str.size(), 0), 这个能运行估计是因为'\0'
    vector<string> res = permutation_iter(str);
    sort(res.begin(), res.end());
    print(res);
    return 0;
}
