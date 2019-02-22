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
class Permutation {
public:
    vector<string> getPermutation(string A) {
        this->res = vector<string>();
        if(A.size() <= 0){
            return res;
        }
        helper(A, A.size(), 0);
        sort(res.begin(), res.end(), cmp);  // 把结果排序
        return res;
    }
private:
    void helper(string&A, int n, int k){
        if(k == n-1){
            res.push_back(A);
        } else{
            for(int i = k; i < n; ++i){
                swap(A[k], A[i]);
                helper(A, n, k+1);
                swap(A[k], A[i]);
            }
        } return;
    }
    vector<string> res;
    static bool cmp(string a, string b){
        return a > b;  // 从大到小排列
    }
};
int main(){
    vector<string> res = Permutation().getPermutation("EDCBA");
    for(int i = 0; i < res.size(); ++i){
        cout << res[i] << endl;
    }
    return 0;
}
