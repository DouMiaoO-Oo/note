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
        sort(A.begin(), A.end());
        vector<vector<int> > res;
        unsigned int u = (1 << A.size());
        for(unsigned int i = u-1; i > 0; --i){  // i > 0去掉空集合
            vector<int> cur;
            unsigned int bit = A.size()-1, k = i;
            while(k != 0){
                if(k&(1<<bit)) {
                    cur.push_back(A[bit]);
                    k ^= (1<<bit);
                } --bit;
            } res.push_back(cur);
        } return res;
    }
private:
    static bool cmp(int x, int y){  // 一定要用static！
        return x > y;
    }
};

int main(){
    int n=3, a[n] = {789, 456, 123};
    // int n=5, a[n] = {9,7,5,3,1};
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
