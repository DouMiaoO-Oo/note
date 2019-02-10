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
把n!分解成若干个素数相乘，只有 2*5 才可能产生尾随零，而2的数量多于5，所以问题转化为计算有多少个5
*/
class Factor {
public:
    // 通过遍历（1到n)，统计每个数能被5整除的总次数
    int getFactorSuffixZero(int n) {

        int cnt = 0;
        for(int i = 5; i <= n; i+=5){
            int t = i;
            while(t%5 == 0){
                t /= 5;
                ++cnt;
            }
        } return cnt;
    }
};
/*
先统计1到n之间有几个5的倍数（数量为n/5），
然后统计有几个25的倍数（数量为n/25），依次类推。
可知该方法会将5^k统计到k次（即分别是5, 25, ..., 5^k的倍数），而5^k恰好贡献了k个5。
*/
int getFactorSuffixZero(int n){
    int base = 5, cnt = 0;
    while(n >= base){
        cnt += n/base;
        base *= 5;
    } return cnt;
}
int main(){
    int n = 998;
    cout << Factor().getFactorSuffixZero(n) << endl;
    cout << getFactorSuffixZero(n) << endl;
    return 0;
}
