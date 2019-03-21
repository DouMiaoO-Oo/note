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

// 本质还是最长递增子序列
struct WDH{
    int w, d, h;
    WDH(int w = 0, int d = 0, int h = 0){
        this->w = w;
        this->d = d;
        this->h = h;
    }
    bool operator < (const WDH& o) const{
        return this->w > o.w;
    }
};
class Box {
public:
    int getHeight(vector<int> w, vector<int> d, vector<int> h, int n) {
        // assert wi <= di
        if(n == 0) return 0;
        vector<WDH> v(n);
        for(int i = 0; i < n; ++i){
            v[i].w = w[i];
            v[i].d = d[i];
            v[i].h = h[i];
        } sort(v.begin(), v.end());
        vector<int> dp(n);
        dp[0] = v[0].h;
        for(int i = 1; i < n; ++i){
            int best = 0;
            for(int j = 0; j < i; ++j){
                if(v[j].w > v[i].w && v[j].d > v[i].d && dp[j] > best){
                    best = dp[j];
                }
            } dp[i] = best + v[i].h;
        } return *max_element(dp.begin(), dp.end());
    }
};

int main(){

    return 0;
}
