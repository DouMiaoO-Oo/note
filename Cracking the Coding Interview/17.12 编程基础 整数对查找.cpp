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
/*
数组中的数字可以相同
对于 [1,2,2] sum为 3 可以是 （1，2）,（ 1，2）
*/
class FindPair {
public:
    int countPairs(vector<int> A, int n, int sum) {
        // 数组中的数字可以相同
        unordered_map<int, int> s;
        int res = 0;
        for(int i = 0; i < n; ++i){
            // 注意可能有 A[i]*2 == sum 的情况
            int pair = sum-A[i];
            if(s.find(pair) != s.end()){
                res += s[pair];
            } ++s[A[i]];
        } return res;
    }
};
int main(){
	
    return 0;
}
