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
class Queens {
public:
    bool valid(vector<int>& a, int r){
        for(int i = 0; i < r; ++i){
            if((a[i] == a[r])
               || (abs(a[i] - a[r]) == abs(r-i) ) ) return false;
        } return true;
    }
    void helper(vector<int>& a, int n, int r){
        if(r == n) {
            ++cnt;
            return;
        }
        for(int i = 0; i < n; ++i){
            a[r] = i;
            if(valid(a, r)) helper(a, n, r+1);
        } return;
    }
    int nQueens(int n) {
        vector<int> a(n);
        cnt = 0;
        helper(a, n, 0);
        return cnt;
    }
private:
    int cnt;
};
int main(){

    return 0;
}
