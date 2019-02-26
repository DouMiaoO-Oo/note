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
        if(A.size() == 0 || n <= 0) return vector<vector<int> >();
        sort(A.begin(), A.end(), cmp);
        vector<vector<int> > a, b, *pa = &a, *pb = &b;
        a.push_back(vector<int>());
        for(int i = 0; i < A.size(); ++i){
            for(int j = 0; j < (*pa).size(); ++j){
                (*pb).push_back((*pa)[j]);
                (*pb).back().push_back(A[i]);
                (*pb).push_back((*pa)[j]);
            } swap(pa, pb);
            (*pb) = vector<vector<int> >();
        } return *pa;
    }
private:
    static bool cmp(int x, int y){  // 一定要用static！
        return x>y;
    }
};
int main(){
    //int n=3, a[n] = {789, 456, 123};
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
