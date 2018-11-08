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
class MaxSum {
public:
    int getMaxSum(vector<int> A, int n) {
        // 要注意全是负数的数组样例
        if(n <= 0) return 0;
        int cur = A[0], ans = A[0];
        for(int i = 1; i < n; ++i){
            if(cur >= 0) cur += A[i];
            else cur = A[i];
            if(ans < cur) ans = cur;
        } return ans;
    }
};
int main(){

    return 0;
}
