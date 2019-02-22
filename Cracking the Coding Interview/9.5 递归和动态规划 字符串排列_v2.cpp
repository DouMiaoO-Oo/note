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
        res = vector<string>();
        if(A.size() == 0) return res;
        sort(A.begin(), A.end(), cmp);
        cout << "A=" << A <<endl;
        visited = vector<bool>(A.size(), false);
        helper(A, "", A.size(), 0);
        return res;
    }
private:
    vector<string> res;
    vector<bool> visited;
    static bool cmp(char a, char b){
        return a > b;
    }
    void helper(string& str, string cur, int n, int k){
        if(k == n){
            if(cur.size() != 0)
                res.push_back(cur);
            return;
        }
        for(int i = 0; i < n; ++i){
            if(visited[i]) continue;
            visited[i] = true;
            cur += str[i];
            helper(str, cur, n, k+1);
            visited[i] = false;
            cur = cur.substr(0, cur.size()-1); // start id, len
        }
    }
};
int main(){
    //vector<string> res = Permutation().getPermutation("EDCBA");
    vector<string> res = Permutation().getPermutation("NXX"); // X > N
//    vector<string> res = Permutation().getPermutation("123");
    for(int i = 0; i < res.size(); ++i){
        cout << res[i] << endl;
    }
    return 0;
}
