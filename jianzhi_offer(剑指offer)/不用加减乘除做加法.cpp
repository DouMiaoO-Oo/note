#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;
/*
位运算方法，二进制表示下，某一位a与b不同才能得到1(0+1或者1+0)，某一位a与b相同能得到0(0+0或者1+1进位)
我们再保留进位 (a&b)<<1，如果进位为0时加法完成
*/
class Solution {
public:
    int Add(int a, int b)
    {
        int t;
        while(b){
            t = a^b;
            b = (a&b)<<1;
            a = t;
        } return a;
    }
};
int main(){

    return 0;
}
