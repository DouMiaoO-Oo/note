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
        // assert n>=0  // 要注意全是负数的数组样例
        if(n <= 0) return 0;
        int res = A[0], sum = A[0];
        for(int i = 1; i < n; ++i){
            sum = max(sum+A[i], A[i]);
            res = max(res, sum);
        } return res;
    }
};
int main(){

    return 0;
}
