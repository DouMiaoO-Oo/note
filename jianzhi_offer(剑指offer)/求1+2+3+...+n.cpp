#include <iostream>
#include<vector>
#include <algorithm>
#include <string>

using namespace std;

/* 方法1：最短路径 */
int Sum_Solution(int n){
    int res = 0;
    res += n--;
    n && (res += Sum_Solution(n));
    return res;
}
/*
// 方法2: 实现乘法运算
class Solution {
public:
    int mul(int a, int b){
        int res = 0;
        (b&1) && (res += a);
        a <<= 1;
        b >>= 1;
        b && (res += mul(a, b));
        return res;
    }
    int Sum_Solution(int n) {
        return mul(n, n+1)>>1;
    }
};
*/
int main(){
	cout << Sum_Solution(10) << endl;
    return 0;
}
