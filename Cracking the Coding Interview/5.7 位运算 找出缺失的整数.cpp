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
/*
题目描述
数组A包含了0到n的所有整数，但其中缺失了一个。对于这个问题，我们设定限制，使得一次操作无法取得数组number里某个整数的完整内容。唯一的可用操作是询问数组中第i个元素的二进制的第j位(最低位为第0位)，该操作的时间复杂度为常数，请设计算法，在O(n)的时间内找到这个数。

给定一个数组number，即所有剩下的数按从小到大排列的二进制各位的值，如A[0][1]表示剩下的第一个数的二进制从低到高的第二位。同时给定一个int n，意义如题。请返回缺失的数。

测试样例：
[[0],[0,1]]
返回：1
*/

class Finder {
public:
    int findMissing(vector<vector<int> > numbers, int n) {
        for(int i = 0; i < n; ++i){
            if((i&1) != numbers[i][0])
                return i;
        } return n;
    }
};
int main(){

    return 0;
}
