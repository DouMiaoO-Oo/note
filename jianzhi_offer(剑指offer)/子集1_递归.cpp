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
#include <assert.h>
using namespace std;

class Subset {
public:
    vector<vector<int> > getSubsets(vector<int> A, int n) {
        // assert A[i] >= 0
        if(n <= 0) return vector<vector<int> >();
        this->res = vector<vector<int> >();
        vector<int> cur;
        sort(A.begin(), A.end(), cmp);  // 升序排列
        helper(A, cur, n, 0);
        return this->res;
    }
private:
    vector<vector<int> > res;
    void helper(vector<int>& arr, vector<int>& cur, int n, int k){
        if(k == n){
            if(cur.size()>0){
                this->res.push_back(cur);
            }
        } else{
            cur.push_back(arr[k]);
            helper(arr, cur, n, k+1);
            cur.pop_back();
            helper(arr, cur, n, k+1);
            //cur.pop_back();
        }
    }
    static bool cmp(int x, int y){  // 一定要用static！
        return x>y;
    }
};
int main(){
    //int n=10, a[n] = {789, 456, 123};
    int n=5, a[n] = {9,7,5,3,1};
    vector<int> A(a, a+n);
    vector<vector<int> > res = Subset().getSubsets(A, n);
    for(int i = 0; i < res.size(); ++i){
        cout << "set" << i << " ";
        for(int j = 0; j < res[i].size(); ++j){
            cout << res[i][j] << " ";
        } cout << endl;
    }
    return 0;
}
