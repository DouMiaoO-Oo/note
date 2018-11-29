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
class Robot {
public:
    int factorial(int n){
        int res = 1;
        for(int i = 2; i <= n; ++i){
            res *= i;
        } return res;
    }
    int combination(int n, int k){
        // c(n, k)
        return factorial(n)/factorial(n-k)/factorial(k);
    }
    int countWays(int x, int y) {
        // 机器人所在的原点是(1, 1)
        return combination(x+y-2, x-1);
    }
};

/* // 方法二 动态规划
class Robot {
public:
    int countWays(int x, int y) {
        vector<vector<int> > cnt(x, vector<int>(y));
        for(int i = 0; i < x; ++i) cnt[i][0] = 1;
        for(int j = 0; j < y; ++j) cnt[0][j] = 1;
        for(int i = 1; i < x; ++i){
            for(int j = 1; j < y; ++j){
                cnt[i][j] = cnt[i-1][j] + cnt[i][j-1];
            }
        } return cnt[x-1][y-1];
    }
};
*/
int main(){

    return 0;
}
