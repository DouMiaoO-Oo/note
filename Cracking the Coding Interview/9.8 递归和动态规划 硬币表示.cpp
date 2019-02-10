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

class Coins {
public:
    void helper(int cur, int last){
       // cout << cur << " " << last << " " << cnt << endl;
        if(cur < 0) return;
        if(cur < 5){
            cnt = (++cnt) % 1000000007;
            return;
        }
        // i 0:25 1:10 2:5 3:1
        for(int i = last; i>= 0; --i){
            helper(cur-arr[i], i);
        }
    }
    int countWays(int n) {
        cnt = 0;
        arr = vector<int>(4, 0);
        arr[0] = 1;
        arr[1] = 5;
        arr[2] = 10;
        arr[3] = 25;
        helper(n, 4);
        return cnt;
    }
    int cnt;
    vector<int> arr;
};
int main(){
    cout << Coins().countWays(6) << endl;  //  5+1 1*6
    cout << Coins().countWays(10) << endl;  // 10 5+5 5+1*5 1*10
    cout << Coins().countWays(100) << endl;
    cout << Coins().countWays(1000) << endl;
    // cout << Coins().countWays(100000) << endl;
    return 0;
}
