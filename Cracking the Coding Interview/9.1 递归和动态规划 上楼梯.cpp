#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
#include <cmath>
#include<unordered_set>  // 需要c++ 11才能支持
using namespace std;
class GoUpstairs {
public:
    int countWays(int n) {
        if(n <= 0) return 0;
        vector<int> cnt(n+1, 0);
        cnt[1] = 1, cnt[2] = 2, cnt[3] = 4;
        for(int i = 4; i <= n; ++i){
            cnt[i] = (cnt[i] + cnt[i-3])%1000000007;
            cnt[i] = (cnt[i] + cnt[i-2])%1000000007;
            cnt[i] = (cnt[i] + cnt[i-1])%1000000007;
        } return cnt[n];
    }
};
int main(){

    return 0;
}
