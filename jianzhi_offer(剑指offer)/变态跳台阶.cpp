#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;

/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
解析： f(n) = f(1) + f(2) + ... + f(n-1) + 1
*/
class Solution {
public:
    int jumpFloorII(int n) {
        if(n <= 0) return 0;
        return pow(2, n-1);
    }
};