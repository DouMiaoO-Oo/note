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
请编写程序交换一个数的二进制的奇数位和偶数位。（使用越少的指令越好）
给定一个int x，请返回交换后的数int。
测试样例：10
返回：5
*/

class Exchange {
public:
    int exchangeOddEven(int x) {
        int odd = x&(0x55555555);  // 32bits
        int even = x&(0xaaaaaaaa);
        return (unsigned int)(even)>>1 | (odd<<1);
    }

int exchangeOddEven2(int x) {
        // write code here
        int odd  = ((x&0x55555555)<<1);
        int even = ((x&0xAAAAAAAA)>>1)&0x7fffffff;
        return even|odd;
    }// 链接：https://www.nowcoder.com/questionTerminal/ed7d014b42e740679c4bd69b9d9c49b9
};
int main(){
    cout << Exchange().exchangeOddEven(-10) << endl;
    cout << Exchange().exchangeOddEven2(-10) << endl;
    cout << Exchange().exchangeOddEven2(0x80000000) << endl;
    cout << Exchange().exchangeOddEven(0x80000000) << endl;
    return 0;
}
