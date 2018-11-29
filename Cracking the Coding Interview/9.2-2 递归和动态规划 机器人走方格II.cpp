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
class Robot {
public:
    int countWays(vector<vector<int> > map, int x, int y) {
        int d = 1000000007;
        vector<vector<int> > cnt(x, vector<int>(y));
        for(int i = 0; i < x && map[i][0] == 1; ++i) cnt[i][0] = 1;
        for(int j = 0; j < y && map[0][j] == 1; ++j) cnt[0][j] = 1;
        for(int i = 1; i < x; ++i){
            for(int j = 1; j < y; ++j){
                if(map[i][j] != 1){
                    cnt[i][j] = 0;
                    continue;
                } cnt[i][j] = (cnt[i-1][j] + cnt[i][j-1]) % d;
            }
        } return cnt[x-1][y-1];
    }
};
int main(){

    return 0;
}
